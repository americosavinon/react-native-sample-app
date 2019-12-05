//
//  AWSDKContact.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/22/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A contact protocol of a consumer

 @since 3.1.0
 */
@protocol AWSDKContact <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the full name of the contact.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSPersonNameComponents representing name of the contact.

 @since 4.2.0
 */
@property (readonly, nullable) NSPersonNameComponents *nameComponents;

@end
