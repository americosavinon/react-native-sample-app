//
//  AWSDKTrackersRequestPrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 10/24/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKTrackersRequest.h>

@interface AWSDKTrackersRequest ()
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a dictionary representation of AWSDKTrackersRequest.

 @return A new NSDictionary instance.

 @since 4.3.0
 */
- (NSDictionary *)toParams;

@end
