//
//  AWSDKHealthPlanPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/2/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKHealthPlan.h>

/**
 A health plan that a consumer can be subscribed to.

 @since 1.0.0
 */
@interface AWSDKHealthPlan ()

+ (NSArray *)arrayFromArray:(NSArray *)array;

@property (nonatomic) NSString *qualifier;

@property (nonatomic) NSString *validationRegex;

@property (nonatomic) UIImage *cardImage;

@end
