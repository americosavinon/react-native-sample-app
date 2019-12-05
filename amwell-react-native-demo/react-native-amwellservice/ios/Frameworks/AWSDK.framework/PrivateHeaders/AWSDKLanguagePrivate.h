//
//  AWSDKLanguagePrivate.h
//  AWSDK
//
//  Created by Steven Uy on 7/14/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKLanguage.h>

/**
 A provider spoken language in the Telehealth system.

 @since 2.0.0
 */
@interface AWSDKLanguage : AWSDKDataObject <AWSDKLanguage>

+ (nonnull NSArray *)languagesFromArray:(nonnull NSArray *)array;

@property (nonatomic, readonly, nonnull) NSString *resourceKey;

@end
