//
//  AWSDKModality.h
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

#import "AWSDKModalityCode.h"
#import "AWSDKModalityType.h"

#import <Foundation/Foundation.h>

/**
 The modality option (video, phone, both) for a visit communication.  After initialization of the SDK, a array of this object is returned in the availableModilities in AWSDKService object.

 @since 4.3.0
 */

@protocol AWSDKModality

/**
 The AWSDKModalityCode of the communication.

 @since 5.0.0
 */
@property (nonatomic, readonly) AWSDKModalityCode code;

/**
 The NSString localized display name of the modality.

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSString *localizedDisplayName;

@end
