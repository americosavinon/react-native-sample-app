//
//  AWSDKAppointmentReadiness.h
//  AWSDK
//
//  Created by Stephen Ciauri on 6/19/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKAppointment.h>
#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <Foundation/Foundation.h>

@class AWSDKAppointmentReadinessOverrides;

/**
 Protocol describing the consumer's readiness state for an upcoming visit. Also allows you to communicate the readiness to the American Well telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKAppointmentReadiness <AWSDKDataObject>
/**
 Describes whether or not the consumer is already fully registered in the American Well telehealth platform.

 @since 3.1.0
 */
@property (nonatomic, readonly) BOOL enrolled;

/**
 Describes the status of the techCheck requirement on the American Well telehealth platform.

 @since 3.1.0
 */
@property (nonatomic, readonly) BOOL techCheckEnabled;

/**
 Indicates whether or not the consumer has passed the 'tech check' step of the appointment readiness workflow.

 @discussion When enabled, the tech check ensures that the user has the necessary hardware to participate in a video visit. On mobile devices, this usually comprises the presence of a front-facing
 camera and the user allowing the application access to both the camera and the microphone.

 @since 3.1.0
 */
@property (nonatomic, readonly) BOOL techCheckPassed;

/**
 Describes if a consumer has completed all prerequisite tasks for their upcoming visit.

 @since 3.1.0
 */
@property (nonatomic, readonly) BOOL readyForAppointment;

/**
The date the consumer's device passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSDate *datePassedTechCheck;

/**
 The delay in milliseconds before data is received as measured by Ookla / Speedtest.

 @since 4.3.0
 */
@property (nonatomic, readonly) NSInteger latencyMs;

/**
 Variation in the latency in milliseconds as measured with Ookla / Speedtest.

 @since 4.3.0
 */
@property (nonatomic, readonly) NSInteger jitter;

/**
 The download speed measured in megabits per second as measured by Ookla / Speedtest.

 @since 4.3.0
 */
@property (nonatomic, readonly) double downloadSpeedMbps;

/**
 The upload speed measured in megabits per second as measured by Ookla / Speedtest.

 @since 4.3.0
 */
@property (nonatomic, readonly) double uploadSpeedMbps;

/**
Describes if the microphone passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readonly) BOOL microphonePassed;

/**
Describes if the speaker passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readonly) BOOL speakerPassed;

/**
Describes if the camera passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readonly) BOOL cameraPassed;

/**
The name for the microphone that's being checked for availability during a telehealth visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *microphoneDeviceName;

/**
The name of the speaker that's being checked for availability during a telehealth visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *speakerDeviceName;

/**
The name of the camera that's being checked for availability during a telehealth visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *cameraDeviceName;

/**
 NSString representing the sourceId.

 @discussion The sourceId is an arbitrary user specified string that can be associated with the appointment readiness object. For example, it could be assigned a unique id that identifies the client
 device.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *sourceId;

/**
 AWSDKPlatformType representing the platform type.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKPlatformType> platformType;

/**
 NSString representing the platform version.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *platformVersion;

/**
 Returns a mutable object initialized with the current appointment readiness properties.

 @since 4.3.0

 @discussion The returned AWSDKAppointmentReadinessOverrides object is a container for mutable appointment readiness properties.
 */
- (nonnull AWSDKAppointmentReadinessOverrides *)getAppointmentReadinessOverride;

/**
 Informs the American Well telehealth platform of the consumer's readiness state.

 @since 3.1.0

 @discussion If an appointment is not given and the consumer has an outstanding appointment, the outstanding appointment's readiness state will be unaffected.

 @param isComplete _YES_ if the consumer has completed the prerequisite checks, _NO_ otherwise.
 @param appointment An optional appointment object that will be used to update the appointment readiness status for the given appointment.
 @param completion Executed when the network call is complete.
 */
- (void)updateAppointmentReadinessWithStatus:(BOOL)isComplete appointment:(nullable id<AWSDKAppointment>)appointment completion:(nonnull GenericCompletionBlock)completion;

/**
 Updates the American Well telehealth platform's consumer readiness state

 @since 4.3.0

 @discussion The pattern of use is to request an AWSDKAppointmentReadinessOverrides object, modify the desired properties and persist the changes to the American Well Telehealth Platform with
 updateAppointmentReadinessWithOverrides.

 @param overrideObj is a container for readiness properties that are mutable
 @param completion Executed when the network call is complete.
 */
- (void)updateAppointmentReadinessWithOverrides:(nonnull AWSDKAppointmentReadinessOverrides *)overrideObj completion:(nullable GenericCompletionBlock)completion;

@end
