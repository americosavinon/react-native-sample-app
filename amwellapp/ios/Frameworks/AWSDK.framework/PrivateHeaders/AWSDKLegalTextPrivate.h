//
//  AWSDKLegalTextPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 7/28/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKLegalText.h>

/**
 A legal text for a visit. This may be a dislaimer or a different legal type.

 @note As of 2.0.0, AWSDKPrivacyDisclaimer was renamed to AWSDKLegalText.

 @since 2.0.0
 */
@interface AWSDKLegalText : AWSDKDataObject <AWSDKLegalText>
+ (NSArray *)disclaimersFromArray:(NSArray *)array;

@property BOOL accepted;

@end
