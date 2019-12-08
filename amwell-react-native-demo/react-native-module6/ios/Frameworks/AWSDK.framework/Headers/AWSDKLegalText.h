//
//  AWSDKLegalText.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 NS_ENUM representing a legal text type

 @since 2.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKLegalTextType) {
    /**
     Legal

     @since 2.0.0
     */
    TypeLegal = 1,
    /**
     Disclaimer

     @since 2.0.0
     */
    TypeDisclaimer,
    /**
     Legal text pertaining to the practice Specialty type

     @since 3.2.0
     */
    TypeSpecialty
};

/**
 A legal text for a visit. This may be a dislaimer or a different legal type.

 @note As of 2.0.0, AWSDKPrivacyDisclaimer was renamed to AWSDKLegalText.

 @since 2.0.0
 */
@protocol AWSDKLegalText <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing displayable name.

 @since 2.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *name;

/**
 BOOL indicating if the consumer is required to accept this disclaimer before entering the visit.

 @since 2.0.0
 */
@property (nonatomic, readonly) BOOL required;

/**
 AWSDKLegaltextType representing the type of text.

 @since 2.0.0
 */
@property (nonatomic, readonly) AWSDKLegalTextType type;

/**
 NSString that contains the content of the legal text.

 @since 3.0.1
 */
@property (nullable, nonatomic, readonly) NSString *content;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Sets the disclaimer as accepted.

 @since 2.0.0
 */
- (void)setAccepted;

/**
 Fetches the full formatted text of the disclaimer.

 @discussion The formatted text should be displayed in UIWebView to be properly formatted.

 @param completion StringResultCompletionBlock containing the full text of the disclaimer as an NSString with HTML format, otherwise an NSError explaining any errors.

 @since 2.0.0
 */
- (void)fetchLegalText:(nullable StringResultCompletionBlock)completion;

@end
