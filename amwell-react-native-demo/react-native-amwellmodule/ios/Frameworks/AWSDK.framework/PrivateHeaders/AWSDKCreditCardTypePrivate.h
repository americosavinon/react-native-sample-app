//
//  AWSDKCreditCardTypePrivate.h
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

#import <AWSDK/AWSDKCreditCardType.h>

@interface AWSDKCreditCardType ()

+ (NSArray *)arrayFromArray:(NSArray *)array;

+ (instancetype)creditCardTypeFromString:(NSString *)typeString;

@property (nonatomic) NSString *type;

@property (nonatomic) NSString *validationRegex;

@end
