//
//  AWSDKLaunchParamKeys.h
//  AWSDK
//
//  Created by Calvin Chestnut on 5/4/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#pragma mark - Launch Params Keys
/**
 @name Launch Params Keys
 */

/**
 Key to store the Base URL of the installation's server. e.g. https://www.amwell.com

 @note Value is required when calling [AWSDKService initializeWithLaunchParams:completion:] .

 @since 1.0.0
 */
static NSString *_Nonnull const kAWSDKUrl = @"AWSDKUrl";

/**
 Key to store the SDK key used to authenticate the SDK.

 @note Value is required when calling [AWSDKService initializeWithLaunchParams:completion:] .

 @since 1.0.0
 */
static NSString *_Nonnull const kAWSDKKey = @"AWSDKKey";

/**
 Key to store the BundleID of your application.

 @note Value is required when calling [AWSDKService initializeWithLaunchParams:completion:] .

 @since 1.0.0
 */
static NSString *_Nonnull const kAWSDKBundleID = @"AWSDKBundleId";

/**
 Key to store the url that the Application was launched with.

 @since 2.0.0
 */
static NSString *_Nonnull const kAWSDKLaunchURL = @"AWSDKLaunchURL";

/**
 Key to store the UUIDString NSString used for remote debugging.

 @note The use of this key is optional. If you do not provide one here, the AWSDK will create one at runtime that will last the lifetime of the application. The application will crash at runtime if
 you provide a string that cannot construct a NSUUID. It is recommended that you construct an NSUUID yourself, and then pass the `uuid.uuidString` into the launchParams dictionary.

 @since 5.0.0
 */
static NSString *_Nonnull const kAWSDKSupportabilityUUID = @"AWSDKSupportabilityUUID";
