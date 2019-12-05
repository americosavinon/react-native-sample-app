//
//  AWSDKConsumerVitals.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/10/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 Consumer's vitals information.

 @since 1.0.0
 */
@protocol AWSDKConsumerVitals

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 A consumer's systolic blood pressure represented as an NSMeasurement of NSUnitPressure.

 @since 4.1.0
 */
@property (readonly, nullable) NSMeasurement<NSUnitPressure *> *systolicBloodPressure;

/**
 A consumer's diastolic blood pressure represented as an NSMeasurement of NSUnitPressure.

 @since 4.1.0
 */
@property (readonly, nullable) NSMeasurement<NSUnitPressure *> *diastolicBloodPressure;

/**
 A consumer's temperature represented as an NSMeasurement of NSUnitTemperature.

 @since 4.1.0
 */
@property (readonly, nullable) NSMeasurement<NSUnitTemperature *> *temperature;

/**
 A consumer's weight represented as an NSMeasurement of NSUnitMass.

 @since 4.1.0
 */
@property (readonly, nullable) NSMeasurement<NSUnitMass *> *weight;

@end
