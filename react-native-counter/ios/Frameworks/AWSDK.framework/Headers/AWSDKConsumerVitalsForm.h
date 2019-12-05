//
//  AWSDKConsumerVitals.h
//  AWSDK
//
//  Created by Steven Uy on 8/09/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKForm.h>

/**
 Class used to update a consumer's vitals information.

 @since 2.0.0
 */
@protocol AWSDKConsumerVitalsForm <AWSDKForm>

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 A consumer's systolic blood pressure represented as an NSMeasurement of NSUnitPressure.

 @discussion This is traditionally the top of the blood pressure reading. The valid range of this value is between 0 and 250 hmmg. If this value is present, diastolicBloodPressure must also be present
 and valid. This value must be greater than diastolicBloodPressure.

 @since 4.1.0
 */
@property (readwrite, nullable) NSMeasurement<NSUnitPressure *> *systolicBloodPressure;

/**
 A consumer's diastolic blood pressure represented as an NSMeasurement of NSUnitPressure.

 @discussion This is traditionally the bottom of the blood pressure reading. The valid range of this value is between 0 and 250 hmmg. If this value is present, systolicBloodPressure must also be
 present and valid. This value must be less than systolicBloodPressure.

 @since 4.1.0
 */
@property (readwrite, nullable) NSMeasurement<NSUnitPressure *> *diastolicBloodPressure;

/**
 A consumer's temperature represented as an NSMeasurement of NSUnitTemperature.

 @discussion This value must be between 60 and 120 farenheit.

 @since 4.1.0
 */
@property (readwrite, nullable) NSMeasurement<NSUnitTemperature *> *temperature;

/**
 A consumer's weight represented as an NSMeasurement of NSUnitMass.

 @discussion This value must be between 1 and 500 lbs.

 @since 4.1.0
 */
@property (readwrite, nullable) NSMeasurement<NSUnitMass *> *weight;

@end

/**
 Class used to update a consumer's vitals information.

 @since 2.0.0
 */
@interface AWSDKConsumerVitalsForm : AWSDKForm <AWSDKConsumerVitalsForm>
@end
