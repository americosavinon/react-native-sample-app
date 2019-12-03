//
//  AWSDKSentMessageDetailsPrivate.h
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

#import "AWSDKSentMessagePrivate.h"

#import <AWSDK/AWSDKSentMessageDetails.h>

/**
 The details of a sent message.

 @since 1.0.0
 */
@interface AWSDKSentMessageDetails : AWSDKSentMessage <AWSDKSentMessageDetails>

@property (nonatomic) AWSDKSentMessage *preview;

@end
