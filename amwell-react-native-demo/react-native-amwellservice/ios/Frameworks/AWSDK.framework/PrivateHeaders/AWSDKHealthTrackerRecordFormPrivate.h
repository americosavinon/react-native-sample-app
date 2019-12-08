//
//  AWSDKHealthTrackerRecordFormPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/11/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKFormPrivate.h"
#import "AWSDKHealthTrackerTypePrivate.h"

#import <AWSDK/AWSDKHealthTrackerRecordForm.h>

/**
 Used for requests where a single NSArray of AWSDKHealthTrackerRecordForm result is expected.

 @discussion Will contain the expected NSArray result, otherwise an optional NSError if there are any problems with the request.

 @param trackerFormData The expected NSArray object.
 @param error   NSError explaining why the request failed.

 @since 4.1.0
 */
typedef void (^HealthTrackerRecordFormArrayCompletionBlock)(NSArray<AWSDKHealthTrackerRecordForm *> *_Nullable trackerFormData, NSError *_Nullable error);

@interface AWSDKHealthTrackerRecordForm () <NSCoding>

+ (void)archiveHealthKitData:(nonnull NSArray *)data;
+ (nullable NSArray<NSDictionary *> *)unarchiveHealthKitData;
+ (nullable NSArray<NSDictionary *> *)unarchiveHealthKitDataFromDevice;

- (nonnull NSDictionary *)toParams;

@end
