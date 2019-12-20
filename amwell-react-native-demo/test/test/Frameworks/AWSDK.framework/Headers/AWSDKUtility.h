//
//  AWSDKUtility.h
//  AWSDK
//
//  Created by Rolin Nelson on 7/10/19.
//  Copyright © 2019 American Well. All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>

/**
 Provides utility methods to perform some useful tasks.

 @since 5.1.0
 */
@interface AWSDKUtility : NSObject

/**
 Computes the amount of time in seconds the system takes to perform a DNS lookup for the supplied URL.

 @note The information provided by this utiliy can be useful during performance optimization or troubleshooting network issues.

 @param url The URL for the look up.
 @param completion TimeIntervalCompletionBlock containing the computed NSTimeInterval, otherwise an NSError with any applicable error cases.

 Potential Error Codes
 @exception 400 Bad URL - Indicates url was not valid.
 @exception 404 Info Not Found - Indicates name info for url was not found.

 @since 5.1.0
 */
+ (void)getDNSLookupTimeFor:(NSURL *)url completion:(TimeIntervalCompletionBlock)completion;

/**
 Returns an NSDate extracted from the given NSString using the cached NSISO8601DateFormatter date formatter.

 @param string The string to retrieve date from

 @since 5.1.0
 */
+ (NSDate *)dateFromString:(NSString *)string;

@end
