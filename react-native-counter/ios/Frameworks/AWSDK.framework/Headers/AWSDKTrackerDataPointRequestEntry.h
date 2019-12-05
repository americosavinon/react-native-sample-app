//
//  AWSDKTrackerDataPointRequestEntry.h
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
 A trackers request protocol.

 @since 4.3.0
 */
@protocol AWSDKTrackerDataPointRequestEntry <AWSDKDataObject>

/**
 NSString representing the uuid of the TrackerComponentTemplate.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *uuid;

/**
 NSNumber representing the value.

 Note: will default to 0.0 if it's not in the JSON payload.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSNumber *value;

@end
