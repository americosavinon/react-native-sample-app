//
//  AWSDKProvider.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/24/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKUser.h>

// clang-format off
@protocol AWSDKPractice, AWSDKProviderType, AWSDKLanguage, AWSDKConsumer, AWSDKProviderSearchResult;
// clang-format on

/**
 NS_ENUM representing a provider's availability.

 @since 1.0.0
 */

typedef NS_ENUM(NSInteger, AWSDKMobileAvailability) {
    /**
     Provider is available for a video visit.

     @since 1.0.0
     */
    VideoAvailable = 1,
    /**
     Provider is currently in a video visit.

     @since 1.0.0
     */
    VideoBusy,
    /**
     Provider is on call and may take longer to respond to visit requests.

     @since 1.0.0
     */
    OnCall,
    /**
     Provider is unavailable.

     @since 1.0.0
     */
    Offline
};

/**
 A provider protocol in the American Well telehealth platform.

 @discussion To fetch an AWSDKProvider, first fetch the AWSDKProviderSearchResult and then call [AWSDKProviderSearchResult fetchDetails:].

 @since 3.1.0
 */
@protocol AWSDKProvider <AWSDKUser>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the provider's custom greeting that introduces them to a consumer.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *greeting;

/**
 AWSDKProviderType representing the provider's specialty.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProviderType> specialty;

/**
 NSString representing the provider's alma mater, localized to the AWSDK's current preferred locale.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *schoolName;

/**
 NSString representing the year the provider graduated (eg. @"1992").

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *graduatingYear;

/**
 NSNumber representing the number of years of experience the provider has.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSNumber *yearsExperience;

/**
 NSArray of NSStrings representing the provider's board certificates

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *boardCertificates;

/**
 NSArray of NSStrings representing the provider's fellowships

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *fellowships;

/**
 NSString representing the provider's internship

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *internship;

/**
 NSString representing the provider's residency

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *residency;

/**
 NSArray of AWSDKLanguage languages the provider is fluent in.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKLanguage>> *languagesSpoken;

/**
 NSArray of NSString states the provider is licensed in.

 @since 3.2.2
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *statesLicensedIn;

/**
 NSString representing Unique ID for the provider used to identify their registration source and for performing searches.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *sourceID;

/**
 NSNumber representing the rating the provider has in the American Well telehealth platform, out of 5 stars.

 @discussion Rating will be populated despite of [AWSDKSystemConfiguration showProviderRatings] .

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSNumber *rating;

/**
 NSNumber representing the total ratings the provider has in the American Well telehealth platform.

 @discussion Rating will be populated despite of [AWSDKSystemConfiguration showProviderRatings]. This value will be 0 until the server-configurable minRatingsToShowStoredValue threshold has been
 reached.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) NSNumber *totalRatings;

/**
 UIImage representing the provider's display image. This will be _nil_ until the fetchProviderImage: method has been called

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
 BOOL set _TRUE_ if the provider is a part of American Well's National Telehealth Network, otherwise _FALSE_ if not apart of the NTN.

 @since 2.0.0
 */
@property (nonatomic, assign, readonly, getter=isNTN) BOOL ntn;

/**
 BOOL set _TRUE_ if the provider is a primary care physician.

 @since 4.1.0
 */
@property (nonatomic, assign, readonly, getter=isPCP) BOOL pcp;

/**
 AWSDKMobileAvailability representing the provider's current availability status.

 @since 1.0.0
 */
@property (readonly) AWSDKMobileAvailability availability;

/**
 NSInteger representing the number of consumers waiting for the provider.

 @note This number is not refreshed unless a new AWSDKProviderSearchResult is fetched.

 @since 2.0.0
 */
@property (assign, nonatomic, readonly) NSInteger waitingRoomCount;

/**
 Bool value indicating whether the Provider desires the consumer to answer triage questions for the visit.

 @since 3.0.0
 */
@property (readonly) BOOL showTriageQuestions;

#pragma mark - Deferred Billing Read-Only Properties
/**
 @name Deferred Billing Read-Only Properties
 */

