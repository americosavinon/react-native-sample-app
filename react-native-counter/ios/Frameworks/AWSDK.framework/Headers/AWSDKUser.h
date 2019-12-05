//
//  AWSDKUser.h
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

#import <AWSDK/AWSDKBiologicalSex.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 A User protocol of American Well's telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKUser <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSPersonNameComponents representing the user's name.

 @since 4.2.0
 */
@property (nonatomic, readonly, nonnull) NSPersonNameComponents *nameComponents;

/**
 AWSDKBiologicalSex representing the user's biologial sex.

 @note As of 2.0.0 moved from AWSDKConsumer to have AWSDKProvider and AWSDKProviderSearchResult include gender.

 @since 4.1.0
 */
@property (nonatomic, readonly) AWSDKBiologicalSex gender;

/**
 NSString with a localized value describing the gender of the AWSDKUser

 @since 4.1.1
 */
@property (nonatomic, readonly, nullable) NSString *localizedGenderName;

@end
