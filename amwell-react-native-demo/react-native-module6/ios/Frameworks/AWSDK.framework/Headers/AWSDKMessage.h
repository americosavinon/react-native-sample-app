//
//  AWSDKMessage.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/8/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKMessageTopic;

/**
 A message protocol in the American Well telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKMessage <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing a truncated preview of the message body.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *bodyPreview;

/**
 NSDate representing the time the message was sent.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSDate *sent;

/**
 NSArray of NSStrings representing all recipients names of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *recipients;

/**
 NSString representing the name of the sender.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *senderName;

/**
 NSString representing the subject of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *subject;

/**
 AWSDKMessageTopic representing the selected topic of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKMessageTopic> topic;

/**
 BOOL set _TRUE_ if the message has been marked as deleted, otherwise _FALSE_ if it hasn't been deleted.

 @since 1.0.0
 */
@property (assign, readonly) BOOL isDeleted;

/**
 BOOL set _TRUE_ if the message has any attachments, otherwise _FALSE_ if not attachments exist.

 @since 1.0.0
 */
@property (assign, readonly) BOOL hasAttachment;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the AWSDKInboxMessageDetails or AWSDKSentMessageDetails representing the message details.

 @param completion MessageDetailsCompletionBlock containing the AWSDKInboxMessageDetails or AWSDKSentMessageDetails object, otherwise an NSError describing any error cases.

 @since 1.0.0
 */
- (void)fetchMessageWithCompletion:(nonnull MessageDetailsCompletionBlock)completion;

/**
 Marks the message as deleted on the American Well telehealth platform, and removes the message from the containing message folder.

 @param completion GenericCompletionBlock containing _TRUE_ if the message was successfully marked as deleted, otherwise _FALSE_ and an optional NSError with any failures.

 @since 1.0.0
 */
- (void)deleteMessageWithCompletion:(nullable GenericCompletionBlock)completion;

@end
