//
//  AWSDKVisitContextPrivate.h
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

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKVisitFlowStatePrivate.h"

#import <AWSDK/AWSDKVisitContext.h>

@class AWSDKAppointment, AWSDKOnDemandSpecialty, AWSDKProvider, AWSDKVisitFlowState, AWSDKConsumer;

@interface AWSDKVisitContext () <AWSDKVisitFlowStateHolder>

@property (nonatomic) AWSDKAppointment *appointment;

@property (nonatomic) NSDate *creationDate;

@property (nonatomic) NSString *transferEngagementId;

@property (readonly) BOOL requireResidencyCheck;

@property (nonatomic) BOOL isQuickTransfer;

@property (nonatomic) NSString *providerEncryptedId;

- (NSDictionary *)toParameters;

- (void)updateConsumer:(AWSDKConsumer *)consumer
                 proxy:(AWSDKConsumer *)proxy
             specialty:(AWSDKOnDemandSpecialty *)specialty
              provider:(AWSDKProvider *)provider
           appointment:(AWSDKAppointment *)appointment;
- (void)acceptAllLegalText;

@end
