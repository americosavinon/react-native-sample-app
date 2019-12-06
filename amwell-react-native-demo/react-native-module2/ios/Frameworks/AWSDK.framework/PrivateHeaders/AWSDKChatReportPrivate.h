//
//  AWSDKChatReportPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 9/27/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKChatReport.h>

@class AWSDKProvider, AWSDKChatItem;

/**
 Chat report containing an array of chat items.

 @since 2.1.0
 */
@interface AWSDKChatReport : AWSDKDataObject <AWSDKChatReport>

// Overrides for readwrites
/**
 The assigned provider in the chat, nil if no provider in the chat

 @since 2.1.0

 Set private in 2.1.0 as only pre-visit chat is supported
 */
@property (nonatomic, readwrite, nullable) AWSDKProvider *provider;

@property (nonatomic, readwrite, nullable) NSMutableArray<AWSDKChatItem *> *privateChatItems;

@property (assign, readwrite, atomic) NSInteger lastOrdinal;

/**
 The assigned assistant's full name in the chat, nil if no assistant in the chat

 @since 2.1.0
 */
@property (nonatomic, readwrite, nullable) NSString *assistantName;

/**
 The assigned assistant's title in the chat, nil if no assistant in the chat

 @since 2.1.0
 */
@property (nonatomic, readwrite, nullable) NSString *assistantTitle;

/**
 Updates the chat report with the given json, in this case will add chat items

 @param json json object for the new update changes
 */
- (void)update:(nonnull NSDictionary *)json;

/**
 Updates the master chat report and also returns the chat report with the new chat items

 @param json json object for the new update changes

 @return AWSDKChatReport for the report with the new chat items only
 */
- (nullable AWSDKChatReport *)updateWithNewReport:(nonnull NSDictionary *)json;

@end
