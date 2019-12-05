//
//  AWSDKVisitClientState.h
//  AWSDK
//
//  Created by Stephen Ciauri on 5/17/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWSDKProvider;
@class AWSDKOnDemandSpecialty;

/**
 The purpose of this class is to track client-side state of any visit flow since some state can/should not be gleaned by the state on the American Well telehealth platform.
 */
@interface AWSDKVisitFlowState : NSObject
@property (nonatomic, nullable) AWSDKOnDemandSpecialty *specialty;
@property (nonatomic, nullable) NSString *onDemandSpecialtyId;
@property (nonatomic, readonly) BOOL createdForFirstAvailableFlow;
@property (nonatomic) BOOL usingAskMeProvider;
@property (nonatomic, nullable) NSDate *firstAvailableSearchStartTime;
@property (nonatomic, nullable) NSDate *firstAvailableSearchEndTime;
@property (nonatomic) NSUInteger firstAvailableProviderAskCount;
@property (nonatomic, nullable) AWSDKProvider *selectedProvider;
@property (nonatomic, nullable) NSArray<NSString *> *guestEmails;
@end

@protocol AWSDKVisitFlowStateHolder
@property (nonatomic, nullable) AWSDKVisitFlowState *visitClientState;
@end
