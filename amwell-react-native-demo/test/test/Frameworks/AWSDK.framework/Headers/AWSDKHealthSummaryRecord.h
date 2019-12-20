//
//  AWSDKHealthSummaryRecord.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/15/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A record protocol in a consumer's health summary such as an allergy or medication.

 @since 3.1.0
 */
@protocol AWSDKHealthSummaryRecord <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSDate representing the first time recorded, otherwise _nil_ if not available.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSDate *firstOccurrence;

/**
 NSDate representing the last time recorded, otherwise _nil_ if not available.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSDate *lastOccurrence;

/**
 NSString representing the description of the record, otherwise _nil_ if not available.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *recordDescription;

/**
 NSString representing the displayable name.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *displayName;

/**
 BOOL set _TRUE_ if the record was self reported, _FALSE_ otherwise.

 @since 1.0.0
 */
@property (readonly, nonatomic) BOOL selfReported;
@end
