//
//  AWSDKPlatformType.h
//  AWSDK
//
//  Created by Rolin Nelson on 12/6/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <Foundation/Foundation.h>

/**
 Platform Name Enum representing the available platform types for the engagement.

 @since 5.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKPlatformTypeID) {
    /**
     An Android-capable device is being used as the platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDUnknown = -1,

    /**
     An Android-capable device is being used as the platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDAndroid,

    /**
     The user is utilizing a web browser as their platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDWebBrowser,

    /**
     The user is utilizing IVR as their platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDIVR,

    /**
     The user is utilizing a kiosk as their platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDWebKiosk,

    /**
     The user is utilizing an Apple iOS device as their platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDiOS,

    /**
     The user is utilizing a third party web sdk as their platform for the engagement.

     @since 5.0.0
    */
    AWSDKPlatformTypeIDWebSdk,

    /**
     The user is utilizing the Telehealth Video Client as their platform for the engagement.

     @since 5.0.0
     */
    AWSDKPlatformTypeIDTelehealthVideoClient,
};

/**
 The platform type.  After initialization of the SDK, a array of this object is returned in the platformType array in AWSDKService object.

 @since 4.3.0
 */

@protocol AWSDKPlatformType

/**
 The AWSDKPlatformTypeID of the platform.

 @since 5.0.0
 */
@property (nonatomic, readonly) AWSDKPlatformTypeID type;

/**
 The NSString localized display name of the platform.

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSString *localizedDisplayName;

@end
