//
//  AWSDKModalityCode.h
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
 The modality code enum representing the available communication mode for the visit.

 @since 5.0.0
 */
typedef NS_ENUM(NSUInteger, AWSDKModalityCode) {
    /**
     An unknown communication mode.

     @since 4.3.0
     */
    AWSDKModalityCodeUndefined,

    /**
     Video communication mode

     @since 4.3.0
     */
    AWSDKModalityCodeVideo,

    /**
     Phone communication mode

     @since 4.3.0
     */
    AWSDKModalityCodePhone,
};
