//
//  AWSDKAddress.h
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

// clang-format off
@protocol AWSDKState, AWSDKCountry;
// clang-format on

/**
 A physical "address" protocol.

 @since 3.1.0
 */
@protocol AWSDKAddress <AWSDKDataObject>

#pragma mark - Required Read-Write Properties
/**
 @name Required Read-Write Properties
 */

/**
 NSString representing the first line of street "address".

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *addressOne;

/**
 NSString representing the city name.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *city;

/**
 AWSDKState the "address" is physically in.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKState> state;

/**
 AWSDKCountry the address resides in.

 @since 4.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKCountry> country;

/**
 NSString unformatted postal zip code for the "address".

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *zip;

#pragma mark - Optional Properties
/**
 @name Optional Properties
 */

/**
 NSString representing second line of street "address", commonly used for floor or unit of a building.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *addressTwo;

#pragma mark - Helper Methods
/**
 @name Helper Methods
 */

/**
 Helper method that uses the native CNPostalAddressFormatter to produce a localized representation of the AWSDKAddress

 @return NSString formatted as follows:
 `Address1
 Address2
 City StateCode Zip`
 otherwise _nil_ if the "address" is invalid.

 @since 1.0.0
 */
- (nullable NSString *)displayString;

@end

/**
 A physical "address".

 @since 1.0.0
 */
@interface AWSDKAddress : AWSDKDataObject <AWSDKAddress>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKAddress.

 @return A new AWSDKAddress instance.

 @since 1.0.0
 */
+ (nonnull instancetype)address;
@end
