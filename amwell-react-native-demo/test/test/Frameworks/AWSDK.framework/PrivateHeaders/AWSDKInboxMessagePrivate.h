//
//  AWSDKInboxMessagePrivate.h
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

#import "AWSDKMessagePrivate.h"

#import <AWSDK/AWSDKInboxMessage.h>

@class AWSDKInboxMessageDetails, AWSDKMessageFolderInbox, AWSDKConsumer;

/**
 An inbox message preview.

 @since 1.0.0
 */
@interface AWSDKInboxMessage : AWSDKMessage <AWSDKInboxMessage>

/*
 Need to pass the auth key here for authentication when performing actions on the messages
 */
+ (NSArray *)messagesFromArray:(NSArray *)array inInbox:(AWSDKMessageFolderInbox *)inbox withConsumer:(AWSDKConsumer *)consumer;

@property (nonatomic) AWSDKMessageFolderInbox *inbox;

@property (nonatomic) AWSDKInboxMessageDetails *messageDetails;

@property (assign, readwrite) BOOL isUnread;

- (void)updateIsUnread:(BOOL)isUnread;

@end
