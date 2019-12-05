//
//  AWSDKPracticeSubCategoryPrivate.h
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

#import "AWSDK/AWSDKPracticeCategoryPrivate.h"
#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKPracticeSubCategory.h>
/**
 @since 4.0.0
 */
@interface AWSDKPracticeSubCategory : AWSDKDataObject <AWSDKPracticeSubCategory>
- (void)setPracticeCategory:(id<AWSDKPracticeCategory>)cat;
@end
