//
//  AWSDKConsumerServicePrivate.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/23/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKConsumerService.h>

@class AWSDKConsumer;

@interface AWSDKConsumerService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKConsumerService

 @return The main AWSDKConsumerService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods
/**
 @name Private Methods
 */

/**
 Loads the consumer details from the American Well Telehealth Platform.

 @param consumerAuthKey NSString representation of the consumers authentication key.
 @param completion      Completion block to be called when the network request to the American Well Telehealth Platform is completed.

 @since 3.0.0
 */
- (void)loadDetailsForConsumer:(NSString *)consumerAuthKey completion:(ConsumerResultCompletionBlock)completion;

@end
