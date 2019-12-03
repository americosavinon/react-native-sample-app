//
//  AWSDKPaymentMethod.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/3/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKAddress;

/**
 A consumer's credit card payment method protocol.

 @since 3.1.0
 */
@protocol AWSDKPaymentMethod <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKAddress representing the billing address for the payment method.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKAddress> billingAddress;

/**
 NSString representing the cardholder's name as it appears on the credit card.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *billingName;

/**
 NSString representing the last four digits of the credit card number.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *lastFourDigits;

/**
 NSString representing the credit card type such as "Visa".

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *cardType;

/**
 BOOL representing if the credit card is expired or not.

 @since 3.1.0
 */
@property (nonatomic, readonly) BOOL isExpired;

/**
The credit card expiration month.

 @since 4.0.0
 */
@property (nonatomic, readonly) NSInteger expirationMonth;

/**
 The credit card expiration year.

 @since 4.0.0
 */
@property (nonatomic, readonly) NSInteger expirationYear;

@end
