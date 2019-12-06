//
//  AWSDKProviderType.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/7/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A specialty protocol of a provider in the telehealth platform such as 'Family Physician'.

 @since 3.1.0
 */
@protocol AWSDKProviderType <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 Displayable name of the specialty type.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

@end
