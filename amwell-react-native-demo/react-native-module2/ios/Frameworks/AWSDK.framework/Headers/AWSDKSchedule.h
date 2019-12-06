//
//  AWSDKSchedule.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/25/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 The schedule protocol of an appointment or past visit.

 @since 3.1.0
 */
@protocol AWSDKSchedule <AWSDKDataObject>
#pragma mark - Read-Only Schedule Times
/**
 @name Read-Only Schedule times
 */

/**
 NSDate representing the actual start time of the visit, otherwise _nil_ if visit hasn't started yet.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSDate *startTime;

/**
 NSDate representing the scheduled start time of the appointment, otherwise _nil_ if not an appointment.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSDate *scheduledStartTime;

/**
 NSDate representing the time the visit was cancelled, otherwise _nil_ if not cancelled.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSDate *cancelTime;

/**
 NSDate representing the time the consumer started waiting for the visit, otherwise _nil_ if the visit hasn't started yet.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSDate *waitStartTime;

#pragma mark - Read-Only Chat Times
/**
 @name Read-Only Chat Times
 */

/**
 NSDate representing the time the pre-visit conversation started, otherwise _nil_ if no chat was started before the visit.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSDate *preVisitChatStartTime;

/**
 NSDateInterval representing the time between when the post-visit conversation started and ended, otherwise _nil_ if no chat was started after the visit.

 @since 5.0.0
 */
@property (nonatomic, nullable, readonly) NSDateInterval *postVisitChatTimeInterval;

#pragma mark - Read-Only Durations
/**
 @name Read-Only Durations
 */

/**
 NSNumber representing the actual duration of the visit in milliseconds, otherwise _nil_ if the visit hasn't started yet.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSNumber *duration;

/**
 NSNumber representing the alloted duration of the visit in milliseconds, otherwise _nil_ if not used.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSNumber *allotedDuration;

/**
 NSNumber representing the alloted duration of the visit extension in milliseconds, otherwise _nil_ if not used.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSNumber *allotedExtensionDuration;

/**
 NSNumber representing the duration the consumer waited before cancelling the visit or being served by the provider in seconds, otherwise _nil_ if the visit hasn't started yet.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSNumber *waitDuration;

/**
 NSNumber representing the duration the provider's status is unavailable or busy following the visit, otherwise _nil_ if not used.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSNumber *postVisitBufferDuration;

@end
