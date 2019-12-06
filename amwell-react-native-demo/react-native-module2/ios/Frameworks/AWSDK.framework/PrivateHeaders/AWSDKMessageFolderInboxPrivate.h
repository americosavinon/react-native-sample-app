//
//  AWSDKMessageFolderInboxPrivate.h
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

#import "AWSDKMessageFolderPrivate.h"

#import <AWSDK/AWSDKMessageFolderInbox.h>

/**
 A message inbox containing a consumer's AWSDKInboxMessage messages.

 @since 1.0.0
 */
@interface AWSDKMessageFolderInbox : AWSDKMessageFolder <AWSDKMessageFolderInbox>

@end
