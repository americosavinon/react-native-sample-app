//
//  AWSDKPexipVisitConsoleNavigationController.h
//  AWSDK
//
//  Created by Stephen Ciauri on 3/7/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <AWCoreSDK/AWCoreSDK.h>
#import "AWCoreVisitConsoleController.h"

@class AWSDKPexipVisitController;

@interface AWSDKPexipVisitConsoleNavigationController : AWCoreVisitConsoleController

@property (nonatomic, nonnull) AWSDKPexipVisitController *pexipVisitController;

@end
