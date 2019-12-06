//
//  AWSDKVisitTopic.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/16/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A selectable visit topic defined by the telehealth platform.

 @since 1.0.0
 */
@protocol AWSDKVisitTopic <AWSDKDataObject, NSCopying>

#pragma mark Read-Only Values
/**
 @name Read-Only Values
 */

/**
 NSString representing the displayable title of the topic.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSString *title;

/**
 NSString representing the displayable description of the topic.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *topicDescription;

#pragma mark Read-Write Values
/**
 @name Read-Write Values
 */

/**
 Set _TRUE_ if the topic is selected for a current visit, otherwise _FALSE_ if not selected.

 @since 1.0.0
 */
@property (assign, readwrite) BOOL selected;

@end
