//
//  AWSDKPaymentMethodForm.h
//  AWSDK
//
//  Created by Calvin Chestnut on 8/9/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKCreditCardType.h"

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKForm.h>

// clang-format off
@protocol AWSDKAddress, AWSDKCreditCardType;
// clang-format on

/**
 AWSDKForm for updating a consumer's payment method.

 @note As of 3.1.0, AWSDKNewPaymentMethod was renamed to AWSDKPaymentMethodForm to inherit from AWSDKForm.

 @since 3.1.0
 */
@protocol AWSDKPaymentMethodForm <AWSDKForm>

#pragma mark - Required Read-Write Properties
/**
 @name Required Read-Write Properties
 */

/**
 AWSDKCreditCardType representing the credit card type.

 @since 2.0.0
 */
@property (nonatomic, nonnull, readwrite) id<AWSDKCreditCardType> cardType;

/**
 AWSDKAddress representing the billing address associated with the payment method.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKAddress> billingAddress;

/**
 NSString representing the unformatted account number on the card.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *cardNumber;

/**
 NSString representing the name of the cardholder as it appears on the card.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *billingName;

/**
 NSString representing the CVV security code, usually found on the back of the card.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *cvvCode;

/**
 NSString representing the expiration month of the credit card as a one or two digit number.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *expMonth;

/**
 NSString representing the expiration year of the card as a four digit number.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *expYear;

/**
 NSArray of AWSDKCreditCardType objects supported by the telehealth platform
@since 4.0
 */
@property (class, nonatomic, nonnull, readonly) NSArray<id<AWSDKCreditCardType>> *creditCardTypes;

#pragma mark - Methods
/**
 @name Methods
 */

@end

/**
 AWSDKForm for updating a consumer's payment method.

 @note As of 2.0.0, AWSDKNewPaymentMethod was renamed to AWSDKPaymentMethodForm to inherit from AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKPaymentMethodForm : AWSDKForm <AWSDKPaymentMethodForm>
@end
