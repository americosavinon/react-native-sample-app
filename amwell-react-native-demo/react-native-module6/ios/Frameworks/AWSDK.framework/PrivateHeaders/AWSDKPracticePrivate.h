//
//  AWSDKPracticePrivate.h
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

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKPractice.h>

@class AWSDKPracticeSearchResult;

/**
 A practice of providers on the telehealth installation.

 @discussion To fetch an AWSDKPractice object, first fetch practices to retrieve AWSDKPracticeSearchResult, and then call [AWSDKPracticeSearchResult fetchPracticeDetails:].

 @since 1.0.0
 */
@interface AWSDKPractice : AWSDKDataObject <AWSDKPractice>

/**
 OnlineCareId of the subcategory the practice belongs to.
 @discussion The id not exposed to the SDK client.  Rather it is used to help assign the full subcategory object to the practice internally.
 @since 4.0.0
 */
@property (nonatomic, readonly, nullable) OnlineCareId *subCategoryId;

/**
 OnlineCareIds of the subcategories the practice belongs to.
 @discussion The ids are not exposed to the SDK client.  Rather it is used to help assign the full subcategory array to the practice internally.
 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSSet<OnlineCareId *> *subCategoryIds;

@property (nonatomic, nullable) NSArray<id<AWSDKPracticeSubCategory>> *subCategories;

+ (nullable NSArray<AWSDKPracticeSearchResult *> *)practicesFromSearchResults:(nonnull NSDictionary *)json;
+ (nullable NSArray<AWSDKPractice *> *)practicesFromConsumerResults:(nonnull NSDictionary *)json;

@property (nonatomic, readwrite, nullable) UIImage *logo;
@property (nonatomic, readwrite, nullable) UIImage *smallLogo;
@property (nonatomic, readwrite, nullable) UIImage *cardOverlay;

@end
