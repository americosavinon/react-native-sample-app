//
//  NSError+AWSDKErrorPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 1/13/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//
#import <AWSDK/AWSDKErrorCode.h>
#import <AWSDK/NSError+AWSDKError.h>

@interface NSError (AWSDKError)

#pragma mark - Error Init
/**
 @name Creating Errors
 */

/**
 Creates a new instance of an NSError with an for the AWSDKErrorDomainSDK with an AWSDKErrorCode, description, reason, and recovery option.

 @param code        AWSDKErrorCode specifying the error type.
 @param description NSString containing a short description for the error.
 @param reason      NSString explaining why the error occured.
 @param suggestion  NSString offering a suggested handling of the error.
 @return NSError instance.

 @since 3.0.0
*/
+ (NSError *)sdkErrorWithCode:(AWSDKErrorCode)code description:(NSString *)description reason:(NSString *)reason recoverySuggestion:(NSString *)suggestion;

/**
 Creates a new instance of an NSError with an for the AWSDKErrorDomainNetwork with an AWSDKErrorCode, description, reason, and recovery option.

 @param code        AWSDKErrorCode specifying the error type.
 @param description NSString containing a short description for the error.
 @param reason      NSString explaining why the error occured.
 @param suggestion  NSString offering a suggested handling of the error.
 @return NSError instance.

 @since 3.0.0
 */
+ (NSError *)networkErrorWithCode:(AWSDKErrorCode)code description:(NSString *)description reason:(NSString *)reason recoverySuggestion:(NSString *)suggestion;

/**
 Creates a new instance of an NSError with an for the AWSDKErrorDomainUnknown with an AWSDKErrorCode, description, reason, and recovery option.

 @param code        AWSDKErrorCode specifying the error type.
 @param description NSString containing a short description for the error.
 @param reason      NSString explaining why the error occured.
 @param suggestion  NSString offering a suggested handling of the error.
 @return NSError instance.

 @since 3.0.0
 */
+ (NSError *)unknownErrorWithCode:(AWSDKErrorCode)code description:(NSString *)description reason:(NSString *)reason recoverySuggestion:(NSString *)suggestion;

/**
 Creates a new instance of an NSError with an AWSDKErrorCode, a provided domain, description, reason, and recovery option.

 @param code        AWSDKErrorCode specifying the error type.
 @param domain      NSErrorDomain containing the AWSDKErrorDomain such as AWSDKErrorDomainServer.
 @param description NSString containing a short description for the error.
 @param reason      NSString explaining why the error occured.
 @param suggestion  NSString offering a suggested handling of the error.
 @return NSError instance.

 @since 3.0.0
 */
+ (NSError *)errorWithCode:(AWSDKErrorCode)code domain:(NSErrorDomain)domain description:(NSString *)description reason:(NSString *)reason recoverySuggestion:(NSString *)suggestion;

/**
 Creates a new instance of an NSError with an AWSDKErrorCode, a provided domain, description, reason, and recovery option.

 @param code        AWSDKErrorCode specifying the error type.
 @param domain      NSErrorDomain containing the AWSDKErrorDomain such as AWSDKErrorDomainServer.
 @param description NSString containing a short description for the error.
 @param reason      NSString explaining why the error occured.
 @param suggestion  NSString offering a suggested handling of the error.
 @param dictionary  NSDictionary representing the field by field errors where the key is the property or parameter and the value is the error code.
 @return NSError instance.

 @since 3.0.0
 */
+ (NSError *)errorWithCode:(AWSDKErrorCode)code
                    domain:(NSErrorDomain)domain
               description:(NSString *)description
                    reason:(NSString *)reason
        recoverySuggestion:(NSString *)suggestion
           errorDictionary:(NSDictionary *)dictionary;

#pragma mark - Helpers
/**
 @name Helpers
 */

/**
 Returns the AWSDKErrorCode that maps to the American Well Telehealth Platform error string returned from the server. If
 no match is found AWSDKErrorCodeUnknownFailure will be returned.

 @param caretalksError The error code string returned from the server.

 @return AWSDKErrorCode

 @since 3.0.0
 */
+ (AWSDKErrorCode)errorCodeWithCareTalksError:(NSString *)caretalksError;

/**
 Turns a server response body into a userInfo dictionary to be used with an NSError object.

 @param dict The response body returned from the server
 @param errorString The error string returned from the server

 @return NSDictionary

 @since 3.0.0
 */
+ (NSDictionary *)caretalksUserInfoWithResponseBody:(NSDictionary *)dict andErrorString:(NSString *)errorString;

@end
