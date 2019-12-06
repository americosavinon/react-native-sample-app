//
//  AWSDKProviderSearchOptions.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/7/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKPractice, AWSDKConsumer, AWSDKProviderType, AWSDKLanguage, AWSDKState, AWSDKCountry;
// clang-format on

/**
 Options protocol used to filter a list of AWSDKProviderSearchResult providers when fetching.

 @discussion Used with method [AWSDKProviderService performProviderSearchWithOptions:withCompletion:] to filter search results. Every property is optional and can be kept as _nil_ to not include.

 @since 3.1.0
 */
@protocol AWSDKProviderSearchOptions <AWSDKDataObject>

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSString representing the provider name to search for.

 @discussion Note that either name or the provider specialties search option will be applied, but not both. In this case the name will take precedence.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *name;

/**
 NSArray of AWSDKProviderType to restrict search to only specific provider types.

 @discussion Note that either this or the provider name search option will be applied, but not both. In this case the name will take precedence.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) NSArray<id<AWSDKProviderType>> *providerSpecialties;

/**
 AWSDKPractice representing a practice to restrict the search to.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKPractice> practice;

/**
 AWSDKConsumer to restrict results to only providers available to this consumer.

 @discussion Some of the reasons why a consumer may not have access to a practice include their current state, a private practice, or a practice that requires a service key to be applied.

 @since 1.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKConsumer> consumer;

/**
 AWSDKLanguage to restrict results to only providers that speak this language.

 @since 2.0.0
 */
@property (nonatomic, nullable) id<AWSDKLanguage> languageSpoken;

/**
 AWSDKState to restrict results to only providers that are available to this state.

 @since 2.0.0
 */
@property (nonatomic, nullable) id<AWSDKState> state;

/**
 AWSDKCountry to restrict results to only providers that are available to this country.

 @since 4.0.0
 */
@property (nonatomic, nullable) id<AWSDKCountry> country;

/**
 int representing max results to list, otherwise 0 to use the server's default max.

 @since 1.0.0
 */
@property (nonatomic, readwrite) int maxResults;

/**
 The number of days to limit the search range.

 @discussion Defaults to 1. Valid range for this value is between 1 and 365.

 @since 3.1.0
 */
@property (nonatomic, readwrite) int limitInDays;

/**
 NSDate to set to search for appointments on a specific day.

 @discussion only appointmentDate or nextAppointmentDate can be set not both.

 @since 3.0.0
 */
@property (nonatomic, nullable) NSDate *appointmentDate;

/**
 BOOL if set _TRUE_, will search for the next available appointment.

 @discussion Only appointmentDate or nextAppointmentDate can be set not both.

 @since 3.0.0
 */
@property (nonatomic, readwrite) BOOL nextAppointmentDate;

#pragma mark - Convenience Methods
/**
 @name Convenience Methods
 */

/**
 Retrieves an NSArray of valid AWSDKState options for provider search.

 @return NSArray of AWSDKState options.

 @since 2.0.0
 */
+ (nonnull NSArray<id<AWSDKState>> *)validSearchStates;

/**
 Retrieves an NSArray of valid AWSDKProviderType options for provider search.

 @return NSArray of AWSDKProviderType options.

 @since 2.1.0
 */
+ (nonnull NSArray<id<AWSDKProviderType>> *)validSearchProviderTypes;

@end

/**
 Options used to filter a list of AWSDKProviderSearchResult providers when fetching.

 @discussion Used with method [AWSDKProviderService performProviderSearchWithOptions:withCompletion:] to filter search results. Every property is optional and can be kept as _nil_ to not include.

 @since 1.0.0
 */
@interface AWSDKProviderSearchOptions : AWSDKDataObject <AWSDKProviderSearchOptions>

#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new instance of AWSDKProviderSearchOptions to use.

 @return A new AWSDKProviderSearchOptions instance.

 @since 1.0.0
 */
+ (nonnull instancetype)options;
#pragma mark - Appledoc
@property (nonatomic, nullable, readwrite) NSString *name;
@property (nonatomic, nullable, readwrite) NSArray<id<AWSDKProviderType>> *providerSpecialties;
@property (nonatomic, nullable, readwrite) id<AWSDKPractice> practice;
@property (nonatomic, nullable, readwrite) id<AWSDKConsumer> consumer;
@property (nonatomic, nullable) id<AWSDKLanguage> languageSpoken;
@property (nonatomic, nullable) id<AWSDKState> state;
@property (nonatomic, readwrite) int maxResults;
@property (nonatomic, readwrite) int limitInDays;
@property (nonatomic, nullable) NSDate *appointmentDate;
@property (nonatomic, readwrite) BOOL nextAppointmentDate;
+ (nonnull NSArray<id<AWSDKState>> *)validSearchStates;
+ (nonnull NSArray<id<AWSDKProviderType>> *)validSearchProviderTypes;
#pragma mark -
@end
