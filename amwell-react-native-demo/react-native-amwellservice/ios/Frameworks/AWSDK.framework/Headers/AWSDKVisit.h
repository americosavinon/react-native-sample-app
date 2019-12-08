//
//  AWSDKVisit.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/16/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWCoreVisitEndReason.h>
#import <AWSDK/AWSDKCallbackStatus.h>
#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <AWSDK/AWSDKFeedbackQuestion.h>
#import <AWSDK/AWSDKVisitDisposition.h>

// clang-format off
@protocol AWSDKCost, AWSDKProvider, AWSDKConsumer, AWSDKForcedVisitTransfer, AWSDKSuggestedVisitTransfer, AWSDKVisitTransfer, AWSDKChatReport, AWSDKModality, AWSDKFeedbackQuestion, AWSDKConference;
// clang-format on

/**
 Delegate method to handle events from the callback process

 @since 3.0.0
 */
@protocol AWSDKCallbackDelegate <AWSDKDataObject>

#pragma mark - Required Delegate Methods
/**
 @name Required Delegate Methods
 */
@required

/**
 Called when the callback status is updated.

 @param status  The new AWSDKCallbackStatus.

 @since 3.0.0
 */
- (void)callbackStatusDidChange:(AWSDKCallbackStatus)status;

@end

/**
 Delegate methods to handle events from the visit.

 @since 1.0.0
 */
@protocol AWSDKVisitDelegate <NSObject>

#pragma mark - Required Delegate Methods
/**
 @name Required Delegate Methods
 */
@required

/**
 Called when the provider enters the visit and the AWSDKVisitConsoleViewController is ready to be presented.

 @since 1.0.0
 */
- (void)providerDidEnterVisit;

/**
 Called when the visit ends.

 @param visitSuccessful _TRUE_ if visit ends successfully, otherwise _FALSE_ if not successful.
 @param reason          AWCoreVisitEndReason indicating what caused the visit to end.

 @since 1.0.0
 */
- (void)visitDidComplete:(BOOL)visitSuccessful withEndReason:(AWCoreVisitEndReason)reason;

#pragma mark - Optional Delegate Methods
/**
 @name Optional Delegate Methods
 */
@optional

/**
 Called when polling for the provider to enter the visit fails.

 @discussion The visit will continue to attempt polls until the provider enters the visit or deallocation.

 @param error    NSError explaining why the polling failed.

 @since 2.0.1
 */
- (void)visitUpdateDidFail:(nonnull NSError *)error;

/**
 Called when the visit's patientsAheadOfConsumer changed value.

 @since 2.0.0
 */
- (void)patientsAheadOfConsumerDidChange;

/**
 Called when the server automatically determined another provider is available for transfer.

 @discussion The telehealth platform will suggest a transfer after a configurable amount of time has passed in the waiting room.

 @param transfer     AWSDKSuggestedVisitTransfer with information about the transfer.

 @since 2.1.0
 */
- (void)suggestedTransferDidChange:(nonnull id<AWSDKSuggestedVisitTransfer>)transfer;

/**
 Called when the chatReport contains new AWSDKChatItems since the last chatReportDidChange: callback.

 @note newChatReport contains only the new AWSDKChatItems, for access to all AWSDKChatItems for the visit, see [AWSDKVisit chatReport] .

 @param newChatReport AWSDKChatReport with only the new chat items.

 @since 2.1.0
 */
- (void)chatReportDidChange:(nonnull id<AWSDKChatReport>)newChatReport;

/**
 Called when the American Well telehealth platform enables the FirstAvailable search while waiting for a provider.

 @discussion When receiving this call, it is recommended that you present the user with an option to search for more readily available providers. If no action is taken in response to this delegate
 call, the consumer's visit experience will be unaffected.

 @note This will be called a maximum of 1 time during the lifetime of a visit. The property didSuggestBeginFirstAvailableTransfer will reflect this.

 @since 4.1.0
 */
- (void)visitDidSuggestFirstAvailableSearch;

@end

/**
 A telehealth visit between an AWSDKConsumer and an AWSDKProvider.

 @since 3.1.1
 */
