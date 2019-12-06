//
//  AWSDKCostPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/28/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWCoreSDK/AWCoreVisitCostProtocol.h>
#import <AWSDK/AWSDKCost.h>

/**
 The cost or estimated cost of a visit.

 @since 1.0.0
 */
@interface AWSDKCost : AWSDKDataObject <AWSDKCost, AWCoreVisitCostProtocol>
@property (readonly, nonnull, nonatomic) NSString *currencyCode;
@property (readonly) float extensionProjectedCost;

/**
 Sent by the American Well Telehealth Platform if the visit is free. This will be false if the billing is deferred.

 @since 3.0.0
 */
@property (readonly, assign, nonatomic) BOOL isZeroCostVisit;

- (void)setCouponCode:(nonnull NSString *)code;

@end
