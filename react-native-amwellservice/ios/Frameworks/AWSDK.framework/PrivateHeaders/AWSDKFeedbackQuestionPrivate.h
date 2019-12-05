//
//  AWSDKFeedbackQuestionPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/20/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKFeedbackQuestion.h>

/**
 A feedback question with the associated responses.

 @note Feedback questions can be configured by the admin of the server.

 @since 1.0.0
 */
@interface AWSDKFeedbackQuestion : AWSDKDataObject <AWSDKFeedbackQuestion>
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@property (nonatomic) NSString *selected;

@end