@protocol AWSDKVisit
#pragma mark Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKProvider representing the selected Provider for the visit.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProvider> provider;

/**
 AWSDKConsumer representing the person for whom the visit is for. This can be either the account owner or a dependent.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> consumer;

/**
 AWSDKConsumer representing the parent of the dependent visit, otherwise _nil_ if not a dependent visit.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKConsumer> consumerProxy;

/**
 AWCoreVisitEndReason representing the reason why the visit ended.

 @since 1.0.0
 */
@property (nonatomic, assign, readonly) AWCoreVisitEndReason endReason;

/**
 AWSDKVisitDisposition describing the state of the AWSDKVisit

 @since 4.2.0
 */
@property (nonatomic, readonly) AWSDKVisitDisposition disposition;

/**
 AWSDKCallbackStatus representing the current status of the callback.

 @since 3.0.0
 */
@property (nonatomic, assign, readonly) AWSDKCallbackStatus callbackStatus;

/**
 NSString representing the override unformatted phone number added during intake.

 @since 3.0.0
 */
@property (nonatomic, readonly, nullable) NSString *overridePhoneNumber;

/**
 NSString representing the override formatted phone number added during intake.

 @since 4.2.0
 */
@property (nonatomic, readonly, nullable) NSString *overrideFormattedPhoneNumber;

/**
 AWSDKCost representing the cost of the visit that will be charged to the consumer's payment method.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKCost> cost;

/**
 AWSDKChatReport representing the entire pre-visit chat, otherwise _nil_ if no chat conversation exists.

 @discussion chatReport AWSDKChatReport is populated when pre-visit chat starts between a consumer and an assistant. chatReport always contains all AWSDKChatItem items from the entire visit. The
 delegate method [AWSDKVisitDelegate chatReportDidChange:] is called when the chatReport receives new AWSDKChatItem items.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKChatReport> chatReport;

/**
 NSInteger representing the number of patients currently waiting for the provider who entered the waiting room earlier than the consumer.

 @discussion Initially set to -1. Implement [AWSDKVisitDelegate patientsAheadOfConsumerDidChange] to handle changes.

 @note This does not guarantee the order in which patients are seen, that is determined by the provider.

 @since 2.0.0
 */
@property (nonatomic, assign, readonly) NSInteger patientsAheadOfConsumer;

/**
 BOOL set _TRUE_ if a payment method is required on this visit for validation purposes, otherwise _FALSE_ if not required.

 @note If set _TRUE_, a payment method will be required even if the visit has no cost associated with it.

 @since 1.0.0
 */
@property (readonly) BOOL paymentMethodRequired DEPRECATED_MSG_ATTRIBUTE("Deprecated as of 5.2.0, use !visit.cost.isFree");

/**
 BOOL set _TRUE_ if the visit was generated via the first-available workflow

 @since 4.1.0
 */
@property (readonly) BOOL createdForFirstAvailableFlow;

/**
 AWSDKModality representing the mode of communication for the visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKModality> modality;

#pragma mark Transfer Read-Only Properties
/**
 @name Transfer Read-Only Properties
 */

/**
 AWSDKForcedVisitTransfer populated if the provider declines, ends the visit and suggests a transfer, otherwise _nil_ if a transfer does not exist or is no longer available.

 @discussion To receive the event when forcedTransfer is populated, handle the AWCoreVisitEndReasonVisitTransferred from [AWSDKVisitDelegate visitDidComplete:withEndReason:].

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKForcedVisitTransfer> forcedTransfer;

/**
 AWSDKSuggestedVisitTransfer populated if the server automatically suggests a new transfer, otherwise _nil_ if a transfer does not exist or is no longer available.

 @discussion To receive the event implement the [AWSDKVisitDelegate suggestedTransferDidChange:] delegate method.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKSuggestedVisitTransfer> suggestedTransfer;

/**
 Describes if the option to begin a First Available search for another provider while in the waiting room of the current provider has become available.

 @note Defaults to _FALSE_. If the American Well telehealth platform is configured to suggest this feature, this flag will be set to _TRUE_ after the configured amount of time has passed
 in the waiting room.

 @discussion When this flag is first set to true, you should present the consumer with the option to begin the search for another provider that may be immediately available in order to reduce their
 total wait time. Their place in line with the current provider will remain unaffected up until the moment a First Available provider accepts their visit.

 @since 4.1.0
 */
