//
//  AWSDKFollowUpItem.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/30/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A suggested follow-up action that the consumer should take.

 @since 1.0.0
 */
@protocol AWSDKFollowUpItem <AWSDKDataObject>

/**
 Enum definition for the type of follow-up item.

 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, AWSDKFollowUpItemType) {
    /**
     Specifier was not provided.

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeUndefined = 0,
    /**
     Another telehealth visit with a provider .

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeVisit,
    /**
     Follow-up item administered during intake.

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeIntake,
    /**
     Reminder for the patient to track a certain health point, such as Active Calories Burned or Body Weight, to report during the next visit.

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeTrackerReminder,
    /**
     Media available on American Well's telehealth platform for the consumer to view for more information.

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeMedia,
    /**
     A scheduled appointment

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeAppointment,
    /**
     Referral to another provider

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeReferral,
    /**
     Provider sick slip

     @since 2.1.0
     */
    AWSDKFollowUpItemTypeSickSlip,
};

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing a displayable description of the follow-up item.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *itemDescription;

/**
 NSString representing the duration of the follow-up item, otherwise _nil_ if not applicable.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *duration;

/**
 NSString representing the frequency of the follow-up item, otherwise _nil_ if not applicable.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *frequency;

/**
 NSDate representing an associated time of the follow-up item, otherwise _nil_ if not applicable.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSDate *time;

/**
 Boolean value indicating whether or not the follow-up item should happen more than once.

 @since 1.0.0
 */
@property (readonly) BOOL recurring;

/**
 AWSDKFollowUpItemType representing the type of follow-up item.

 @since 1.0.0
 */
@property (readonly) AWSDKFollowUpItemType type;

@end
