//
//  AWSDKAppointmentRecordFormPrivate.h
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

#import <AWSDK/AWSDKAppointmentRecordForm.h>

@interface AWSDKAppointmentRecordForm ()
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new blank instance of AWSDKAppointmentRecordForm.

 @return A new AWSDKAppointmentRecordForm instance.

 @since 4.3.0
 */
+ (nonnull instancetype)appointmentRecordForm;

/**
 Creates a dictionary representation of AWSDKAppointmentRecordForm.

 @return A new NSDictionary instance.

 @since 4.3.0
 */
- (nonnull NSDictionary *)toParams;

@end
