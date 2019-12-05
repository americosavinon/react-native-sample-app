//
//  AWSDKMessageFolderSentPrivate.h
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

#import "AWSDKMessageFolderPrivate.h"

#import <AWSDK/AWSDKMessageFolderSent.h>

/**
 A sent message folder containing a consumer's AWSDKSentMessage messages.

 @since 1.0.0
 */
@interface AWSDKMessageFolderSent : AWSDKMessageFolder <AWSDKMessageFolderSent>

@end
