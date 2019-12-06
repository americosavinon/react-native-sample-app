//
//  AWSDKPractice.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/15/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <AWSDK/AWSDKModality.h>
#import <AWSDK/AWSDKPracticeSubCategory.h>

/** List of Practice Types */
typedef NS_ENUM(NSInteger, AWSDKPracticeType) {
    /** Default Practice Type */
    Default = 1,
    /** Exclusive Practice Type */
    Exclusive,
    /** Normal Practice Type */
    Normal
};

// clang-format off
@protocol AWSDKAddress, AWSDKConsumer;
// clang-format on

/**
 A practice of providers protocol on the telehealth installation.

 @discussion To fetch an AWSDKPractice object, first fetch practices to retrieve AWSDKPracticeSearchResult, and then call [AWSDKPracticeSearchResult fetchPracticeDetails:].

 @since 3.1.0
 */
@protocol AWSDKPractice <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable name of the practice.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString representing the sourceId of the practice.

 @since 4.1.1
 */
@property (nonatomic, readonly, nonnull) NSString *sourceId;

/**
 AWSDKPracticeType enum representing the practice type.

 @since 3.0.2
 */
@property (assign, nonatomic) AWSDKPracticeType practiceType;

/**
 NSString representing the custom welcome message explaining any information about the practice.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *welcomeMessage;

/**
 AWSDKAddress representing the practice's physical address.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKAddress> address;

/**
 NSString representing the unformatted contact phone number for the practice.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *phoneNumber;

/**
 NSString representing the formatted phone number for the practice.

 @since 4.2.0
 */
@property (nonatomic, readonly, nullable) NSString *formattedPhoneNumber;

/**
 NSString representing the unformatted contact fax number for the practice.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *faxNumber;

/**
 NSString containing the hours of the practice, formatted by the practice administrators.

 @discussion This is typically formatted text using special characters such as line breaks e.g. @"\n".

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *hours;

/**
 UIImage representing the practice's logo.

 @note This will be _nil_ until the fetchPracticeLogo: method has been called

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) UIImage *logo;

/**
 NSURL pointing to the location of the logo image.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSURL *logoUrl;

/**
 NSInteger indicating the rank of the practice used for sorting.

 @discussion    This can be used to determine if the practices have been received in sorted order.

 @since 3.2.2
 */
@property (assign, nonatomic, readonly, nonnull) NSNumber *rank;

/**
 UIImage representing the practice's small logo.

 @discussion The small logo is a reduced version of the AWSDKPractice.logo property.

 @note This will be _nil_ until the fetchPracticeSmallLogo: method has been called.

 @since 3.0.0
 */
@property (nonatomic, readonly, nullable) UIImage *smallLogo;

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

/**
 Boolean indicating whether or not payment is required when scheduling a visit within this practice.

 @discussion    If the value is YES, then require the consumer's payment information to be provided when scheduling an appointment.

 @since 3.2.0
 */
@property (assign, nonatomic, readonly) BOOL isPaymentRequiredForScheduledVisits;

/**
 NSString containing the text to display when a payment method is required when scheduling an appointment.

 @discussion    The text to display when payment is required while scheduling a visit within this practice.

 @since 3.2.0
 */
@property (copy, nonatomic, readonly, nullable) NSString *paymentRequiredForScheduledVisitsText;

/**
 NSString representing the displayable name of the practice specialty.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *specialtyName;

/**
 NSString representing the practice specialty color.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *specialtyColor;

/**
 NSString representing the practice subtitle.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSString *subtitle;

/**
 UIImage representing the practice's card image.

 @discussion The practice's card image.

 @note This will be _nil_ until the fetchPracticeCardOverlay: method has been called.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) UIImage *cardOverlay;

/**
 Array of modality options for visit communications

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKModality>> *availableModalities;

/**
 Boolean indicating whether or not the cancel appointment link is hidden for this practice.

 @discussion If the value is YES, then you should remove the ability for the consumer to cancel their appointment from your application.

 @since 4.4.0
 */
@property (assign, nonatomic, readonly) BOOL hideCancelAppointmentLink;

/**
 Boolean indicating whether or not to hide the provider visit cost estimate for this practice.

 @discussion If the value is YES, then the provider visit cost estimate will be hidden.

 @since 4.4.0
 */
@property (assign, nonatomic, readonly) BOOL hideProviderVisitCostEstimate;

#pragma mark - Read-Only Configuration Properties
/**
 @name Read-Only Configuration Properties
 */

/**
 BOOL representing the system configuration for the practice to show or hide "available now" providers.

 @discussion If enabled, the consumer web platform will show providers currently available. The SDK does not enforce using this boolean, but provides access for a consistent user experience.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) BOOL showAvailableNow;

/**
 BOOL representing the system configuration for the practice to show or hide scheduling options.

 @discussion If enabled, the consumer web platform will show scheduling options. The SDK does not enforce using this boolean, but provides access for a consistent user experience.

 @since 3.0.0
 */
@property (assign, nonatomic, readonly) BOOL showScheduling;

/**
 The array of subcategories the practice belongs to.
 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKPracticeSubCategory>> *subCategories;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the logo for the practice and sets it as logo.

 @param completion GenericCompletionBlock containing _TRUE_ if logo was successfully populated, otherwise _FALSE_ and an NSError if the practice has no logo or any other failures.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage   No image for practice

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
 Fetches all providers visible in the practice.

 @param completion ProviderSearchResultsCompletionBlock containing an NSArray of AWSDKProviderSearchResults representing the providers of the practice, otherwise an NSError if there are any problems.

 @since 1.0.0
 */
- (void)fetchDefaultProviders:(nullable ProviderSearchResultsCompletionBlock)completion;

/**
 Fetches all providers in the practice that a specific consumer has access to.

 @param consumer    AWSDKConsumer representing the consumer to fetch providers for.
 @param completion   ProviderSearchResultsCompletionBlock containing an NSArray of AWSDKProviderSearchResults representing the providers of the practice, otherwise an NSError if there are any
 problems.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required parameter

 @since 1.0.0
 */
- (void)fetchProvidersForConsumer:(nonnull id<AWSDKConsumer>)consumer completion:(nonnull ProviderSearchResultsCompletionBlock)completion;

/**
 Fetches all specialties in the practice that a specific consumer has access to.

 @discussion As of 2.0.0, it is common for only one AWSDKOnDemandSpecialty per practice.

 @param consumer     AWSDKConsumer representing the consumer to fetch specialties for.
 @param completion   OnDemandSpecialtyResultsCompletionBlock containing an NSArray of AWSDKOnDemandSpecialties available to the given consumer, or an NSError explaining what went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required parameter

 @since 1.0.0
 */
- (void)fetchSpecialtiesForConsumer:(nonnull id<AWSDKConsumer>)consumer completion:(nonnull OnDemandSpecialtyResultsCompletionBlock)completion;

/**
 Fetches the card image for the practice.

 @param completion GenericCompletionBlock containing _TRUE_ if logo was successfully populated, otherwise _FALSE_ and an NSError if the practice has no card image or any other failures.

 Potential Error Codes
 @exception AWSDKErrorCodeNoSpecifiedImage   No card image for practice

 @since 4.1.0
 */
- (void)fetchPracticeCardOverlay:(nullable GenericCompletionBlock)completion;

@end
