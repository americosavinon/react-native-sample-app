//
//  AWSDKTrackerDataPointRequestEntryPrivate.h
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

#import <AWSDK/AWSDKTrackerComponentTemplate.h>
#import <AWSDK/AWSDKTrackerDataPointRequestEntry.h>

@interface AWSDKTrackerDataPointRequestEntry : AWSDKDataObject <AWSDKTrackerDataPointRequestEntry>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKTrackerDataPointRequestEntry.

 @return A new AWSDKTrackerDataPointRequestEntry instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackerDataPointRequestEntry:(nonnull id<AWSDKTrackerComponentTemplate>)template;

/**
 Converts array of dictionary to array of AWSDKTrackerEntryRequest.

 @return An array of AWSDKTrackerEntryRequest.

 @since 4.3.0
 */
+ (nonnull NSArray<id<AWSDKTrackerDataPointRequestEntry>> *)arrayFromArray:(nonnull NSArray *)array;

/**
 Convert an array of AWSDKTrackerDataPointRequestEntry to an array NSDictionary.

 @return A NSArray of NSDictionary.

 @since 4.3.0
 */
+ (nonnull NSArray<NSDictionary *> *)arrayToParams:(nonnull NSArray<id<AWSDKTrackerDataPointRequestEntry>> *)data;

/**
 Creates a new instance of AWSDKTrackerDataPointRequestEntry.

 @return A new AWSDKTrackerDataPointRequestEntry instance.

 @since 4.3.0
 */
- (nullable instancetype)initWithTemplate:(nonnull id<AWSDKTrackerComponentTemplate>)template;

- (nullable instancetype)initWithUUID:(nonnull NSString *)uuid;

/**
 Creates a dictionary representation of AWSDKTrackerDataPointRequestEntry.

 @return A new NSDictionary instance.

 @since 4.3.0
 */
- (nonnull NSDictionary *)toParams;

@end
