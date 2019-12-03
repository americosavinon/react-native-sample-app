//
//  AWSDKCreditCardType.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/7/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A type of credit card protocol.

 @since 3.1.0
 */
@protocol AWSDKCreditCardType <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString displayable name of the credit card type.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *displayName;

/**
 int length of a valid cvv code for this type.

 @since 1.0.0
 */
@property (readonly) int cvvLength;

@end

/**
 A type of credit card.

 @since 1.0.0
 */
@interface AWSDKCreditCardType : AWSDKDataObject <AWSDKCreditCardType>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Determines and returns the type of credit card given a credit card number.

 @param cardNumber  NSString unformatted credit card mumber.

 @return instance of AWSDKCreditCardType that matches the given number, otherwise _nil_ if no match was found.

 @since 1.0.0
 */
+ (nullable instancetype)creditCardTypeForNumber:(nonnull NSString *)cardNumber;
@end
