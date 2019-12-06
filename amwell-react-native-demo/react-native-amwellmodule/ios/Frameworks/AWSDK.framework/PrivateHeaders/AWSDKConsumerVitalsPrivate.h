//
//  AWSDKConsumerVitalsPrivate.h
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

#import <AWSDK/AWSDKConsumerVitals.h>

/**
 Consumer's vitals information.

 @since 1.0.0
 */
@interface AWSDKConsumerVitals : NSObject <AWSDKConsumerVitals>
// Read-write overrides
@property (readwrite) NSMeasurement<NSUnitPressure *> *systolicBloodPressure;
@property (readwrite) NSMeasurement<NSUnitPressure *> *diastolicBloodPressure;
@property (readwrite) NSMeasurement<NSUnitTemperature *> *temperature;
@property (readwrite) NSMeasurement<NSUnitMass *> *weight;

@property (nonatomic, class, readonly) NSUnitPressure *pressureUnit;
@property (nonatomic, class, readonly) NSUnitMass *weightUnit;
@property (nonatomic, class, readonly) NSUnitTemperature *temperatureUnit;

- (void)populate:(NSDictionary *)dict;

@end
