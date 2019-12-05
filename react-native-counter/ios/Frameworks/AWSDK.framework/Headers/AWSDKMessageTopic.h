//
//  AWSDKMessageTopic.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 A topic of an AWSDKMessage or AWSDKMessageDraft.

 @since 3.1.1
 */
@protocol AWSDKMessageTopic <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable name of the topic.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches all valid message topics for the telehealth platform.

 @param completion MessageTopicsCompletionBlock containing an NSArray of AWSDKMessageTopic objects, otherwise an NSError describing failures.

 @since 1.0.0
 */
+ (void)fetchAvailableTopics:(nullable MessageTopicsCompletionBlock)completion;

@end

/**
 A topic of an AWSDKMessage or AWSDKMessageDraft.
 */
@interface AWSDKMessageTopic : AWSDKDataObject <AWSDKMessageTopic>
@end
