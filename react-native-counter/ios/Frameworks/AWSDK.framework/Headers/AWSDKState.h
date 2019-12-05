//
//  AWSDKState.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/18/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

@class AWSDKCountry;
/**
 A physical state protocol such as 'New York' or 'Michigan'.

 @since 3.1.0
 */
@protocol AWSDKState <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable name of the state.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString as the short string to represent the state, e.g. 'NY' or 'MI'.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *code;

/**
 The country the state belongs to.

 @since 4.0.0
 */
@property (nonatomic, readonly, nonnull) AWSDKCountry *country;

@end
