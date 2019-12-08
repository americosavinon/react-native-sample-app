//
//  AWSDKNetworkInfoPrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 8/8/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

@import Foundation;

/**
 Wraps the network info functionality into a helper class for easy use

 @since 4.2.0
 */
@interface AWSDKNetworkInfo : NSObject

/**
 Returns the server-expected enum value for network type

 @return the server-expected enum value for network type
 */
- (NSString *)networkType;

@end
