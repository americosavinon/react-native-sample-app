//
//  AWSDKConsumerNotifications.h
//  AWSDK
//
//  Created by Stephen Ciauri on 8/2/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

@import Foundation;

/**
 Class that represents the notifiable elements belonging to the consumer

 @since 4.2.0
 */
@interface AWSDKConsumerNotifications : NSObject

/**
 The total number of messages in the inbox of the respective AWSDKConsumer

 @since 4.2.0
 */
@property (nonatomic, readonly) int totalInboxCount;

/**
 The number of unread messages in the inbox of the respective AWSDKConsumer

 @since 4.2.0
 */
@property (nonatomic, readonly) int unreadInboxCount;

/**
 The number of dependent access requests directed at the AWSDKConsumer

 @since 4.2.0
 */
@property (nonatomic, readonly) int dependentAccessRequestCount;

/**
 The number of upcoming appointments the AWSDKConsumer has scheduled.

 @since 4.2.0
 */
@property (nonatomic, readonly) int appointmentCount;

/**
 BOOL describing whether or not the threshold for the next upcoming appointment has been reached

 @since 4.2.0
 */
@property (nonatomic, readonly) BOOL isTimeForNextAppointment;

@end
