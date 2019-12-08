//
//  AWSDKMessagePrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/8/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKMessage.h>

@class AWSDKConsumer;

/**
 A message in the Telehealth system.

 @discussion AWSDKMessage is not used directly, use AWSDKInboxMessage and AWSDKSentMessage instead.

 @since 1.0.0
 */
@interface AWSDKMessage : AWSDKDataObject <AWSDKMessage>

@property (nonatomic) AWSDKConsumer *consumer;

@end
