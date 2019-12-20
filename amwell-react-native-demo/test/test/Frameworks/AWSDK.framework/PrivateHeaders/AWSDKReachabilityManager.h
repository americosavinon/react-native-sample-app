//
//  AWSDKReachabilityManager.h
//  AWSDK
//
//  Created by Stephen Ciauri on 1/9/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <AWCoreSDK/AWCoreSDK.h>

/**
 Manage reachability connection status.

 @since 5.0.0
 */
@interface AWSDKReachabilityManager : NSObject <AWCoreReachabilityHandlerProtocol>

@property (class, nonatomic, readonly) AWSDKReachabilityManager *sharedManager;

@end
