//
//  AWSDKVidyoVisitConsoleNavigationController.h
//  AWSDK
//
//  Created by Stephen Ciauri on 7/18/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <AWCoreSDK/AWCoreSDK.h>

@interface AWSDKVidyoVisitConsoleNavigationController : AWCoreVisitConsoleController

@property (nonatomic, nonnull) id<AWCoreVideoKeyEventDelegate> keyEventDelegate;

@end
