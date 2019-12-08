//  AWSDKAppointmentReadinessOverrides.h
//  AWSDK
//
//  Created by Ed Chianese on 11/16/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//
#import "AWSDKAppointmentReadiness.h"

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <Foundation/Foundation.h>

/**
 Helper class that is used to modify the consumer's readiness state on the American Well telehealth platform.

 @since 4.3.0
 */
@interface AWSDKAppointmentReadinessOverrides : NSObject
/**
 Indicates whether or not the consumer has passed the tech check step of the appointment readiness workflow.

 @discussion When enabled, the tech check ensures that the user has the necessary hardware to participate in a video visit.

 @since 4.3.0
 */
@property (nonatomic, readwrite) BOOL techCheckPassed;

/**
 Indicates whether or not the microphone passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readwrite) BOOL microphonePassed;

/**
 Indicates whether or not the camera passed the tech check.

 @since 4.3.0
 */
@property (nonatomic, readwrite) BOOL cameraPassed;

/**
 Indicates whether or not the speaker passed the tech check.

 @discussion Since iOS doesn't require permissions to access the device's speakers, this value defaults to YES.

 @since 5.0.0
 */
@property (nonatomic, readwrite) BOOL speakerPassed;

/**
 The name of the microphone that's being checked for availability during a telehealth visit.

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *microphoneDeviceName;

/**
 The name of the camera that's being checked for availability during a telehealth visit.

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *cameraDeviceName;

/**
 The name of the speaker that's being checked for availability during a telehealth visit.

 @since 5.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *speakerDeviceName;

/**
 An application supplied string.

 @discussion The sourceId is a user specified string that can be associated with the appointment readiness object. For example, it could be assigned a unique id that identifies the client
 device.

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *sourceId;

@end
