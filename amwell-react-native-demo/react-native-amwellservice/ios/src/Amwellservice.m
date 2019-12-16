#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

@interface RCT_EXTERN_MODULE(Amwellservice, NSObject)

RCT_EXTERN_METHOD(initialize:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject );
RCT_EXTERN_METHOD(triggerRequest);

@end
