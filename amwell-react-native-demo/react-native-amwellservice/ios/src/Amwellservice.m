#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

@interface RCT_EXTERN_MODULE(Amwellservice, NSObject)

RCT_EXTERN_METHOD(initialize:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

RCT_EXTERN_METHOD(authenticateConsumer:(NSString *)userName
                  (NSString*)password
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

RCT_EXTERN_METHOD(fetchPractices:(nonnull id<AWSDKConsumer>)consumer
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

RCT_EXTERN_METHOD(getConsumerSpecialties:(nonnull id<AWSDKConsumer>)consumer
                  (nonnull id<AWSDKPractice>)practice
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

RCT_EXTERN_METHOD(createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer
                  (nonnull id<AWSDKOnDemandSpecialty>)specialty
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

RCT_EXTERN_METHOD(createVisitWithContext:(nonnull id<AWSDKVisitContext>)visitContext
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

// ============== Testing =========================
RCT_EXTERN_METHOD(triggerRequest);
RCT_EXTERN_METHOD(increment);
RCT_EXTERN_METHOD(getCount:(RCTResponseSenderBlock)callback);
RCT_EXTERN_METHOD(setCount:(int) value
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject);

@end
