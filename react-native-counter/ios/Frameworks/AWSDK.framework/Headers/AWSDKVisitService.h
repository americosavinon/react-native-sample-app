//
//  AWSDKVisitService.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/27/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKVisit, AWSDKVisitContext, AWSDKProvider;
@class AWSDKConsumerOverrides, AWSDKAppearanceManager;
// clang-format on

/**
 Delegate protocol for Find First Available visits.

 @discussion When submitting a Find First Available request you must specify an AWSDKFindFirstAvailableDelegate object. This object will handle updates to the Find First Available visit status in an
 asynchronous maner.

 @since 1.0.0
 */
@protocol AWSDKFindFirstAvailableDelegate <NSObject>

/**
 Called when a provider was found for the consumer and that matchmaking service has completed.

 @discussion After the provider accepts, the consumer will have a configurable time limit to start the visit. By default this is 240 seconds. If the startVisit:completion: is called after the time
 limit, AWSDKErrorCodeFindFirstAvailableNoTicketAvailable is sent.

 @since 2.1.0
 */
- (void)providerFound;

/**
 Called when the provider list has been exhausted and no provider has accepted the visit.

 @since 1.0.0
 */
- (void)providerListExhausted;

/**
 Called when a failure occurred on the Find First Available request and the request has been canceled.

 @param error NSError explaining any failures.

 @since 1.0.0
 */
- (void)findFirstAvailableFailedWithError:(nullable NSError *)error;

@end

/**
 Manages visit context validation, creating visits, starting visits, and creating the video console view controller.

 @since 3.0.0
 */
@protocol AWSDKVisitService <AWSDKDataObject>

#pragma mark - Validation Methods
/**
 @name Validation Methods
 */

/**
 Validates an instance of AWSDKVisitContext for submission.

 @discussion This method is also called by createVisitWithContext:completion: but is available separately for client validation before submission.

 @param visit AWSDKVisitContext to verify
 @param cartMode BOOL describing if the AWSDKVisitContext is going to be used to create a "cart mode" visit
 @param error Provide an NSError for validation to populate if there are any errors. If validation errors are present the error's code will be (AWSDKErrorCodeInvalidVisitContext), and the userInfo
 property will have a dictionary value under the key "AWSDKValidationErrors". The ValidationErrors dictionary will use property names as keys, and an AWSDKErrorCode wrapped in an NSNumber as an int as
 the value. If a property validated sucessfully it will not be in the ValidationErrors dictionary and the error will be set to _nil_.

 @return _TRUE_ if valid, otherwise _FALSE_ and error will be populated explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                   Visit context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.
 @exception AWSDKErrorCodePrivacyDisclaimerMissing              Required disclaimer is not accepted.

 @since 4.3.0
 */
+ (BOOL)isVisitContextValid:(nonnull id<AWSDKVisitContext>)visit cartMode:(BOOL)cartMode error:(NSError *__nullable *__nullable)error;

/**
 Validates an instance of AWSDKVisit before starting the visit.

 @discussion Also validates payment information. This method is also called by startVisit:completion: , but is available separately for client validation before submission.

 @param visit      AWSDKVisit to verify.
 @param completion GenericCompletionBlock containing _TRUE_ if valid, otherwise _FALSE_ and an NSError explaining any validation errors. If validation errors are present the error's code will be
 (AWSDKErrorCodeInvalidVisitContext), and the userInfo property will have a dictionary value under the key "AWSDKValidationErrors". The ValidationErrors dictionary will use property names as keys, and
 an AWSDKErrorCode wrapped in an NSNumber as an int as the value. If a property validated sucessfully it will not be in the ValidationErrors dictionary.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                   Visit context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.

 @since 3.0.0
 */
+ (void)readyToStartVisit:(nonnull id<AWSDKVisit>)visit completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Create Visit Methods
/**
 @name Create Visit Methods
 */

/**
 Creates an instance of AWSDKVisit given an AWSDKVisitContext and prepares for the visit on the American Well telehealth platform.

 @discussion Calling this method will first run the isVisitContextValid:error: method. If there are any validation errors it will return an NSError in the VisitCompletionBlock with an identical
 format as what would be expected from the validation call.

 @param visitContext AWSDKVisitContext used to create the visit containing all information from intake.
 @param completion   VisitCompletionBlock containing the AWSDKVisit instance if successful, otherwise an NSError explaining any issues.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                           Visit context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.
 @exception AWSDKErrorCodePrivacyDisclaimerMissing                      Required disclaimer is not accepted.
 @exception AWSDKErrorCodeProviderOffline                               Provider is unavailable.

 Successful Eligibility Exception Cases
 @exception AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo           The consumer's subscription was flagged as invalid by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.
 @exception AWSDKErrorCodeValidationEligibilityException                       The consumer's subscription couldn't be validated by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.


 @since 3.0.0
 */
