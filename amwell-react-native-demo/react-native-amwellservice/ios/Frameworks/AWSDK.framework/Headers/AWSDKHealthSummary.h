//
//  AWSDKHealthSummary.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/14/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKHealthSummaryRecord;

/**
 A consumer's health summary protocol including allergies, diagnoses, medications and procedures.

 @since 3.1.0
 */
@protocol AWSDKHealthSummary <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSArray of AWSDKHealthSummaryRecord objects representing the list of consumer reported allergies.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKHealthSummaryRecord>> *allergies;

/**
 NSArray of AWSDKHealthSummaryRecord objects representing reported diagnoses for the consumer.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKHealthSummaryRecord>> *diagnoses;

/**
 NSArray of AWSDKHealthSummaryRecord objects representing reported medications for the consumer.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKHealthSummaryRecord>> *medications;

/**
 NSArray of AWSDKHealthSummaryRecord objects representing reported past procedures for the consumer.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKHealthSummaryRecord>> *procedures;

@end
