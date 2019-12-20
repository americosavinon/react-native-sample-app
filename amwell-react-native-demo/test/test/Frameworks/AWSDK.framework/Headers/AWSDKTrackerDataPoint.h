//
//  AWSDKTrackerDataPoint.h
//  AWSDK
//
//  Created by Rolin Nelson on 10/24/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKTrackerDataPoint;

/**
 Object representing individual data point captured in a tracker.

 @since 4.3.0
 */
@protocol AWSDKTrackerDataPoint <AWSDKDataObject>

/**
 NSString representing the uuid of the TrackerComponentTemplate.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *uuid;

/**
 NSString representing the component label (diastolic, systolic, etc) of the tracker record.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *title;

/**
 NSDate representing the date of the measurement.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSDate *measurementDate;

/**
 NSNumber representing the measurement value.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSNumber *value;

/**
 NSString representing the unit of measurement short description.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *unitOfMeasureShortDescription;

/**
 NSString representing the unit of measurement full description.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *unitOfMeasureFullDescription;

@end
