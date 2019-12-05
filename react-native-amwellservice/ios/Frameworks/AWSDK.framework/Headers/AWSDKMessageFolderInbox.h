//
//  AWSDKMessageFolderInbox.h
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

#import <AWSDK/AWSDKMessageFolder.h>

/**
 A message inbox protocol containing a consumer's AWSDKInboxMessage messages.

 @since 3.1.0
 */
@protocol AWSDKMessageFolderInbox <AWSDKMessageFolder>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 int representing the number of unread messages in the inbox, including messages not currently loaded.

 @since 1.0.0
 */
@property (assign, readonly) int unread;
@end
