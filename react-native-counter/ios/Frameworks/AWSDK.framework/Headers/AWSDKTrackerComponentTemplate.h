//
//  AWSDKTrackerComponentTemplate.h
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

/**
 Object representing a tracker component template (E.g. systolic and diastolic of blood pressure).

 @since 4.3.0
 */
@protocol AWSDKTrackerComponentTemplate <AWSDKDataObject>

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
 NSString representing the unit of measurement short description.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *unitOfMeasureShortDescription;

/**
 NSString representing the unit of measurement full description.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *unitOfMeasureFullDescription;

/**
 NSNumber representing the minimum measurement value.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSNumber *minimum;

/**
 NSNumber representing the maximum measurement value.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSNumber *maximum;

@end
