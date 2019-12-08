//
//  AWSDKMessageFolder.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/11/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@class AWSDKMessageFetchOptions;
@protocol AWSDKMessage;

/**
 Message folder protocol used by AWSDKMessageFolderInbox and AWSDKMessageFolderSent

 @since 3.1.0
 */
@protocol AWSDKMessageFolder <AWSDKDataObject>
#pragma mark Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSArray of AWSDKMessage objects ordered from most recent to oldest.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKMessage>> *messages;

/**
 NSDate representing the time the folder was last updated by calling a fetch messages method.

 @discussion Calling [AWSDKConsumer fetchMessageInboxWithOptions:completion:], [AWSDKConsumer fetchSentMessageFolderWithOptions:completion:], fetchMessagesWithOptions:completion: and
 fetchNewMessagesWithCompletion: updates lastUpdated.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSDate *lastUpdated;

/**
 int representing the total number of messages in the folder

 @since 1.0.0
 */
@property (readonly, assign) int total;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches additional AWSDKMessages to the messages array property using AWSDKMessageFetchOptions.

 @param options    AWSDKMessageFetchOptions that describes what messages to fetch from the server.
 @param completion MessageFolderCompletionBlock containing the updated AWSDKMessageFolderInbox or AWSDKSentMessageFolder instance, otherwise an NSError describing any failures.

 @since 1.0.0
 */
- (void)fetchMessagesWithOptions:(nullable AWSDKMessageFetchOptions *)options completion:(nonnull MessageFolderCompletionBlock)completion;

/**
 Fetches any new AWSDKMessages since the last folder update.

 @discussion New AWSDKMessage is where [AWSDKMessage sent] timestamp is after lastUpdated.

 @param completion MessageFolderCompletionBlock containing the updated AWSDKMessageFolderInbox or AWSDKSentMessageFolder instance, otherwise an NSError describing any failures.

 @since 1.0.0
 */
- (void)fetchNewMessagesWithCompletion:(nonnull MessageFolderCompletionBlock)completion;

@end
