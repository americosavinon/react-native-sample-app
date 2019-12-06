//
//  AWSDKHealthTrackerTypePrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/9/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKHealthTrackerType.h>

@interface AWSDKHealthTrackerType () <NSCoding>

+ (NSArray<AWSDKHealthTrackerType *> *)trackerTypesFromArray:(NSArray *)array;

@end
