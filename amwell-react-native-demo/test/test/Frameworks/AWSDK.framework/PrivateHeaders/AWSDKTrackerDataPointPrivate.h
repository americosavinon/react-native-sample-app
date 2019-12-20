//
//  AWSDKTrackerDataPointPrivate.h
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

#import <AWSDK/AWSDKTrackerDataPoint.h>

@interface AWSDKTrackerDataPoint : AWSDKDataObject <AWSDKTrackerDataPoint>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Converts array of dictionary to array of AWSDKTrackerDataPoint.

 @return A new array of AWSDKTrackerDataPoint.

 @since 4.3.0
 */
+ (NSArray<id<AWSDKTrackerDataPoint>> *)arrayFromArray:(NSArray *)array;

@end
