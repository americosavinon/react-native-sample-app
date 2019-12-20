//
//  AWSDKBiologicalSex.h
//  AWSDK
//
//  Created by Stephen Ciauri on 3/08/19.
//  Copyright © 2019 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#ifndef AWSDKBiologicalSex_h
#define AWSDKBiologicalSex_h

#import <Foundation/Foundation.h>

/**
 This enumerated type is used to represent the biological sex of an individual.

 - AWSDKBiologicalSexNotSet: The biological sex has not been set
 - AWSDKBiologicalSexFemale: Represents the female sex
 - AWSDKBiologicalSexMale: Represents the male sex
 - AWSDKBiologicalSexOther: Represents an intersex

 @since 4.2.5
 */
typedef NS_ENUM(NSInteger, AWSDKBiologicalSex) {
    /**
     The biological sex has not been set

     @since 4.2.5
     */
    AWSDKBiologicalSexNotSet = 0,
    /**
     Represents the female sex

     @since 4.2.5
     */
    AWSDKBiologicalSexFemale,
    /**
     Represents the male sex

     @since 4.2.5
     */
    AWSDKBiologicalSexMale,
    /**
     Represents an intersex

     @since 4.2.5
     */
    AWSDKBiologicalSexOther,
};

#endif /* AWSDKBiologicalSex_h */
