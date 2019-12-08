//
//  AWSDKContactPrivate.h
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

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKContact.h>

@class AWSDKConsumer;

/**
 A contact of a consumer.

 @since 1.0.0
 */
@interface AWSDKContact : AWSDKDataObject <AWSDKContact>

@property (nonatomic, nonnull) AWSDKConsumer *consumer;

@property (nonatomic, nullable) NSPersonNameComponents *nameComponents;

/**
 True if the contact accepts secure messages set in the account configuration,
 Note, not populated in every case

 @since 1.0.0
 */
@property BOOL isAcceptingSecureMessages;

+ (nonnull NSArray *)contactsFromArray:(nonnull NSArray *)array filtered:(BOOL)filtered;

@end
