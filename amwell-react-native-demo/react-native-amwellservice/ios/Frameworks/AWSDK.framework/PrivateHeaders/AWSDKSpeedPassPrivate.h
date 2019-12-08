//
//  AWSDKSpeedPassPrivatePrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 5/16/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

@import Foundation;

#import "AWSDKOnDemandSpecialtyPrivate.h"
#import "AWSDKVisitPrivate.h"

#import <AWSDK/AWSDKSpeedPass.h>

@class AWSDKOnDemandSpecialty;

@interface AWSDKSpeedPass : AWSDKVisit <AWSDKSpeedPass>
@property (nonatomic, nullable) AWSDKOnDemandSpecialty *specialty;
@property (nonatomic, nonnull) AWSDKProvider *selectedProvider;

- (nonnull NSDictionary<NSString *, NSString *> *)toParams;

@end