/**
 BOOL set _TRUE_ if deferred billing is enabled on the practice configuration to allow consumers to be billed at a later date.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) BOOL isDeferredBillingEnabled;

/**
 NSString representing a configurable displayable message in the practice configuration to alert consumers about deferred billing.

 @since 3.0.0
 */
@property (nonatomic, readonly, nullable) NSString *deferredBillingText;

/**
 AWSDKPractice representing the practice associated to the provider.

 @note Since a provider can be associated to several practices, this value will depend on the practice the provider used for that session.

 @since 4.4.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKPractice> practice;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the image for the particular provider.

 @param completion GenericCompletionBlock containing _TRUE_ if image was successfully populated, otherwise _FALSE_ and an NSError if there is a network issue or if the provider doesn't have an image.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage  No image for provider.

 @since 1.0.0
 */
- (void)fetchProviderImage:(nullable GenericCompletionBlock)completion;

/**
 Fetches the estimated cost for a visit with the provider.

 @param consumer    AWSDKConsumer representing the estimated visit cost for.
 @param completion  CostResultCompletionBlock containing an AWSDKCost if the estimated cost fetched successfully, otherwise _FALSE_ and an NSError explaining any failures. If the consumer's
 subscription is invalid or could not be validated, the NSError will be populated with either AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo or AWSDKErrorCodeValidationEligibilityException
 accordingly. These are successful cases, but warns that the cost does not reflect the consumer's subscription coverage.

 Successful Eligibility Exception Cases
 @exception AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo           The consumer's subscription was flagged as invalid by the insurance provider. The cost will not reflect their
 subscription coverage. The user can update their demographic information to match what the health plan has on file to update the estimated cost.
 @exception AWSDKErrorCodeValidationEligibilityException                       The consumer's subscription couldn't be validated by the insurance provider. The cost will not reflect their subscription
 coverage.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionUnpublished, AWSDKVisitDispositionUnscheduled, AWSDKVisitDispositionScheduled, AWSDKVisitDispositionParked and AWSDKVisitDispositionPreVisit

 @since 2.0.0
 */
- (void)fetchEstimatedCostForConsumer:(nonnull id<AWSDKConsumer>)consumer withCompletion:(nonnull CostResultCompletionBlock)completion;

/**
 Reloads the provider details to get most recent availability and waiting room counts.

 @param completion GenericCompletionBlock containing _TRUE_ if the provider details were properly reloaded, otherwise _FALSE_ and an NSError explaining any failures.

 @since 1.0.0
 */
- (void)reloadDetails:(nullable GenericCompletionBlock)completion;

/**
 Attempts to fetch available appointment blocks on a specific day. If no date is passed in, the telehealth platform will attempt to fetch the next available day and its appointments.

 @param date       NSDate for the date to search
 @param completion ScheduleResultsCompletionBlock will return a list of AWSDKSchedule appointment schedules on a specific day or next available day. Will return an empty array if no results are
 available.

 @since 4.1.0
 */
- (void)fetchAvailableAppointmentsOnDate:(nullable NSDate *)date withCompletion:(nonnull ScheduleResultsCompletionBlock)completion;

/**
 Attempts to fetch available appointment blocks between two specific dates.

 @discussion    If an invalid date range is passed, the default behavior will search between the start date and the next calendar day.

 @param dateInterval  NSDateInterval representing the start and end date search range
 @param completion ScheduleResultsCompletionBlock will return a list of AWSDKSchedule appointment schedules on a specific day or next available day. Will return an empty array if no results are
 available.

 @since 5.0.0
 */
- (void)fetchAvailableAppointmentsWithinDateInterval:(nonnull NSDateInterval *)dateInterval withCompletion:(nonnull ScheduleResultsCompletionBlock)completion;

#pragma mark - Convenience Methods
/**
 @name Convenience Methods
 */

/**
 Compares the AWSDKProvider and an AWSDKProviderSearchResult.

 @param result AWSDKProviderSearchResult to compare to.

 @return _TRUE_ if the same provider, otherwise _FALSE_ if a different provider.

 @since 2.1.0
 */
- (BOOL)isEqualToProviderSearchResult:(nonnull id<AWSDKProviderSearchResult>)result;
@end
