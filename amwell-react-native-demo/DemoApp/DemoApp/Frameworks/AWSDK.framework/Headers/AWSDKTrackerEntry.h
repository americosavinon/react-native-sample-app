//
//  AWSDKTrackerEntry.h
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

// clang-format off
@protocol AWSDKTrackerDataPoint, AWSDKTrackerTemplate;
// clang-format on

/**
 Object for an individual tracker entry.

 @since 4.3.0
 */
@protocol AWSDKTrackerEntry <NSObject>

/**
 NSDate representing the date of tracker entry.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSDate *date;

/**
 NSString representing the source of the tracker entry.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *source;

/**
 NSArray representing the data points associated to this tracker entry.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSArray<id<AWSDKTrackerDataPoint>> *data;

/**
 AWSDKTrackerTemplate associated to this tracker entry.

 @since 5.0.0
 */
@property (nonatomic, nonnull, readonly) id<AWSDKTrackerTemplate> trackerTemplate;

@end
