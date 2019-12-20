//
//  AWSDKVisitPrivate.h
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

#import "AWSDKChatReportPrivate.h"
#import "AWSDKCostPrivate.h"
#import "AWSDKDataObjectPrivate.h"
#import "AWSDKForcedVisitTransferPrivate.h"
#import "AWSDKSuggestedVisitTransferPrivate.h"
#import "AWSDKVisitExtensionPrivate.h"
#import "AWSDKVisitFlowStatePrivate.h"

#import <AWCoreSDK/AWCoreConsumerVisitProtocol.h>
#import <AWCoreSDK/AWCoreVidyoAccountInfo.h>
#import <AWCoreSDK/AWCoreVisitEndReason.h>
#import <AWSDK/AWSDKVisit.h>
#import <AWSDK/AWSDKVisitDisposition.h>

@class AWSDKVisitExtension, AWSDKVisitConsoleViewController, AWCoreVidyoAccountInfo, AWSDKVisitContext, AWSDKConsumer, AWSDKProvider, AWSDKVisitFlowState, AWSDKChatReport, AWSDKCost, AWSDKConference,
    AWCoreVisitPollingDelegate, AWSDKVideoMetrics;

@protocol AWSDKVisitPollingDelegate <NSObject>
- (void)visitDidUpdate;
- (void)visitUpdateFailed;
@end

/**
 A telehealth visit between an AWSDKConsumer and an AWSDKProvider.

 @since 1.0.0
 */
@interface AWSDKVisit : AWSDKDataObject <AWSDKVisit, AWSDKVisitFlowStateHolder, AWCoreConsumerVisitProtocol>

@property (nonatomic, readwrite, nonnull) AWSDKCost *cost;

@property (nonatomic, nonnull) NSString *videoPortal;

@property (nonatomic, nullable) NSString *providerConnectionType;

@property (nonatomic) AWSDKVisitDisposition disposition;

@property (nonatomic, nonnull) AWSDKVisitExtension *paidExtension;

@property (nonatomic) NSInteger videoInvitesSent;

@property (nonatomic, nonnull) AWSDKProvider *provider;

/**
 Populated if the provider ends the visit and suggests a transfer, otherwise nil if a transfer is not or no longer available.
 To receive the event when forcedTransfer is populated, handle the AWCoreVisitEndReasonVisitTransferred from [AWSDKVisit visitDidComplete:]
 *
 @since 2.1.0
 */
@property (nonatomic, readwrite, nullable) AWSDKForcedVisitTransfer *forcedTransfer;

/**
 Populated if the server automatically suggests a new transfer, otherwise nil if a transfer is not or no longer available.
 To receive the event implement the [AWSDKVisitDelegate transferSuggested:] delegate method.
 *
 @since 2.1.0
 */
@property (nonatomic, readwrite, nullable) AWSDKSuggestedVisitTransfer *suggestedTransfer;

/**
 AWSDKConference representing a meeting space between 2 or more participants.

 @since 5.0.0
 */
@property (nonatomic, readwrite, nonnull) AWSDKConference *conference;

@property BOOL visitStarted;

@property (nonatomic) BOOL paidExtensionsOffered;

@property (nonatomic) BOOL shouldShowEndingAlert;

@property (nonatomic) BOOL providerSuggestedEnd;

@property (nonatomic) BOOL shouldHideTimer;

@property (nonatomic) BOOL readyToJoin;

@property (nonatomic) BOOL hasJoinedVisit;

@property (nonatomic) BOOL requireResidencyCheck;

/**
 Sent the transfer request already
 */
@property BOOL hasSentTransferRequest;

/**
 Is in the process of transfering
 */
@property BOOL isTransfering;

@property (nonatomic, readwrite) BOOL didSuggestBeginFirstAvailableTransfer;

@property (nonatomic, readwrite) BOOL consumerAcceptedFirstAvailableTransferSearch;

@property (nonatomic, nullable) AWSDKVisitFlowState *visitClientState;

/**
 Bool value determining whether or not the consumer has successfully joined the visit
 */
@property BOOL initiatorConnected;

/**
 Bool value determining whether or not the provider has successfully joined the visit
 */
@property BOOL providerConnected;
@property (nonatomic) NSInteger previousWaitingRoomCount;
@property (nonatomic, assign, readwrite) NSInteger patientsAheadOfConsumer;

/**
 Bool value indicating whether or not the visit has been completed
 */
@property BOOL finished;

@property (nonatomic) NSInteger minRemaining;

@property (nonatomic) NSInteger millisecondsRemaining;

@property (nonatomic, readonly) BOOL isPolling;
@property (weak, nonatomic, nullable) id<AWCoreVisitPollingDelegate> pollingDelegate;

@property (nonatomic, nullable) AWCoreVidyoAccountInfo *accountInfo;

@property (nonatomic, readwrite, nullable) id<AWSDKChatReport> chatReport;

- (void)updateConsumer:(nonnull AWSDKConsumer *)consumer proxy:(nullable AWSDKConsumer *)proxy;

- (void)inviteGuest:(nonnull NSString *)email completion:(nullable GenericCompletionBlock)completion;

- (void)inviteGuests:(nonnull NSArray<NSString *> *)emails completion:(nullable GenericCompletionBlock)completion;

- (void)acceptExtension:(BOOL)accepted completion:(nullable GenericCompletionBlock)completion;

- (void)updateVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)updateEndReason:(AWCoreVisitEndReason)endReason;

- (void)startVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)privateCancelVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)handleVideoFailure:(nullable GenericCompletionBlock)completion;

- (void)declineSuggestedEndWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)declineTransfer:(BOOL)dontAskAgain completion:(nullable GenericCompletionBlock)completion;

- (void)endVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)loadCostWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)visitEnded;

- (void)stopPolling;
- (void)startPolling;
- (void)processVisitState;
- (void)cancelVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)makeCallback:(BOOL)isRetry WithCompletion:(nullable GenericCompletionBlock)completion;
- (void)joinVisitWith:(NSUUID *_Nullable)uuid completion:(nullable GenericCompletionBlock)completion;
- (void)updateVideoMetrics:(AWSDKVideoMetrics *_Nonnull)metrics completion:(nullable GenericCompletionBlock)completion;
+ (AWCoreVisitEndReason)reasonForString:(nonnull NSString *)reasonString;

#pragma mark - Callback Methods
/**
 Returns an AWSDKCallbackStatus status matched to the given string

 @param callbackStatusString An NSString representation of the callback status retrieved from the server.

 @since 3.0.0
 */
+ (AWSDKCallbackStatus)callbackStatusForString:(nonnull NSString *)callbackStatusString;

/**
 Ends the callback.

 @param completion   GenericCompletionBlock containing _TRUE_ if the callback was successfully ended, otherwise _FALSE_ and an NSError explaining what went wrong.

 @since 3.0.0
 */
- (void)endCallback:(nullable GenericCompletionBlock)completion;

/**
 Retry the callback.

 @param completion   GenericCompletionBlock containing _TRUE_ if the callback successfully started, otherwise _FALSE_ and an NSError explaining what went wrong.

 @since 3.0.0
 */
- (void)retryCallback:(nullable GenericCompletionBlock)completion;

@end
