//
//  AWSDKAllergy.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/14/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 An allergy protocol that may be current for a consumer.

 @since 3.1.0
 */
@protocol AWSDKAllergy <AWSDKDataObject>
#pragma mark - Read-Only Properties

/**
 @name Read-Only Properties
 */

/**
 NSString displayable name of the allergy.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *displayName;

#pragma mark - Read-Write Properties

/**
 @name Read-Write Properties
 */

/**
 Boolean value indicating if a consumer is currently suffering from the allergy.

 @discussion Setting this is used with [AWSDKConsumer updateAllergies:withCompletion:] to update the allergies for a consumer.

 @since 1.0.0
 */
@property (readwrite, nonatomic) BOOL isCurrent;

@end
