//
//  AWSDKPharmacyPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/20/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKPharmacy.h>

/**
 A pharmacy to handle prescriptions prescribed by a provider.

 @since 1.0.0
 */
@interface AWSDKPharmacy : AWSDKDataObject <AWSDKPharmacy>

+ (NSArray *)pharmaciesFromArray:(NSArray *)array useDistance:(BOOL)useDistance;

@end
