//
//  AWSDKPracticeService.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/25/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKLanguage, AWSDKConsumer, AWSDKPractice, AWSDKPracticeCategory;
// clang-format on

/**
 Service handling practice related tasks.

 @since 3.0.0
 */
@protocol AWSDKPracticeService <AWSDKDataObject>

#pragma mark - Practice Search
/**
 @name Practice Search
 */

/**
 Fetches a list of default practices.

 @param completion PracticeSearchResultsCompletionBlock containing an NSArray of AWSDKPracticeSearchResult default practices, otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPracticesSearchResultsWithCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;

/**
 Fetches a list of practices with providers that speak a language.

 @param language   AWSDKLanguage valid language to search spoken languages.
 @param completion PracticeSearchResultsCompletionBlock containing an NSArray of AWSDKPracticeSearchResult practices that contain providers that speak the given language, otherwise an NSError
 explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPracticesSearchResultsWithLanguage:(nonnull id<AWSDKLanguage>)language withCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;

/**
 Fetches an ordered list of AWSDKPractice objects (by rank and name) that an AWSDKConsumer has access to.

 @discussion A consumer may not have access to a practice due to their current state, the practice being private, or the practice requiring a service key to be applied for the consumer.

 @param consumer        AWSDKConsumer to fetch practices for.
 @param completion      PracticeResultsCompletionBlock containing an NSArray of AWSDKPractice objects that the consumer has access to, otherwise an NSError explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing parameter.
 @exception AWSDKErrorCodeConsumerUnauthenticated               Consumer has not been authenticated.

 @since 3.0.0
 */
+ (void)fetchPracticesForConsumer:(nonnull id<AWSDKConsumer>)consumer withCompletion:(nonnull PracticeResultsCompletionBlock)completion;

/**
 Fetches a list of practices with providers that speak a specific language that an AWSDKConsumer has access to.

 @param consumer        AWSDKConsumer to fetch practices for.
 @param language        AWSDKLanguage valid language to search spoken languages.
 @param completion      PracticeSearchResultsCompletionBlock containing an NSArray of AWSDKPracticeSearchResult practices containing providers who speak the chosen language, otherwise an NSError
 explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing parameter.
 @exception AWSDKErrorCodeConsumerUnauthenticated               Consumer has not been authenticated.

 @since 3.0.0
 */
+ (void)fetchPracticesSearchResultsForConsumer:(nonnull id<AWSDKConsumer>)consumer
                                  withLanguage:(nonnull id<AWSDKLanguage>)language
                                withCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;

/**
 Fetches the practice with the given sourceId. If a practice is not found with the provided sourceId, this will return an empty array.

 @param sourceID The sourceId of the desired practice
 @param completion PracticeSearchResultsCompletionBlock containing an NSArray of AWSDKPracticeSearchResult practices that map to the given sourceId, otherwise an NSError

 @since 4.2.0
 */
+ (void)fetchPracticeSearchResultWithSourceID:(nonnull NSString *)sourceID completion:(nonnull PracticeSearchResultsCompletionBlock)completion;

/**
 Service that returns the set of practices and the set of categories associated with those practices.  This supersedes fetchPracticesForConsumer, and lets us match up practices with their
 subcategories.

 @since 4.0.0
 */
+ (void)fetchPracticesAndCategoriesForConsumer:(nonnull id<AWSDKConsumer>)consumer
                                withCompletion:
                                    (void (^_Nullable)(NSArray<id<AWSDKPractice>> *_Nullable practices, NSArray<id<AWSDKPracticeCategory>> *_Nullable categories, NSError *_Nullable error))completion;

/**
 Fetches a list of available appointment dates within a practice, starting with the specified date.

 @param practice  AWSDKPractice we are looking for availability in.
 @param consumer  AWSDKConsumer to fetch dates for
 @param language  AWSDKLanguage to filter providers on when finding open appointment times. The default language is used if the parameter is nil.
 @param startDate The first date from which we look for availability.
 @param maxResults maxResult limits the number of dates potentially returned. All dates are returned when the parameter is nil.
 @param completion Contains an array of NSDates that have availability within the practice.

 @since 4.1.0
 */
+ (void)fetchAvailableDatesForPractice:(nonnull id<AWSDKPractice>)practice
                              consumer:(nonnull id<AWSDKConsumer>)consumer
                        spokenLanguage:(nullable id<AWSDKLanguage>)language
                             startDate:(nonnull NSDate *)startDate
                            maxResults:(nullable NSNumber *)maxResults
                        withCompletion:(nonnull DatesArrayCompletionBlock)completion;
@end

/**
 Service handling practice related tasks.

 @since 3.0.0
 */
@interface AWSDKPracticeService : AWSDKDataObject <AWSDKPracticeService>
#pragma mark - Appledoc
+ (void)fetchPracticesSearchResultsWithCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;
+ (void)fetchPracticesSearchResultsWithLanguage:(nonnull id<AWSDKLanguage>)language withCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;
+ (void)fetchPracticesForConsumer:(nonnull id<AWSDKConsumer>)consumer withCompletion:(nonnull PracticeResultsCompletionBlock)completion;
+ (void)fetchPracticesSearchResultsForConsumer:(nonnull id<AWSDKConsumer>)consumer
                                  withLanguage:(nonnull id<AWSDKLanguage>)language
                                withCompletion:(nonnull PracticeSearchResultsCompletionBlock)completion;
+ (void)fetchPracticesAndCategoriesForConsumer:(nonnull id<AWSDKConsumer>)consumer
                                withCompletion:
                                    (void (^_Nullable)(NSArray<id<AWSDKPractice>> *_Nullable practices, NSArray<id<AWSDKPracticeCategory>> *_Nullable categories, NSError *_Nullable error))completion;
+ (void)fetchAvailableDatesForPractice:(nonnull id<AWSDKPractice>)practice
                              consumer:(nonnull id<AWSDKConsumer>)consumer
                        spokenLanguage:(nullable id<AWSDKLanguage>)language
                             startDate:(nonnull NSDate *)startDate
                            maxResults:(nullable NSNumber *)maxResults
                        withCompletion:(nonnull DatesArrayCompletionBlock)completion;
#pragma mark -
@end
