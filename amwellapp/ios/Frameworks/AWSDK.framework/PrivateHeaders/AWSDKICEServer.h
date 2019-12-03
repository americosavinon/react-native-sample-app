//
//  AWSDKICEServer.h
//  AWSDK
//
//  Created by Stephen Ciauri on 9/23/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWSDKICEServer : NSObject
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *urls;
@property (nonatomic, readonly, nullable) NSString *username;
@property (nonatomic, readonly, nullable) NSString *credential;
- (instancetype)initWithURLs:(NSArray<NSString *> *)urls username:(NSString *)username credential:(NSString *)credential;
+ (NSArray<AWSDKICEServer *> *)ICEServersFromArray:(NSArray<NSDictionary *> *)array;

@end

NS_ASSUME_NONNULL_END