@property (nonatomic, readonly) BOOL didSuggestBeginFirstAvailableTransfer;

/**
 Describes if the consumer has accepted the option to begin searching for a provider through the First Available network.

 @note Defaults to _FALSE_. If the consumer has accepted the option to begin a First Available search, the value will be set to _TRUE_.

 @since 4.1.0
 */
@property (nonatomic, readonly) BOOL consumerAcceptedFirstAvailableTransferSearch;

/**
 NSString representing the visit source id.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *sourceId;

/**
 AWSDKFeedbackQuestion for the consumer to respond to.

 @discussion To select a response, set [AWSDKFeedbackQuestion selectedOption];

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKFeedbackQuestion> consumerFeedbackQuestion;

/**
 Contains a list of email addresses representing the guests invited to the visit by the consumer.

 @discussion Can be used to prevent duplicate guests invites.

 @since 5.0.0
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *invitedGuestEmails;

#pragma mark - Required Read-Write Properties
/**
 @name Required Read-Write Properties
 */

/**
 Visit delegate that will receive messages about visit events.

 @note This is required to be set by a receiver object.

 @since 1.0.0
 */
@property (weak, nonatomic, nullable) NSObject<AWSDKVisitDelegate> *delegate;

/**
 Callback delegate that will receive status updates.

 @note This is required to be set to receive callback events.

 @since 3.0.0
 */
@property (weak, nonatomic, nullable) NSObject<AWSDKCallbackDelegate> *callbackDelegate;

#pragma mark - Visit Methods
/**
 @name Visit Methods
 */

/**
 Fetches the AWSDKVisitSummary for the visit.

 @note This summary is only available if the visit has ended and ended successfully.

 @param completion VisitSummaryCompletionBlock containing the associated AWSDKVisitSummary,  otherwise an NSError with any applicable error cases.

 Potential Error Codes
 @exception AWSDKErrorCodeWrapUpUnavailable Indicates wrap-up cannot be downloaded.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionProviderWrapUp, AWSDKVisitDispositionCompleted and AWSDKVisitDispositionExpired

 @since 1.0.0
 */
- (void)fetchVisitSummary:(nullable VisitSummaryCompletionBlock)completion;

/**
 Applies a coupon code to the cost of the visit.

 @note Only one coupon code may be applied per visit, and once a coupon code has been applied another one cannot be used.

 @param code        NSString representing the coupon code to apply.
 @param completion  GenericCompletionBlock containing _TRUE_ if the coupon was applied successfully, otherwise _FALSE_ and an NSError indicating any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationInvalidCoupon   Invalid coupon code entered.
 @exception AWSDKErrorCodeCouponCodeAlreadyInUse    A coupon code has already been applied for this visit.

 @since 1.0.0
 */
- (void)applyCouponCode:(nonnull NSString *)code withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Begins the search for a provider via the First Available flow.

 @note If didSuggestBeginFirstAvailableTransfer is not set to _TRUE_, this method is a no-op. The American Well telehealth platform must dictate that the feature is enabled before attempting to begin
 the search for a new provider. If this method completes successfully, consumerAcceptedFirstAvailableTransferSearch will be set to _TRUE_.

 @param completion GenericCompletionBlock detailing whether or not the operation completed successfully.

 Potential Error Codes
 @exception AWSDKErrorCodeUnavailable       The feature is not yet available to the user.

 @note Valid dispositions for visit: AWSDKVisitDispositionPreVisit
 
 @since 4.1.0
 */
- (void)beginFirstAvailableTransferSearch:(nullable GenericCompletionBlock)completion;

