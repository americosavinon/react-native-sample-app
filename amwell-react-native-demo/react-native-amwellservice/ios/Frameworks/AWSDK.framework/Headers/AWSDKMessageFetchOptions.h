//
//  AWSDKMessageFetchOptions.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/7/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 Options for loading messages from the American Well telehealth platform.

 @since 1.0.0
 */
@interface AWSDKMessageFetchOptions : AWSDKDataObject

#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new AWSDKMessageFetchOptions instance.

 @return AWSDKMessageFetchOptions instance.

 @since 1.0.0
 */
+ (nonnull instancetype)options;

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSDate representing the earliest date desired for the fetch or _nil_ if no date specified.

 @discussion Setting earliest filters messages received since the date and then applies startIndex and maxResults options.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSDate *earliest;

/**
 NSNumber representing the starting index for the search or _nil_ if no index specified.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSNumber *startIndex;

/**
 NSNumber representing the maximum number of results to fetch or _nil_ if no max set.

 @discussion The server only supports fetching up to 100 messages at a time. If maxResults is set as _nil_ or more than 100, only up to 100 results will be fetched.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSNumber *maxResults;

@end
