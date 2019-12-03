//
//  AWSDKTrackerEntryRequestPrivate.h
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

#import <AWSDK/AWSDKTrackerEntryRequest.h>
#import <AWSDK/AWSDKTrackerTemplate.h>

@class AWSDKTrackerComponentTemplate;

@interface AWSDKTrackerEntryRequest : AWSDKDataObject <AWSDKTrackerEntryRequest>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKTrackerEntryRequest.

 @return A new AWSDKTrackerEntryRequest instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackerEntryRequest:(nonnull id<AWSDKTrackerTemplate>)template;

/**
 Converts array of dictionary to array of AWSDKTrackerEntryRequest.

 @return An array of AWSDKTrackerEntryRequest.

 @since 4.3.0
 */
+ (nonnull NSArray<id<AWSDKTrackerEntryRequest>> *)arrayFromArray:(nonnull NSArray *)array;

/**
 Convert an array of AWSDKTrackerEntryRequest to an array NSDictionary.

 @return A NSArray of NSDictionary.

 @since 4.3.0
 */
+ (nonnull NSArray *)arrayToParams:(nonnull NSArray<id<AWSDKTrackerEntryRequest>> *)entries;

/**
 Creates a new instance of AWSDKTrackerEntryRequest.

 @return A new AWSDKTrackerEntryRequest instance.

 @since 4.3.0
 */
- (nullable instancetype)initWithTemplate:(nonnull id<AWSDKTrackerTemplate>)template;

@end