+ (void)createVisitWithContext:(nonnull id<AWSDKVisitContext>)visitContext completion:(nonnull VisitCompletionBlock)completion;

/**
 Creates an instance of AWSDKVisit given an AWSDKVisitContext and AWSDKConsumerOverrides and prepares for the visit on the American Well telehealth platform.

 @note This method is intended for use with a cart-based visit. The provided AWSDKConsumerOverrides will override any demographic information associated with the provided AWSDKVisitContext

 @discussion Calling this method will first run the isVisitContextValid:error: method. If there are any validation errors it will return an NSError in the VisitCompletionBlock with an identical
 format as what would be expected from the validation call.

 @param visitContext AWSDKVisitContext used to create the visit containing all information from intake.
 @param consumerOverrides AWSDKConsumerOverrides used to override the demographic information of the consumer receiving care
 @param quickConnect  BOOL representing if this visit is being used in the Quick Connect flow.
 @param visitSourceId    NSString representing the desired sourceId associated with the resulting visit
 @param completion   VisitCompletionBlock containing the AWSDKVisit instance if successful, otherwise an NSError explaining any issues.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                           Visit context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.
 @exception AWSDKErrorCodePrivacyDisclaimerMissing                      Required disclaimer is not accepted.
 @exception AWSDKErrorCodeProviderOffline                               Provider is unavailable.

 Successful Eligibility Exception Cases
 @exception AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo           The consumer's subscription was flagged as invalid by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.
 @exception AWSDKErrorCodeValidationEligibilityException                       The consumer's subscription couldn't be validated by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.


 @since 4.2.2
 */
+ (void)createVisitWithContext:(nonnull id<AWSDKVisitContext>)visitContext
             consumerOverrides:(nullable AWSDKConsumerOverrides *)consumerOverrides
                isQuickConnect:(BOOL)quickConnect
                 visitSourceId:(nullable NSString *)visitSourceId
                    completion:(nonnull VisitCompletionBlock)completion;

/**
 Creates an instance of AWSDKVisit given an AWSDKSpeedPass and prepares for the visit on the American Well telehealth platform.

 @param speedPass AWSDKSpeedPass used to create the visit containing all information from the previous visit.
 @param completion  VisitCompletionBlock containing the AWSDKVisit instance if successful, otherwise an NSError explaining any issues.

 Successful Eligibility Exception Cases
 @exception AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo           The consumer's subscription was flagged as invalid by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.
 @exception AWSDKErrorCodeValidationEligibilityException                       The consumer's subscription couldn't be validated by the insurance provider. The consumer can decide to proceed but will
 have a cost without their subscription information applied.

 @since 4.1.0
 */
+ (void)createVisitWithSpeedPass:(nonnull id<AWSDKSpeedPass>)speedPass completion:(nonnull VisitCompletionBlock)completion;

#pragma mark - Find First Available Methods
/**
 @name Find First Available Methods
 */

/**
 Starts the Find First Available request with the given visit context to search for the first available provider.

 @param visitContext AWSDKVisitContext representing the context containing the 'On Demand Specialty' to use for the Find First Available search.
 @param delegate     Delegate receiver object to send Find First Available callback messages to.
 @param completion   GenericCompletionBlock containing _TRUE_ if the Find First Available request successfully started polling for provider search, otherwise _FALSE_ and an NSError explaining what
 went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.
 @exception AWSDKErrorCodeFindFirstAvailableAlreadyActive               Consumer is already active in another Find First Available request.

 @since 3.0.0
 */
+ (void)startFindFirstAvailableServiceWithContext:(nonnull id<AWSDKVisitContext>)visitContext
                                         delegate:(nonnull id<AWSDKFindFirstAvailableDelegate>)delegate
                                       completion:(nullable GenericCompletionBlock)completion;

/**
 Starts the Find First Available request with the given visit context to search for the first available provider.

 @param visit AWSDKVisit containing the context containing the 'On Demand Specialty' to use for the Find First Available search.
 @param delegate     Delegate receiver object to send Find First Available callback messages to.
 @param completion   GenericCompletionBlock containing _TRUE_ if the Find First Available request successfully started polling for provider search, otherwise _FALSE_ and an NSError explaining what
 went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.
 @exception AWSDKErrorCodeFindFirstAvailableAlreadyActive               Consumer is already active in another Find First Available request.

 @since 4.1.0
 */
