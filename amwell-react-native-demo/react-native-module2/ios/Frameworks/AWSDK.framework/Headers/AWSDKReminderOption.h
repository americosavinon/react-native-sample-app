//
//  AWSDKReminderOption.h
//  AWSDK
//
//  Created by Matt Labush on 8/9/17.
//  Copyright © 2018 American Well. All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 Consumer selectable appointment reminder options protocol such as '15 minutes' or '1 week'.

 @since 3.2.0
 */
@protocol AWSDKReminderOption <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the display name of the reminder option.

 @since 3.2.0
 */
@property (nonatomic, readonly, nonnull) NSString *label;

/**
 NSInteger representing the number of minutes for the reminder option.

 @since 3.2.0
 */
@property (nonatomic, assign, readonly) NSInteger minutes;

@end
