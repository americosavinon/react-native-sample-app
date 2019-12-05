//
//  AWSDKInboxMessage.h
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

#import <AWSDK/AWSDKMessage.h>

/**
 An inbox message preview.

 @since 3.1.0
 */
@protocol AWSDKInboxMessage <AWSDKMessage>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 BOOL set _TRUE_ if the message has a reply, otherwise _FALSE_ if no reply exists.

 @since 1.0.0
 */
@property (assign, readonly) BOOL isReplied;

/**
 BOOL set _TRUE_ if the message is a notification from the American Well telehealth platform, otherwise _FALSE_ if not sent by the system.

 @since 1.0.0
 */
@property (assign, readonly) BOOL isSystemNotification;

/**
 BOOL set _TRUE_ if the message is marked as unread, otherwise _FALSE_ if already read.

 @since 1.0.0
 */
@property (assign, readonly) BOOL isUnread;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Marks the message as read on the American Well telehealth platform.

 @param completion GenericCompletionBlock containing _TRUE_ if the message was successfully marked as read, otherwise _FALSE_ and an optional NSError with any failures.

 @since 1.0.0
 */
- (void)markMessageRead:(nullable GenericCompletionBlock)completion;

@end
