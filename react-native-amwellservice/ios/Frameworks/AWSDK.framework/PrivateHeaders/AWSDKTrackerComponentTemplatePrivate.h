//
//  AWSDKTrackerComponentTemplatePrivate.h
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

@interface AWSDKTrackerComponentTemplate : AWSDKDataObject <AWSDKTrackerComponentTemplate>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKTrackerComponentTemplate.

 @return A new AWSDKTrackerComponentTemplate instance.

 @since 4.3.0
 */
+ (nonnull instancetype)trackerComponentTemplate;

/**
 Converts array of dictionary to array of AWSDKTrackerComponentTemplate.

 @return A new array of AWSDKTrackerComponentTemplate.

 @since 4.3.0
 */
+ (nonnull NSArray<id<AWSDKTrackerComponentTemplate>> *)arrayFromArray:(nonnull NSArray *)array;

@end
