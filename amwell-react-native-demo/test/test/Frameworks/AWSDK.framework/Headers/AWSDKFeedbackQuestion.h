//
//  AWSDKFeedbackQuestion.h
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

#import <AWSDK/AWSDKDataObject.h>

/**
 A feedback question with the associated responses.

 @note Feedback questions can be configured by the admin of the server.

 @since 1.0.0
 */
@protocol AWSDKFeedbackQuestion <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable question.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *questionText;

/**
 NSArray of NSStrings representing the response options to select from.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *responseOptions;

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSInteger to set as the index of the responseOptions array to select as a response.

 @since 1.0.0
 */
@property (nonatomic) NSInteger selectedOption;

@end
