//
//  AWSDKInboxMessageDetailsPrivate.h
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

#import "AWSDKInboxMessagePrivate.h"

#import <AWSDK/AWSDKInboxMessageDetails.h>

/**
 An inbox message details.

 @since 1.0.0
 */
@interface AWSDKInboxMessageDetails : AWSDKInboxMessage <AWSDKInboxMessageDetails>

@property (nonatomic) AWSDKInboxMessageDetails *source;

@property (nonatomic) AWSDKInboxMessage *preview;

@end
