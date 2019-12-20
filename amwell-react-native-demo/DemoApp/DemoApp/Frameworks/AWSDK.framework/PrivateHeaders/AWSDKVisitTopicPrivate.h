//
//  AWSDKVisitTopicPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/26/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKVisitTopic.h>

/**
 A selectable visit topic defined by the telehealth platform.

 @since 1.0.0
 */
@interface AWSDKVisitTopic : AWSDKDataObject <AWSDKVisitTopic, NSCopying>
+ (NSArray *)visitTopicsWithArray:(NSArray *)topicDicts;

@end
