//
//  AWSDKSentMessagePrivate.h
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

#import "AWSDKMessagePrivate.h"

#import <AWSDK/AWSDKSentMessage.h>

@class AWSDKMessageFolderSent, AWSDKSentMessageDetails, AWSDKConsumer;

/**
 A sent message preview in the telehealth platform.

 @since 1.0.0
 */
@interface AWSDKSentMessage : AWSDKMessage <AWSDKSentMessage>

+ (NSArray *)sentMessagesFromArray:(NSArray *)array inFolder:(AWSDKMessageFolderSent *)sent withConsumer:(AWSDKConsumer *)consumer;

@property (nonatomic) AWSDKMessageFolderSent *container;

@property (nonatomic) AWSDKSentMessageDetails *messageDetails;

@end
