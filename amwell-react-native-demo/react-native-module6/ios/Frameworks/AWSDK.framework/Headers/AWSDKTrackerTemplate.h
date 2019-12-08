//
//  AWSDKTrackerTemplate.h
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

@protocol AWSDKTrackerComponentTemplate;
@protocol AWSDKTrackerEntryRequest;

/**
 Object representing a tracker template (E.g. blood pressure).

 @since 4.3.0
 */
@protocol AWSDKTrackerTemplate <AWSDKDataObject>

/**
 NSString representing the tracker template id.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *uuid;

/**
 NSString representing the component label (diastolic, systolic, etc) of the tracker record.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSString *title;

/**
 NSArray representing the data points associated to this tracker entry.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readonly) NSArray<id<AWSDKTrackerComponentTemplate>> *components;

/**
 Creates a new blank instance of AWSDKTrackerEntryRequest.

 @return A new AWSDKTrackerEntryRequest instance.

 @since 4.3.0
 */
- (nullable id<AWSDKTrackerEntryRequest>)newTrackerEntryRequest;

@end
