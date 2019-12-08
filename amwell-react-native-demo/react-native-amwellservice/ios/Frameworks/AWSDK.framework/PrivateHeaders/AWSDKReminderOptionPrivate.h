//
//  AWSDKReminderOptionPrivate.h
//  AWSDK
//
//  Created by Matt Labush on 8/9/17.
//  Copyright © 2018 American Well. All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKReminderOption.h>

/**
 A reminder option such as '15 Minutes' or '1 Hour'

 @since 3.2.0
 */
@interface AWSDKReminderOption : AWSDKDataObject <AWSDKReminderOption>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString submitted indicating the selected value for both the consumer and provider reminder options when scheduling an appointment.

 @since 3.2.0
 */
@property (nonatomic, readonly, nonnull) NSString *value;

#pragma mark Constructor

/**
 NSArray of AWSDKReminderOption objects generated from an incoming array of web service-provided reminder option dictionaries.

 @param    reminderOptionsArray  An array of reminder option dictionaries from the web service.

 @return   NSArray of AWSDKReminderOption objects.

 @since 3.2.0
 */
+ (nonnull NSArray<AWSDKReminderOption *> *)optionsFromArray:(nonnull NSArray<AWSDKReminderOption *> *)reminderOptionsArray;

/**
 NSString of private 'value' property, required for submitting a reminder option when scheduling an appointment.

 @return   NSString containing the private 'value' property.

 @since 3.2.0
 */
- (nonnull NSString *)valueString;

@end
