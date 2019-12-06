//
//  AWSDKHealthTrackerRecordForm.h
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

#import <AWSDK/AWSDKForm.h>

@protocol AWSDKHealthTrackerType;

/**
 AWSDKForm protocol to create a new Health Tracker Record to add to a consumer's health summary.

 @since 3.1.0
 */
@protocol AWSDKHealthTrackerRecordForm <AWSDKForm>
#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSDate object showing the date the record was collected.

 @since 3.0.0
 */
@property (nonatomic, nonnull, readwrite) NSDate *date;

/**
 NSNumber containing the value of the record, measured in the unit property of the associated AWSDKHealthTrackerType.

 @since 3.0.0
 */
@property (nonatomic, nonnull, readwrite) NSNumber *value;

/**
 AWSDKHealthTrackerType representing the type of record that is being collected.

 @since 3.0.0
 */
@property (nonatomic, nonnull, readwrite) id<AWSDKHealthTrackerType> type;

@end

/**
 AWSDKForm object to create a new Health Tracker Record to add to a consumer's health summary.

 @since 3.0.0
 */
@interface AWSDKHealthTrackerRecordForm : AWSDKForm <AWSDKHealthTrackerRecordForm>
@end
