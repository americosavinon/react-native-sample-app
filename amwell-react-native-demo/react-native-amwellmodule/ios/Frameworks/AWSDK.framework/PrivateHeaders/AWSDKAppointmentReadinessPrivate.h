//
//  AWSDKAppointmentReadinessPrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 8/9/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKAppointmentReadiness.h>

/**
 Describes the consumer's readiness state for an upcoming visit. Also allows you to communicate the readiness to the American Well telehealth platform.

 @since 3.1.0
 */
@interface AWSDKAppointmentReadiness : AWSDKDataObject <AWSDKAppointmentReadiness>

/**
 The encryptedID of the engagement that the appointmentreadiness will reference

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *engagementID;

@property (nonatomic, readwrite, nullable) NSString *consumerAuthKey;

@end
