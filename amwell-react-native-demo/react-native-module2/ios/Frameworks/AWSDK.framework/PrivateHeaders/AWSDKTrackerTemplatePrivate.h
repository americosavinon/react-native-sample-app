//
//  AWSDKTrackerTemplatePrivate.h
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

#import <AWSDK/AWSDKTrackerTemplate.h>

@interface AWSDKTrackerTemplate : AWSDKDataObject <AWSDKTrackerTemplate>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKTrackerTemplate.

 @return A new AWSDKTrackerTemplate instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackerTemplate;

/**
 Converts array of dictionary to array of AWSDKTrackerTemplate.

 @return A new array of AWSDKTrackerTemplate.

 @since 4.3.0
 */
+ (nonnull NSArray<id<AWSDKTrackerTemplate>> *)arrayFromArray:(nonnull NSArray *)array;

@end
