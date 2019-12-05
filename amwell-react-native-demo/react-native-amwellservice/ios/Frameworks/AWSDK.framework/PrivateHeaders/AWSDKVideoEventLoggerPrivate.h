//
//  AWSDKVideoEventLogger.h
//  AWSDK
//
//  Created by Rolin Nelson on 4/8/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <AWCoreSDK/AWCoreSDK-Swift.h>
#import <Foundation/Foundation.h>

@class AWSDKRemoteLogMessageParam, AWSDKVisit;

@interface AWSDKVideoEventLogger : NSObject <AWCoreVideoKeyEventDelegate>

@property (nonatomic, readonly) AWSDKVisit *visit;
@property (nonatomic, readonly) NSArray<AWSDKRemoteLogMessageParam *> *params;

- (instancetype)initWithVisit:(AWSDKVisit *)visit;
- (void)didRequestEnd;

@end
