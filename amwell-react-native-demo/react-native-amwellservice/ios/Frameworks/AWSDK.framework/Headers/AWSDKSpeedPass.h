//
//  AWSDKSpeedPass.h
//  AWSDK
//
//  Created by Stephen Ciauri on 5/16/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//
#import <AWSDK/AWCoreVisitEndReason.h>
#import <AWSDK/AWSDKVisit.h>
#import <Foundation/Foundation.h>

/**
 This object allows you to re-use previously entered visit details in a subsequent eligible visit

 @since 4.1.0
 */

@protocol AWSDKSpeedPass

/**
 The AWSDKProvider the consumer worked with during the previous visit.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProvider> previousProvider;

/**
 The AWSDKConsumer from the previous visit.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> previousConsumer;

/**
 The AWSDKProvider the SpeedPass was created for.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKProvider> selectedProvider;

/**
 The AWSDKOnDemandSpecialty the SpeedPass was created for.

 @since 4.1.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKOnDemandSpecialty> specialty;

/**
 The AWSDKVisitStatus of the previous visit.

 @since 4.1.0
 */
@property (nonatomic, readonly) AWSDKVisitDisposition visitDisposition;

/**
 AWCoreVisitEndReason representing the reason why the previous visit ended.

 @since 4.1.0
 */
@property (nonatomic, assign, readonly) AWCoreVisitEndReason visitEndReason;

@end
