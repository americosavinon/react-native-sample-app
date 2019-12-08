//
//  AWSDKTrackerEntryRequest.h
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

@protocol AWSDKTrackerDataPointRequestEntry;

/**
 The tracker request entry associated to a list of trackers to process.

 @since 4.3.0
 */
@protocol AWSDKTrackerEntryRequest <AWSDKDataObject>

/**
 NSString representing the uuid of the TrackerTemplate.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSString *uuid;

/**
 NSArray representing the list of tracker data point request.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSArray<id<AWSDKTrackerDataPointRequestEntry>> *data;

@end
