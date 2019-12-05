//
//  AWSDKModalityType.h
//  AWSDK
//
//  Created by Rolin Nelson on 11/12/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 The modality type enum representing the available communication mode for the visit.

 @since 5.0.0
 */
typedef NS_ENUM(NSUInteger, AWSDKModalityType) {
    /**
     An unknown communication mode.

     @since 5.0.0
     */
    AWSDKModalityTypeUndefined,

    /**
     Outbound Phone communication mode

     @since 5.0.0
     */
    AWSDKModalityTypeOutboundPhone,

    /**
     Vydio Video communication mode

     @since 5.0.0
     */
    AWSDKModalityTypeVidyoVideo,

    /**
     Pexip RTC Video communication mode

     @since 5.0.0
     */
    AWSDKModalityTypePexipRTCVideo,
};
