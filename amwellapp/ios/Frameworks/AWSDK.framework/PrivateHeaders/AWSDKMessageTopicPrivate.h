//
//  AWSDKMessageTopicPrivate.h
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

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKMessageTopic.h>

@interface AWSDKMessageTopic ()

+ (NSArray *)topicsFromArray:(NSArray *)array;

+ (AWSDKMessageTopic *)none;

@property (nonatomic) NSString *enumKey;

@end
