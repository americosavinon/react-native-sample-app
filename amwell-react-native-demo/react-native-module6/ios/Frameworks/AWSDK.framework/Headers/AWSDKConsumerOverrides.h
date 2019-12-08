//
//  AWSDKConsumerOverrides.h
//  AWSDK
//
//  Created by Rolin Nelson on 8/28/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKBiologicalSex.h>

// clang-format off
@protocol AWSDKAddress, AWSDKState, AWSDKCountry;
// clang-format on

@class AWSDKAddress, AWSDKUser;

/**
 A class used to override the demographic information of a consumer on a per-visit basis. This is typically used for cart-based visits.

 @since 4.2.0
 */
@interface AWSDKConsumerOverrides : NSObject
#pragma mark - Address
/**
 AWSDKAddress representing the patient's address.

 @note Attempting to update the AWSDKCountry field of AWSDKAddress using the AWSDKConsumerOverrides object will result in a no-op, since cart-based visits do not support overriding the AWSDKCountry
 field.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) AWSDKAddress *address;

#pragma mark - Name & Gender
/**
 NSPersonNameComponents representing the user's name.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) NSPersonNameComponents *nameComponents;

/**
 AWSDKBiologicalSex representing the user's biologial sex.

 @since 4.2.0
 */
@property (nonatomic, readwrite) AWSDKBiologicalSex gender;

/**
 NSString representing the patient's email address.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) NSString *email;

/**
 NSDate representing the consumer's date of birth.

 @note When representing this field in your UI and to avoid off-by-one errors, be sure you are using the UTC time zone. This field is serialized from "milliseconds since epoch" at 00:00:00.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) NSDate *dateOfBirth;

/**
 NSString representing the patient's phone number.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) NSString *phoneNumber;

/**
 NSString representing the patient's medical record number.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nullable) NSString *mrnId;

@end
