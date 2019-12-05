//
//  AWSDKLocale.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 The locale on the SDK system.

 @discussion Represents the locale to be used system wide.

 @since 4.0.0
 */
@protocol AWSDKLocale <AWSDKDataObject>

/**
 The preferred locale used when formatting dates and making server requests to the American Well telehealth platform.

 @since 4.0.0
 */
@property (class, nonatomic, readonly, nullable) NSLocale *preferredLocale;

/**
 Updates the SDK preferred locale for display strings to be shown in the expected language.

 @discussion The locale must be a locale supported by the American Well telehealth platform.

 @param locale     NSLocale representing the desired locale for the SDK.
 @return  _TRUE_ if the SDK supports the locale and sets it successfully, otherwise _FALSE_.

 @since 4.0.0
 */
+ (BOOL)setPreferredLocale:(nullable NSLocale *)locale;

/**
 Indicates if the locale is supported by the American Well telehealth platform.

 @param locale The locale to validate against the American Well telehealth platform's supported locales

 @return _TRUE_ if the locale is supported, otherwise _FALSE_ if not supported.

 @since 4.0.0
 */
+ (BOOL)isSupportedLocale:(nullable NSLocale *)locale;

/**
 The current language code on the user's device.

 @return the 2-character language code of the user's current locale.

 @since 4.0.0
 */
+ (nonnull NSString *)currentLanguageCode;

/**
 Adjust the font size by percentage for the device language specified by the languageCode.

 @param defaultFont The base font to adjust.
 @param languageCode The language code the adjustment is active for.
 @param percent The percentage to increase or decrease the font by.
 @return The adjusted or the orignal font.
 */
+ (nonnull UIFont *)adjustFont:(nonnull UIFont *)defaultFont languageCode:(nonnull NSString *)languageCode percent:(double)percent;

/**
 Adjust the font size by percentage for the device language specified by the languageCode.

 @param defaultFont The base font to adjust.
 @param languageCode The language code the adjustment is active for.
 @param percent The percentage to increase or decrease the font by.
 @param fontSize The base font to increase or decrease from.
 @return The adjusted or the orignal font.
 */
+ (nonnull UIFont *)adjustFont:(nonnull UIFont *)defaultFont languageCode:(nonnull NSString *)languageCode percent:(double)percent fontSize:(CGFloat)fontSize;

/**
 Detects the language in the input text.

 @param text The text to detect the language of.
 @return The language code of the detected language.
 */
+ (nonnull NSString *)languageForString:(nonnull NSString *)text;

@end

@interface AWSDKLocale : AWSDKDataObject <AWSDKLocale>

@end
