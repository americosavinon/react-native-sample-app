//
//  AWSDKInboxMessageDetails.h
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

#import <AWSDK/AWSDKInboxMessage.h>

// clang-format off
@protocol AWSDKContact, AWSDKAttachment;
// clang-format on
/**
 A inbox message details protocol

 @since 3.1.0
 */
@protocol AWSDKInboxMessageDetails <AWSDKInboxMessage>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKContact representing the message recipient.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKContact> recipient;

/**
 NSArray of AWSDKContacts representing all other recipients.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKContact>> *otherRecipients;

/**
 AWSDKContact representing the sender.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKContact> sender;

/**
 NSString representing the full body of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *messageBody;

/**
 NSArray of AWSDKAttachment objects attached to the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKAttachment>> *attachments;

/**
 BOOL set _TRUE_ if the message can be replied to, otherwise _FALSE_ if reply is not allowed.

 @since 1.0.0
 */
@property (assign, readonly) BOOL canReply;

/**
 BOOL set _TRUE_ if the message is a reply and has a source message, otherwise _FALSE_ if it's a source message and not a reply.

 @since 1.0.0
 */
@property (assign, readonly) BOOL hasSourceMessage;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the details of the message that the message was in response to.

 @param completion InboxMessageDetailsCompletionBlock containing the AWSDKInboxMessageDetails, otherwise an NSError object representing the source message.

 @since 1.0.0
 */
- (void)fetchSourceMessageWithCompletion:(nonnull InboxMessageDetailsCompletionBlock)completion;

@end
