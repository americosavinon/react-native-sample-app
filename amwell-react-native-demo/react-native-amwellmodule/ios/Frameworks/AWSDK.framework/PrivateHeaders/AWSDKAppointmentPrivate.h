//
//  AWSDKAppointmentPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/11/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKAppointment.h>

@class AWSDKConsumer;

/**
 An appointment in the telehealth platform.

 @since 1.0.0
 */
@interface AWSDKAppointment ()

+ (nonnull NSArray *)appointmentsFromArray:(nonnull NSArray *)array credentialHolder:(nonnull AWSDKConsumer *)credentialHolder;

+ (AWSDKAppointmentStatus)statusForString:(nonnull NSString *)string;

/**
 Attempts to cancel the selected appointment

 @param completion GenericCompletionBlock returns a boolean value indicating success and an NSError explaining any failures

 @since 1.0.0
 */
- (void)cancelAppointmentWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)updateConsumer:(nonnull AWSDKConsumer *)consumer;

- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict credentialHolder:(nonnull AWSDKConsumer *)credentialHolder;

@end
