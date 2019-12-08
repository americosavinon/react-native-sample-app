//
//  AWSDKPracticeCategory.h
//  AWSDK
//
//  Created by Ed Chianese on 12/20/17.
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
 The AWSDKPracticeCategory describes a category and its collection of subcategories. Practices can belong to a subcategory if the practice contains a subcatagory id that matches the id of the
 subcategory.
 @since 4.0.0
 */
@protocol AWSDKPracticeSubCategory;
@protocol AWSDKPracticeCategory <AWSDKDataObject>
/**
 Name of the Practice Category
 @discussion Each Category has a name.

 @since 4.0.0
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 SubCategories that are part of this Category.

@discussion
 Each practice contains a subcategory id, and each category has 1 or more subcategory ids held in the subCategories array.  Therefore to find all the practices in a category one would identify all
practices that have a subcategory id which matches one of the subcategories that are in the subCategories array of the category of interest.

@since 4.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKPracticeSubCategory>> *subCategories;
@end
