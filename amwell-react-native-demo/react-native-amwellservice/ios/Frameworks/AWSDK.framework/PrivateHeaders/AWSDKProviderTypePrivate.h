//
//  AWSDKProviderTypePrivate.h
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

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKProviderType.h>

/**
 A specialty of a provider in the telehealth platform such as 'Family Physician'.

 @since 1.0.0
 */
@interface AWSDKProviderType : AWSDKDataObject <AWSDKProviderType>

@property (nonatomic, readwrite, nonnull) NSString *key;

+ (nonnull NSArray *)typesWithArray:(nonnull NSArray *)types;

+ (nonnull NSArray<NSString *> *)arrayFromTypes:(nonnull NSArray<AWSDKProviderType *> *)providerTypes;

@end
