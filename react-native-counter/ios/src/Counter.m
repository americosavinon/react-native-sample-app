#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

@interface RCT_EXTERN_MODULE(Counter, NSObject)

RCT_EXTERN_METHOD(initialize:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject );
RCT_EXTERN_METHOD(test:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject );
RCT_EXTERN_METHOD(testProperty);

@end
