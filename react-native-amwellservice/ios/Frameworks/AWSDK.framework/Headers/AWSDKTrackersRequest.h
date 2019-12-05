//
//  AWSDKTrackersRequest.h
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

@protocol AWSDKTrackerEntryRequest;

/**
 Object for list of requested trackers to process.

 @since 4.3.0
 */
@interface AWSDKTrackersRequest : NSObject
/**
 Creates a new blank instance of AWSDKTrackersRequest.

 @return A new AWSDKTrackersRequest instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackersRequest;

/**
 NSDate representing the date and time of the measurement.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSDate *measurementDateTime;

/**
 NSTimeZone representing the timezone of the measurement.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSTimeZone *timeZone;

/**
 NSArray representing the list of tracker entry request.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSArray<id<AWSDKTrackerEntryRequest>> *entries;

@end