/**
 Declines the offer to begin the search for a provider via the First Available flow.

 @note If didSuggestBeginFirstAvailableTransfer is not set to _TRUE_, this method is a no-op. The American Well telehealth platform must dictate that the feature is enabled before attempting to begin
 the search for a new provider. If this method completes successfully, consumerAcceptedFirstAvailableTransferSearch will be set to _FALSE_.

 @param dontAsk BOOL indicating if the American Well telehealth platform may offer to search again after a configurable time interval.
 @param completion GenericCompletionBlock detailing whether or not the operation completed successfully.

 Potential Error Codes
 @exception AWSDKErrorCodeUnavailable       The feature is not yet available to the user.

 @note Valid dispositions for visit: AWSDKVisitDispositionPreVisit

 @since 4.1.0
 */
- (void)declineFirstAvailableTransferSearch:(BOOL)dontAsk completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Chat Report Methods
/**
 @name Chat Report Methods
 */

/**
 Sends a pre-visit chat message from the consumer.

 @discussion Updates are reflected in the chatReport object. Sending and receiving messages can only start when chatReport is populated and contains AWSDKChatItem items. [AWSDKVisitDelegate
 chatReportDidChange:] is called if new chat items return whether or not a completion block exists.

 @param message     NSString message to send to the provider or assistant.
 @param completion  ChatReportCompletionBlock containing an AWSDKChatReport object with only the new chat items since the message was sent, otherwise an NSError explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeChatUnavailable    The pre-visit chat has not started yet with the assistant.

 @note Valid dispositions for visit: AWSDKVisitDispositionPreVisit, AWSDKVisitDispositionInVisit and AWSDKVisitDispositionPostVisit
 
 @since 2.1.0
 */
- (void)sendPreVisitChatMessage:(nonnull NSString *)message withCompletion:(nonnull ChatReportCompletionBlock)completion;

/**
 Updates the visit object with the most up-to-date information. This method is intended to be used during background polling if your application has a background fetch entitlement.

 @discussion Use of this method is not required for any workflow. It is provided as a hook for your application to update state in the background if a user sends the application to the
 background while they are waiting for the provider to join the visit.

 @note The minimum interval for background fetching enforced by iOS tends to be anywhere from 10 to 30 minutes, so this may or may not be helpful in your workflow.

 @param completion GenericCompletionBlock containing a BOOL detailing the success of the network call and an optional Error

 @since 4.0.0
 */
- (void)fetchUpdatedStateWithCompletion:(nonnull GenericCompletionBlock)completion;

#pragma mark - Setup SMS Methods
/**
 @name Setup SMS Messaging Methods
 */

/**
 Setup SMS messaging to the consumer for the following (2) conditions:
    1) the provider has entered the waiting room
    2) the consumer position has moved up in the queue

 @discussion The telehealth platform will send an SMS message to the specified mobile number.

 @param phoneNumber         NSString phoneNumber is the destination of the message, if NULL, the callback phone number specified during the intake will be used.
 @param providerReadyAlert  BOOL providerReadyAlert specifies to send an alert when the provider enters the waiting room.
 @param movedUpInQueueAlert BOOL movedUpInQueueAlert specifies to send an alert when the consumer's position in the queue has been updated.
 @param completion          GenericCompletionBlock to be executed on completion.

 @note Valid dispositions for visit: AWSDKVisitDispositionPreVisit
 
 @since 4.0.0
 */
- (void)setupMemberTextToNumber:(nullable NSString *)phoneNumber
             providerReadyAlert:(BOOL)providerReadyAlert
            movedUpInQueueAlert:(BOOL)movedUpInQueueAlert
                     completion:(nullable GenericCompletionBlock)completion;

/**
 @discussion Submits the feedback question.

 @param feedbackQuestion    The feedbackQuestion with the selected responseOption.
 @param completion          GenericCompletionBlock to be executed on completion.
 
 @note Valid dispositions for visit: Any disposition

 @since 4.3.0
 */
- (void)submitFeedbackQuestion:(nonnull id<AWSDKFeedbackQuestion>)feedbackQuestion completion:(nullable GenericCompletionBlock)completion;

@end
