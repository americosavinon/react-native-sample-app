//
//  AWSDKPracticeSearchResult.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/30/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 A result protocol of a practice search.

 @discussion This preview contains basic information about a practice. Use fetchPracticeDetails: to fetch the details of the practice.

 @since 3.1.0
 */
@protocol AWSDKPracticeSearchResult <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the display name of the practice.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *practiceName;

/**
 UIImage representing the practice's logo.

 @discussion This will be _nil_ until the method fetchPracticeLogo: has been called.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) UIImage *logo;

/**
 NSURL pointing to the location of the logo image.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSURL *logoUrl;

/**
 UIImage representing the practice's small logo.

 @discussion The small logo is a reduced version of the AWSDKPractice.logo property.

 @note This will be _nil_ until the fetchPracticeSmallLogo: method has been called.

 @since 3.0.0
 */
@property (nonatomic, readonly, nullable) UIImage *smallLogo;

/**
 UIImage representing the practice's card image.

 @discussion This will be _nil_ until the method fetchPracticeCardOverlay: has been called.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) UIImage *cardOverlay;

/**
 NSURL pointing to the location of the small logo image.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSURL *smallLogoUrl;

/**
 Boolean indicating if the practice has a logo available.

 @discussion    This should be checked before making a call to fetchPracticeLogo: to determine if there is
 a logo to retrieve.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) BOOL hasLogo;

/**
 Boolean indicating if the practice has a small logo available.

 @discussion    This should be checked before making a call to fetchPracticeSmallLogo: to determine if there is
 a small logo to retrieve.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) BOOL hasSmallLogo;

/**
 Boolean indicating if the practice has a card image available.

 @discussion    This should be checked before making a call to fetchPracticeCardOverlay: to determine if there is
 a card image to retrieve.

 @since 4.1.0
 */
@property (assign, nonatomic, readonly) BOOL hasCardOverlay;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the logo for the practice.

 @param completion GenericCompletionBlock containing _TRUE_ if logo was successfully populated, otherwise _FALSE_ and an NSError if there is a network issue or if the practice doesn't have a logo.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage  No image for practice

 @since 1.0.0
 */
- (void)fetchPracticeLogo:(nullable GenericCompletionBlock)completion;

/**
 Fetches the small logo for the practice.

 @param completion GenericCompletionBlock containing _TRUE_ if small logo was successfully populated, otherwise _FALSE_ and an NSError if the practice has no small logo or any other failures.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage   No image for practice

 @since 3.0.0
 */
- (void)fetchPracticeSmallLogo:(nullable GenericCompletionBlock)completion;

/**
 Fetches details about the Practice

 @param completion PracticeCompletionBlock containing the AWSDKPractice object, otherwise an NSError if there are any problems.

 @since 1.0.0
 */
- (void)fetchPracticeDetails:(nullable PracticeCompletionBlock)completion;

/**
 Fetches the card image for the practice.

 @param completion GenericCompletionBlock containing _TRUE_ if logo was successfully populated, otherwise _FALSE_ and an NSError if there is a network issue or if the practice doesn't have a card
 image.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage  No card image for practice

 @since 4.1.0
 */
- (void)fetchPracticeCardOverlay:(nullable GenericCompletionBlock)completion;

@end
