//
//  AWSDKPracticeSubCategory.h
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
#import <AWSDK/AWSDKPracticeCategory.h>
/**
 The AWSDKPracticeSubCategory describes the subcategory that one or more practices can belong to. Subcategories are themselves associated with a category (AWSDKPracticeCategory).
 @since 4.0.0
 */
@protocol AWSDKPracticeSubCategory <AWSDKDataObject>

/**
 Name of the subcategory.
 @since 4.0.0
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 Number of practices that are in the subcategory.
@discussion  The count can be used in the visual presentation of the category hierarchy.
@since 4.0.0
*/
@property (nonatomic, readonly, nonnull) NSNumber *count;
/**
 The category this subcategory belongs to.
 @discussion Each subcategory belongs to exactly ONE category.
 @since 4.0.0
 */
@property (weak, nonatomic, readonly, nullable) id<AWSDKPracticeCategory> category;
@end
