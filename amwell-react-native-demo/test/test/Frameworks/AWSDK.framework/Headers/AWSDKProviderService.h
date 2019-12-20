//
//  AWSDKProviderService.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/24/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKProviderSearchOptions;

/**
 Service handling provider related tasks.

 @since 3.0.0
 */
@protocol AWSDKProviderService <AWSDKDataObject>

#pragma mark - Provider Search Methods
/**
 @name Provider Search Methods
 */

/**
 Fetches a list of provider types available for provider search.

 @param completion ProviderTypeResultsCompletionBlock containing an NSArray of AWSDKProviderType objects, otherwise an NSError explaining what went wrong.

 @since 3.0.0
 */
+ (void)getProviderTypesWithCompletion:(nonnull ProviderTypeResultsCompletionBlock)completion;

/**
 Searches for providers given provider search options.

 @param options    AWSDKProviderSearchOptions object which contains the parameters to search by. If no options are provided, the default options will be used.
 @param completion ProviderSearchResultsCompletionBlock returns the array of AWSDKProviderSearchResult objects matching the given search terms or an NSError containing any errors

 @since 3.0.0
 */
+ (void)performProviderSearchWithOptions:(id<AWSDKProviderSearchOptions> _Nullable)options withCompletion:(nonnull ProviderSearchResultsCompletionBlock)completion;

/**
 Searches for available providers given provider search options.

 @note A consumer must be specified in options.

 @param options Required AWSDKProviderSearchOptions object which contains the parameters to search by. [AWSDKProviderSearchOptions consumer] must be specified.
 @param completion AvailableProviderSearchResultsCompletionBlock containing an AWSDKAvailableProviderSearchResults object containing a list of AWSDKAvailableProviderSearchResult providers and an
 NSDate of the date fetched otherwise an NSError explaining any errors.

 Error codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing   Options was not provided or a consumer was not specified

 @since 3.0.0
 */
+ (void)fetchAvailableProvidersWithOptions:(nonnull id<AWSDKProviderSearchOptions>)options withCompletion:(nonnull AvailableProviderSearchResultsCompletionBlock)completion;

/**
 Fetches providers with specified sourceIds.

 @param sourceIds  NSArray of NSString sourceIds where each sourceId represents a provider to fetch.
 @param completion ProviderSearchResultsCompletionBlock containing an NSArray of AWSDKProviderSearchResult objects, otherwise an NSError containing any errors.

 @since 3.0.0
 */
+ (void)fetchProvidersWithSourceIds:(nonnull NSArray<NSString *> *)sourceIds withCompletion:(nonnull ProviderSearchResultsCompletionBlock)completion;

@end

/**
 Service handling provider related tasks.

 @since 3.0.0
 */
@interface AWSDKProviderService : AWSDKDataObject <AWSDKProviderService>
+ (void)getProviderTypesWithCompletion:(nonnull ProviderTypeResultsCompletionBlock)completion;
+ (void)performProviderSearchWithOptions:(nullable id<AWSDKProviderSearchOptions>)options withCompletion:(nonnull ProviderSearchResultsCompletionBlock)completion;
+ (void)fetchAvailableProvidersWithOptions:(nonnull id<AWSDKProviderSearchOptions>)options withCompletion:(nonnull AvailableProviderSearchResultsCompletionBlock)completion;
+ (void)fetchProvidersWithSourceIds:(nonnull NSArray<NSString *> *)sourceIds withCompletion:(nonnull ProviderSearchResultsCompletionBlock)completion;
@end
