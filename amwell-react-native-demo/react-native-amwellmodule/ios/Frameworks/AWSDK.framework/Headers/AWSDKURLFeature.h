//
//  AWSDKURLFeature.h
//  AWSDK
//
//  Created by Calvin Chestnut on 4/28/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

/**
 NS_ENUM representing features that are supported by a launch URL.

 @since 1.0.0
 */
typedef NS_ENUM(NSUInteger, AWSDKURLFeature) {
    /**
     URL has a link to an appointment. See [AWSDKConsumer appointmentFromUrl:withCompletion:]

     @since 1.0.0
     */
    AWSDKFeatureAppointment,
    /**
     URL has a link to a visit that a guest may join. See [AWSDKAuthenticationService authenticateGuestWithURL:email:name:delegate:completion:]

     @since 1.0.0
     */
    AWSDKFeatureGuestInvite,
    /**
     The URL is not valid for any AWSDK features.

     @since 1.0.0
     */
    AWSDKFeatureNone,
};
