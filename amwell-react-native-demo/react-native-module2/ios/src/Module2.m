//
//  Module2.m
//  Module2
//
//  Created by Yunfeng Lin on 12/6/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

@interface RCT_EXTERN_MODULE(Module2, NSObject)

RCT_EXTERN_METHOD(test:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject );
RCT_EXTERN_METHOD(testProperty);
RCT_EXTERN_METHOD(initialize:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject );

@end
