//
//  AWSDKAppointmentRecordForm.h
//  AWSDK
//
//  Created by Rolin Nelson on 11/20/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKForm.h>

/**
 Object to request appointment updates.

 @since 4.3.0
 */
@protocol AWSDKAppointmentRecordForm <AWSDKForm>

/**
 NSLocale representing the locale of the appointment.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSLocale *locale;

/**
 NSString representing the initiator override phone number.

 @since 4.3.0
 */
@property (nonatomic, nonnull, readwrite) NSString *initiatorOverridePhoneNumber;

@end

/**
 Class used for updating a consumer's or dependent's appointment.

 @since 4.3.0
 */
@interface AWSDKAppointmentRecordForm : AWSDKForm <AWSDKAppointmentRecordForm>
#pragma mark - Appledoc
@property (nonatomic, nonnull, readwrite) NSLocale *locale;
@property (nonatomic, nonnull, readwrite) NSString *initiatorOverridePhoneNumber;

#pragma mark -
@end
