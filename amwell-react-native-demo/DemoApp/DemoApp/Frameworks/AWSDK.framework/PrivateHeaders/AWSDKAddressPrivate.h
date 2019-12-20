//
//  AWSDKAddressPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/14/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKAddress.h>

@interface AWSDKAddress ()

#pragma mark - Validation Methods
/**
 @name Validation Methods
 */

/**
 Validates an address.

 @param address The AWSDKAddress object to validate.

 @return _nil_ if the AWSDKAddress is valid; otherwise return an NSDictionary with the name of invalid AWSDKAddress properties as keys, and the corresponding AWSDKErrorCode(s) as values, expressed as
 NSNumber(s). Validation is performed on the street address, city, state, and zip.

 The possible error codes are:
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.


 @since 1.0.0
 */
+ (nullable id)validateAddress:(nullable AWSDKAddress *)address;

@end
