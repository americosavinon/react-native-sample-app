//
//  AWSDKPracticeSearchResultPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/30/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKPracticeSearchResult.h>

/**
 A result of a practice search.

 @discussion This preview contains basic information about a practice. Use fetchPracticeDetails: to fetch the details of the practice.

 @since 1.0.0
 */
@interface AWSDKPracticeSearchResult : AWSDKDataObject <AWSDKPracticeSearchResult>

@property (nonatomic, readwrite) UIImage *logo;
@property (nonatomic, readwrite) UIImage *smallLogo;
@property (nonatomic, readwrite) UIImage *cardOverlay;
@property (nonatomic, readwrite) NSString *consumerAuthKey;

@end
