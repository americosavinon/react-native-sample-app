//
//  AWSDKProviderSearchResult.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/30/15.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKProvider.h>
#import <AWSDK/AWSDKUser.h>

@protocol AWSDKProviderType;

/**
 A result protocol of a provider search.

 @discussion This is a preview containing basic information about a provider. Use fetchDetails: to retrieve the AWSDKProvider object.

 @since 3.1.0
 */
@protocol AWSDKProviderSearchResult <AWSDKUser>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKProviderType representing the provider's specialty.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProviderType> specialty;

/**
 AWSDKMobileAvailability representing the provider's current availability status.

 @since 1.0.0
 */
@property (readonly) AWSDKMobileAvailability availability;

/**
 UIImage representing the provider's display image.

 @note This will be _nil_ until the fetchProviderImage: method has been called.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) UIImage *image;

/**
 Boolean indicating if the provider has an image available.

 @discussion    This should be checked before making a call to fetchProviderImage: to determine if there is
 an image to retrieve.

 @since 3.0.0
 */
@property (readonly) BOOL hasImage;

/**
 NSURL pointing to the location of the provider's image.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSURL *imageUrl;

/**
 NSInteger representing the provider's rating from a scale of 1 to 5.

 @note If 0, the rating has not been set.

 @discussion Rating will be populated despite of [AWSDKSystemConfiguration showProviderRatings] .

 @since 2.0.0
 */
@property (assign, nonatomic, readonly) NSInteger rating;

/**
 NSString representing the unique ID for the provider used to identify their registration source and to search by.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *sourceID;

/**
 NSInteger representing the number of consumers waiting for the provider.

 @note This number is not refreshed unless a new AWSDKProviderSearchResult is fetched

 @since 2.0.0
 */
@property (assign, nonatomic, readonly) NSInteger waitingRoomCount;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Loads details for the provider.

 @param completion ProviderResultCompletionBlock containing the AWSDKProvider, otherwise an NSError explaining any issues that may have occured.

 @since 1.0.0
 */
- (void)fetchDetails:(nullable ProviderResultCompletionBlock)completion;

/**
 Fetches the image for the provider.

 @param completion GenericCompletionBlock containing _TRUE_ if image was successfully populated, otherwise _FALSE_ and an NSError if there is a network issue or the provider doesn't have an image.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage  No image for practice.

 @since 1.0.0
 */
- (void)fetchProviderImage:(nullable GenericCompletionBlock)completion;

#pragma mark - Convenience Methods
/**
 @name Convenience
 */

/**
 Checks if an AWSDKProvider object roots from the AWSDKProviderSearchResult.

 @param provider AWSDKProvider object to compare to.

 @return _TRUE_ if the AWSDKProvider roots from the AWSDKProviderSearchResult and represents the same provider. Otherwise _FALSE_ if different providers.

 @since 2.1.0
 */
- (BOOL)isEqualToProvider:(nonnull id<AWSDKProvider>)provider;

@end