+ (void)startFindFirstAvailableServiceWithVisit:(nonnull id<AWSDKVisit>)visit
                                       delegate:(nonnull id<AWSDKFindFirstAvailableDelegate>)delegate
                                     completion:(nullable GenericCompletionBlock)completion NS_SWIFT_NAME(startFindFirstAvailableServiceWithVisit(visit:delegate:completion:));

#pragma mark - Start Visit Methods
/**
 @name Start Visit Methods
 */

/**
 Starts waiting for the visit and places the consumer in the provider's waiting room where the provider can accept or decline the visit.

 @param visit      AWSDKVisit to start.
 @param completion GenericCompletionBlock containing _TRUE_ if the consumer successfully started waiting for the provider, otherwise _FALSE_ and an NSError explaining why it failed.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                   Visit Context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.
 @exception AWSDKErrorCodeFindFirstAvailableTicketExpired       The findFirstAvailable ticket has expired.

 @since 3.0.0
 */
+ (void)startVisit:(nonnull id<AWSDKVisit>)visit completion:(nullable GenericCompletionBlock)completion;

/**
 Starts waiting for the visit with the specified provider and places the consumer in the provider's waiting room where the provider can accept or decline the visit. This method is intended to be used
 in the first available workflow, since the provider returned in the [AWSDKVisitContext createVisitContextForConsumer:specialty:completion:] will not necessarily be the provider that the visit will be
 with.

 @discussion In order to properly leverage the AWSDKProvider, practices that use the First Available functionality should check that all of the providers (matching the criteria of the First Available
 feature) have uniform pricing. The First Available feature should only be enabled if the patient’s copay responsibility for the visit will be identical for a visit with any provider associated with
 the First Available feature.

 @param visit      AWSDKVisit to start.
 @param provider   AWSDKProvider to begin the visit with
 @param completion GenericCompletionBlock containing _TRUE_ if the consumer successfully started waiting for the provider, otherwise _FALSE_ and an NSError explaining why it failed.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidVisitContext                   Visit Context is invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                          Invalid required parameter.
 @exception AWSDKErrorCodeFindFirstAvailableTicketExpired       The findFirstAvailable ticket has expired.

 @since 3.2.0
 */
+ (void)startVisit:(nonnull id<AWSDKVisit>)visit withProvider:(nonnull id<AWSDKProvider>)provider completion:(nullable GenericCompletionBlock)completion;

/**
 Rejoins active visit by placing the consumer back in to the provider's waiting room or reconnecting to an in-progress visit.

 @discussion If the visit returned by AWSDKConsumer's fetchActiveVisit:completion: has a disposition of AWSDKVisitDispositionPreVisit, rejoining the visit will place the consumer in the provider's waiting room.  If the active visit's disposition is AWSDKVisitDispositionInVisit, [AWSDKVisitDelegate providerDidEnterVisit] will be called on the visit's delegate shortly after rejoining the visit.

 @param visit      AWSDKVisit to rejoin.
 @param completion GenericCompletionBlock containing _TRUE_ if the consumer successfully rejoined the visit, otherwise _FALSE_ and an NSError explaining why it failed.

 Potential Error Codes
 @exception AWSDKErrorCodeVisitAlreadyStarted                   The AWSDKVisit has already been started or rejoined.

 @since 5.2.0
 */
+ (void)rejoinVisit:(nonnull id<AWSDKVisit>)visit completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Cancel/End Visit Methods
/**
 @name Cancel/End Visit Methods
 */

/**
 Cancels the visit. Only valid before the provider has accepted or declined the visit.

 @param visit      AWSDKVisit to cancel.
 @param completion GenericCompletionBlock containing _TRUE_ if the visit was successfully cancelled, otherwise _FALSE_ and an NSError explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeCannotCancelVisit  Cannot cancel visit in current state.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionUnpublished, AWSDKVisitDispositionUnscheduled, AWSDKVisitDispositionScheduled, AWSDKVisitDispositionParked, AWSDKVisitDispositionPreVisit and AWSDKVisitDispositionInVisit

 @since 3.0.0
 */
+ (void)cancelPendingVisit:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Ends the visit. Only valid when the visit is in progress.

 @param visit      AWSDKVisit to end.
 @param completion GenericCompletionBlock containing _TRUE_ if the visit was successfully ended, otherwise _FALSE_ and an NSError explaining any failures.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionInVisit
 
 @since 5.2.0
 */
+ (void)endActiveVisit:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;

#pragma mark - Visit Console Methods
/**
 @name - Visit Console Methods
 */

