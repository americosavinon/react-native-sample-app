//
//  AWSDKForm.h
//  AWSDK
//
//  Created by Steven Uy on 8/8/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 Form protocol containing parameters with field by field validation. Commonly used in setting or update methods.

 @since 3.1.1
 */
@protocol AWSDKForm

#pragma mark - Validation
/**
 @name Validation
 */

/**
 Validates the form's data and returns a _TRUE_ if valid, _FALSE_ otherwise and an NSError with a mapping of invalid parameters.

 @param error Populates the error with NSError if not valid, refer to userInfo for details.

 @return _TRUE_ if valid, _FALSE_ otherwise.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidData                                   Data is Invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.
 @exception AWSDKErrorCodeValidationRequiredParameterTooShort           Value is too short.
 @exception AWSDKErrorCodeTooLarge                                      Value is too long.
 @exception AWSDKErrorCodeDateTooEarly                                  Required parameter is too early in time.
 @exception AWSDKErrorCodeDateTooLate                                   Required parameter is too late in time.
 @exception AWSDKErrorCodeInvalidEmail                                  Email address is invalid.

 @since 2.0.0
 */
- (BOOL)isValid:(NSError *_Nullable *_Nullable)error;

/**
 Convenience method to validate the form's data.

 @discussion This calls isValid: with nil error;

 @return _TRUE_ if valid, _FALSE otherwise.

 @since 2.0.0
 */
- (BOOL)isValid;
@end

/**
 Form containing parameters with field by field validation. Commonly used in setting or update methods.

 @since 2.0.0
 */
@interface AWSDKForm : NSObject <AWSDKForm>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Method used to create a new instance of AWSDKForm.

 @return AWSDKForm instance.

 @since 2.0.0
 */
+ (nonnull instancetype)form;
@end
