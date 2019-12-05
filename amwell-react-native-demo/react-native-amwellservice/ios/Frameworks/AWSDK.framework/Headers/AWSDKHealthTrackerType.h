//
//  AWSDKHealthTrackerType.h
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

#import <AWSDK/AWSDKDataObject.h>

/**
 The type of an AWSDKHealthTrackerRecord, including information about the measurement units and HealthKit identifier.

 @since 3.1.0
 */
@protocol AWSDKHealthTrackerType <AWSDKDataObject>
#pragma mark - Getter Methods
/**
 @name Getter Methods
 */

/**
 Retrieves a list of AWSDKHealthTrackerTypes supported by the telehealth platform

 @return NSArray of AWSDKHealthTrackerType objects

 @since 3.0.0
 */
+ (nonnull NSArray<id<AWSDKHealthTrackerType>> *)supportedTrackerTypes;

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 The localized display name of the tracker type.

 @since 3.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *displayName;

/**
 The number of decimal places configured for the type.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) NSInteger fractionDigits;

/**
 The string representation of the HealthKit quantity type.

 @remark You can initialize an HKObject type with:
 @code
 HKQuantityType.quantityType(forIdentifier: HKQuantityTypeIdentifier(rawValue: typeString))
 @endcode

 @since 3.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *typeString;

/**
 The string representation of the HealthKit unit type.

 @remark You can initialize an HKUnit with:
 @code
 HKUnit(from: unitString)
 @endcode

 @since 4.2.6
 */
@property (nonatomic, nonnull, readonly) NSString *unitString;

/**
 The category this AWSDKTrackerType belongs to. Available Categories include:

 - nutrition
 - bodyMeasurements
 - fitness
 - labResults
 - vitals

 @since 3.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *category;

@end

/**
 The type of an AWSDKHealthTrackerRecord, including information about the measurement units and HealthKit identifier.

 @since 3.0.0
 */
@interface AWSDKHealthTrackerType : AWSDKDataObject <AWSDKHealthTrackerType>
@end
