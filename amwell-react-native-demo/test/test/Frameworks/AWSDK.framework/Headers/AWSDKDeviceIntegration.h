//
//  AWSDKDeviceIntegration.h
//  AWSDK
//
//  Created by Stephen Ciauri on 12/10/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

@protocol AWSDKExamData;

/**
 Describes the type of integrated device.

 @since 4.3.0
 */
typedef NS_ENUM(NSUInteger, AWSDKDeviceIntegrationType) {
    /**
     Undefined type

     @since 4.3.0
     */
    AWSDKDeviceIntegrationTypeUndefined,
    /**
     Indicates integration with the Tyto Care device

     @since 4.3.0
     */
    AWSDKDeviceIntegrationTypeTyto,
};

/**
 Describes the pairing status of an AWSDKDeviceIntegration.

 @since 4.3.0
 */
typedef NS_ENUM(NSUInteger, AWSDKDeviceIntegrationPairingStatus) {
    /**
     Status is unknown or understood by the AWSDK

     @since 4.3.0
     */
    AWSDKDeviceIntegrationPairingStatusUnknown,
    /**
     Patient is paired

     @since 4.3.0
     */
    AWSDKDeviceIntegrationPairingStatusPatientPaired,
    /**
     Patient is not paired

     @since 4.3.0
     */
    AWSDKDeviceIntegrationPairingStatusPatientNotPaired,
    /**
     Patient is partially matched with integration server

     @since 4.3.0
     */
    AWSDKDeviceIntegrationPairingStatusPatientPartiallyMatched,
    /**
     Patient record not found in integration server

     @since 4.3.0
     */
    AWSDKDeviceIntegrationPairingStatusPatientNotFound,
};

/**
 Represents a device integration and associated exam data.

 @since 4.3.0
 */
@protocol AWSDKDeviceIntegration

/**
 Array of exam data associated with the device

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKExamData>> *examData;

/**
 An enum representing the type of integration for the AWSDKDeviceIntegration record.

 @since 4.3.0
 */
@property (nonatomic, readonly) AWSDKDeviceIntegrationType integrationType;

@end
