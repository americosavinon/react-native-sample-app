//
//  AWSDKChatItemPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 9/13/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKUserPrivate.h"

#import <AWSDK/AWSDKChatItem.h>

/**
 Individual chat message and associated metadata.

 @since 2.1.0
 */
@interface AWSDKChatItem : AWSDKDataObject <AWSDKChatItem>

+ (NSMutableArray *)arrayFromItems:(NSArray *)array;

@end
