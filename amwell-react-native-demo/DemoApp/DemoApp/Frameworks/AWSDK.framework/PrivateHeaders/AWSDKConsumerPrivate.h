//
//  AWSDKConsumerPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/21/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKUserPrivate.h"
#import "AWSDKVisitServicePrivate.h"

#import <AWSDK/AWSDKConsumer.h>

extern NSString *_Nonnull const ConsumerDemographicsUpdatedNotification;

@class AWSDKSubscription, AWSDKAddress, AWSDKVisitContext, AWSDKVisitFlowState;
@protocol AWSDKVisitFlowStateHolder;

/**
 A consumer or dependent of American Well's telehealth platform.

 @since 1.0.0
 */
@interface AWSDKConsumer : AWSDKUser <AWSDKConsumer>

@property (weak, nonatomic, nullable) id<AWSDKFindFirstAvailableDelegate> delegate;

@property (nonatomic, nullable) NSTimer *findFirstAvailableTimer;

@property (assign) int findFirstAvailableFailureCount;

@property (nonatomic, nullable) AWSDKVisitFlowState *visitClientState;

@property (nonatomic, readwrite, nullable) id<AWSDKSubscription> subscription;

@property (nonatomic, nullable) NSDate *lastLogin;

@property (nonatomic, nullable) NSString *consumerType;

@property (nonatomic, nullable) NSString *patientMrnID;
@property (assign, nonatomic) BOOL eligibleForVisit;
@property (assign, nonatomic) BOOL enrolled;
@property (assign, nonatomic) BOOL systemGenerated;

@property (nonatomic, nullable) AWSDKAddress *billingAddress;

@property (nonatomic, nullable) NSURL *elibilityRequestURL;
@property (nonatomic, nullable) NSTimer *pollTimer;
@property (nonatomic, readwrite, nullable) NSString *consumerAuthKey;

@property (nonatomic, nullable) NSString *memberType;

+ (nonnull NSArray<AWSDKConsumer *> *)dependentsFromArray:(nonnull NSArray<NSDictionary *> *)array withauthenticatedParent:(nonnull id<AWSDKConsumer>)authenticatedParent;

- (void)updateBillingAddress:(nonnull AWSDKAddress *)address;
- (nonnull NSString *)privateConsumerAuthKey;
- (void)startFindFirstAvailableRequestWithClientStateHolder:(nonnull id<AWSDKVisitFlowStateHolder>)stateHolder
                                                   delegate:(nonnull id<AWSDKFindFirstAvailableDelegate>)delegate
                                                 completion:(nullable GenericCompletionBlock)completion;
- (void)updateDependents:(nullable NSArray<AWSDKConsumer *> *)array;
- (void)updateAuthenticatedParent:(nullable id<AWSDKConsumer>)authenticatedParent;
- (void)fetchVisitWithParams:(nonnull NSDictionary *)params completion:(nonnull VisitCompletionBlock)completion;

/**
 Used to fetch the fully populated, detailed representation of the AWSDKDeviceIntegration. This method will obtain AWSDKExamData for each AWSDKDeviceIntegration record.

 @param integration The AWSDKDeviceIntegration object that should be fetched in detail from the telehealth platform.
 @param completion DeviceIntegrationCompletionBlock containing the detailed view of the AWSDKDeviceIntegration record provided in the first parameter.

 @since 4.3.0
 */
- (void)fetchDeviceIntegrationDetail:(nonnull id<AWSDKDeviceIntegration>)integration completion:(nonnull DeviceIntegrationCompletionBlock)completion;

/**
 Search query used to find device integration records.

 @note Use fetchDeviceIntegrationDetail:completion: in order to obtain AWSDKDeviceIntegration records that contain AWSDKExamData.

 @param request The populated request object containing the search criteria.
 @param completion DeviceIntegrationsCompletionBlock containing a list of AWSDKDeviceIntegration objects. They will not contain exam data.

 @since 4.3.0
 */
- (void)findDeviceIntegrations:(nonnull AWSDKDeviceIntegrationSearchRequest *)request completion:(nonnull DeviceIntegrationsCompletionBlock)completion;
@end
