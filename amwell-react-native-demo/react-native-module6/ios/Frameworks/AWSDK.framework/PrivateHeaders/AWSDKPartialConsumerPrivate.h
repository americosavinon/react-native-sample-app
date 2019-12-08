//
//  AWSDKPartialConsumerPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/4/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKPartialConsumer.h>

/**
 A partially enrolled consumer in the telehealth platform.

 @since 1.0.0
 */
@interface AWSDKPartialConsumer : AWSDKDataObject <AWSDKPartialConsumer>

@property (nonatomic) NSString *consumerAuthKey;

@end
