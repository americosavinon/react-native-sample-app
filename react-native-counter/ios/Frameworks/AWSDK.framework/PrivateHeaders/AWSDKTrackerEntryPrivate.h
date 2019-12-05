//
//  AWSDKTrackerEntryPrivate.h
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

#import <AWSDK/AWSDKTrackerEntry.h>

@interface AWSDKTrackerEntry : AWSDKDataObject <AWSDKTrackerEntry>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKTrackerEntry.

 @return A new AWSDKTrackerEntry instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackerEntry;

/**
 Converts array of dictionary to array of AWSDKTrackerEntry.

 @return A new array of AWSDKTrackerEntry.

 @since 4.3.0
 */
+ (nonnull NSArray<id<AWSDKTrackerEntry>> *)arrayFromArray:(nonnull NSArray *)array trackerTemplate:(nonnull id<AWSDKTrackerTemplate>)template;

@end