/**
 Generates an AWCoreVisitConsoleController to be presented to the user for the video conference between the consumer and the provider.

 @note This controller should be presented modally and should be dismissed in the [AWSDKVisitDelegate visitDidComplete:withEndReason:] method.
 @param visit      AWSDKVisit containing the information for the visit.
 @param completion VisitConsoleCompletionBlock containing an AWCoreVisitConsoleController to present modally otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)createVisitConsoleForVisit:(nonnull id<AWSDKVisit>)visit withCompletion:(nonnull VisitConsoleCompletionBlock)completion;

/**
 Generates an AWCoreVisitConsoleController to be presented to the user for the video conference between the consumer and the provider.

 @note This controller should be presented modally and should be dismissed in the [AWSDKVisitDelegate visitDidComplete:withEndReason:] method.

 @param visit      AWSDKVisit containing the information for the visit.
 @param appearanceManager   AWSDKAppearanceManager containing the appearance overrides for the visit console.
 @param completion VisitConsoleCompletionBlock containing an AWCoreVisitConsoleController to present modally otherwise an NSError explaining any failures.

 @since 5.0.0
 */
+ (void)createVisitConsoleForVisit:(nonnull id<AWSDKVisit>)visit
             withAppearanceManager:(nullable AWSDKAppearanceManager *)appearanceManager
                    withCompletion:(nonnull VisitConsoleCompletionBlock)completion;

#pragma mark - Callback Methods
/**
 @name - Callback Methods
 */

/**
 Makes another attempt at an callback if it failed for any reason.

 @discussion The callback may fail for any of the following reasons

 - AWSDKCallbackStatusProviderUnreachable
 - AWSDKCallbackStatusConsumerUnreachable
 - AWSDKCallbackStatusTimeout
 - AWSDKCallbackStatusUnknown

 @param visit       AWSDKVisit object containing information for the visit.
 @param completion  GenericCompletionBlock containing _TRUE_ if the callback was successfully started, otherwise _FALSE_ and an NSError explaining what went wrong.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionInVisit, AWSDKVisitDispositionPostVisit, AWSDKVisitDispositionProviderWrapUp, AWSDKVisitDispositionCompleted
 and AWSDKVisitDispositionExpired

 @since 3.0.0
 */
+ (void)retryCallback:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Stop the callback request and associated status updates.

 @discussion Stopping the callback flow will clean up any running tasks.

 @param visit       AWSDKVisit object containing information for the visit.
 @param completion  GenericCompletionBlock containing _TRUE_ if the callback was successfully stopped, otherwise _FALSE_ and an NSError explaining what went wrong.

 @note Valid dispositions for visit: AWSDKVisitDispositionInVisit, AWSDKVisitDispositionPostVisit, AWSDKVisitDispositionProviderWrapUp, AWSDKVisitDispositionCompleted
 and AWSDKVisitDispositionExpired

 @since 3.0.0
 */
+ (void)endCallback:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;

@end

/**
 Manages visit context validation, creating visits, starting visits, and creating the video console view controller.

 @since 3.0.0
 */
@interface AWSDKVisitService : AWSDKDataObject <AWSDKVisitService>
#pragma mark - Appledoc
+ (BOOL)isVisitContextValid:(nonnull id<AWSDKVisitContext>)visit cartMode:(BOOL)cartMode error:(NSError *__nullable *__nullable)error;
+ (void)readyToStartVisit:(nonnull id<AWSDKVisit>)visit completion:(nullable GenericCompletionBlock)completion;
+ (void)createVisitWithContext:(nonnull id<AWSDKVisitContext>)visitContext completion:(nonnull VisitCompletionBlock)completion;
+ (void)startFindFirstAvailableServiceWithContext:(nonnull id<AWSDKVisitContext>)visitContext
                                         delegate:(nonnull id<AWSDKFindFirstAvailableDelegate>)delegate
                                       completion:(nullable GenericCompletionBlock)completion;
+ (void)startVisit:(nonnull id<AWSDKVisit>)visit completion:(nullable GenericCompletionBlock)completion;
+ (void)cancelPendingVisit:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;
+ (void)createVisitConsoleForVisit:(nonnull id<AWSDKVisit>)visit withCompletion:(nonnull VisitConsoleCompletionBlock)completion;
+ (void)createVisitConsoleForVisit:(nonnull id<AWSDKVisit>)visit
             withAppearanceManager:(nullable AWSDKAppearanceManager *)appearanceManager
                    withCompletion:(nonnull VisitConsoleCompletionBlock)completion;
+ (void)retryCallback:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;
+ (void)endCallback:(nonnull id<AWSDKVisit>)visit withCompletion:(nullable GenericCompletionBlock)completion;
#pragma mark -
@end
