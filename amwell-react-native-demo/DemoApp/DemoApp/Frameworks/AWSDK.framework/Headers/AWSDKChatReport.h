//
//  AWSDKChatReport.h
//  AWSDK
//
//  Created by Steven Uy on 9/27/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.

#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKChatItem;

/**
 Chat report protocol containing an array of chat items.

 @since 3.1.0
 */
@protocol AWSDKChatReport <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSArray of AWSDKChatItem items, otherwise _nil_ if no chat items.

 @discussion These are sorted based on [AWSDKChatItem ordinal] values.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKChatItem>> *chatItems;
@end
