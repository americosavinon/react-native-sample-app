//
//  AWSDKLocalePrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 11/30/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKLocale.h>

@interface AWSDKLocale ()

/**
 The backing store for the preferred locale.
 */
@property (nonatomic, nullable) NSLocale *preferredLocale;

/**
 Returns the shared instance singleton.
 */
+ (nullable instancetype)sharedInstance;

/**
 Instantiate the AWSDKLocale singleton to a new instance.
 */
- (void)clear;

/**
 Sets the preferred locale.

 @param locale the NSLocale to set locale to.
  @return BOOL set _TRUE_ if the system configuration supports this locale, otherwise _FALSE_.
 */
+ (BOOL)setPreferredLocale:(nullable NSLocale *)locale;

/**
 Checks if the locale is supported by the American Well Platform.

 @param locale the NSLocale to check.
 @return true if the locale is supported, false if the locale is not supported.
 */
+ (BOOL)isSupportedLocale:(nullable NSLocale *)locale;

/**
 Private initializer used to create a new AWSDKService instance

 @return The new AWSDKService instance
 */
- (nullable instancetype)initPrivate;

@end
