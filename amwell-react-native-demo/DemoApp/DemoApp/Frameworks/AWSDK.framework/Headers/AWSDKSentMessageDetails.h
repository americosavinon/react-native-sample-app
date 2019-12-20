//
//  AWSDKSentMessageDetails.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/20/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKSentMessage.h>

// clang-format off
@protocol AWSDKContact, AWSDKAttachment;
// clang-format on

/**
 The details protocol of a sent message.

 @since 3.1.0
 */
@protocol AWSDKSentMessageDetails <AWSDKSentMessage>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSArray of AWSDKContact recipients of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKContact>> *allRecipients;

/**
 AWSDKContact representing the sender of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKContact> sender;

/**
 NSString representing the full body of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *messageBody;

/**
 NSArray of AWSDKAttachment attachments attached to the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKAttachment>> *attachments;

/**
 BOOL set _TRUE_ if the message can be replied to, otherwise _FALSE_.

 @since 1.0.0
 */
@property (readonly) BOOL canReply;

@end
