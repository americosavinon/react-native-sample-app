//
//  AWSDKTriageQuestion.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/8/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A triage question to be answered during intake of a visit.

 @since 1.0.0
 */
@protocol AWSDKTriageQuestion <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the triage question to be answered.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *question;

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSString representing the consumer's response to the triage question.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *response;

@end
