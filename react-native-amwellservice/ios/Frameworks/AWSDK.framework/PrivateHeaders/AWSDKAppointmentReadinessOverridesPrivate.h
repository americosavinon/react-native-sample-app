//
//  AWSDKAppointmentReadinessOverridesPrivate.h
//  AWSDK
//
//  Created by Ed Chianese on 11/20/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#ifndef AWSDKAppointmentReadinessOverridesPrivate_h
#define AWSDKAppointmentReadinessOverridesPrivate_h

#import <AWSDK/AWSDKAppointmentReadinessOverrides.h>
#import <Foundation/Foundation.h>

/**
 Helper class that is used to modify the consumer's readiness state on the American Well telehealth platform.

 @since 4.3.0
 */
@interface AWSDKAppointmentReadinessOverrides ()

// The fields are currently not supported for override from the client side

/**
 Modifiable delay in milliseconds that describes the length of time before data is received in the tech check.

 @since 4.3.0
 */
@property (nonatomic, readonly) NSInteger latencyMs;

/**
 Modifiable jitter value. Jitter is the variation in the latency in milliseconds of ip packets.

 @since 4.3.0
 */
@property (nonatomic, readonly) NSInteger jitter;

/**
 Modifiable upload speed measured in megabits per second.

 @since 4.3.0
 */
@property (nonatomic, readonly) double downloadSpeedMbps;

/**
 Modifiable download speed measured in megabits per second.

 @since 4.3.0
 */
@property (nonatomic, readonly) double uploadSpeedMbps;

/**
 AWSDKPlatformType representing the platform type.

 @since 5.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKPlatformType> platformType;

/**
 NSString representing the platform version.

 @since 5.0.0
 */
@property (nonatomic, readonly, nullable) NSString *platformVersion;

/**
 The encryptedID of the engagement that the appointmentreadiness will reference

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *engagementID;

- (nonnull NSDictionary<NSString *, NSString *> *)toParams;

@end

#endif /* AWSDKAppointmentReadinessOverridesPrivate_h */
