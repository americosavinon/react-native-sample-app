//
//  AmwellViewController.m
//  Amwellservice
//
//  Created by YUNFENG LIN on 12/24/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import <React/RCTViewManager.h>

// the component will be exposed as "CounterView"
// if the name ends with "Manager" it will be stripped by React Native
@interface RCT_EXTERN_MODULE(AmwellViewManager, RCTViewManager)
// or, we could also rename it ourselves
//@interface RCT_EXTERN_REMAP_MODULE(CounterView, CounterViewManager, RCTViewManager)

// all NSNumber arguments are required to be marked as "nonnull"
RCT_EXTERN_METHOD(updateValueViaManager:(nonnull NSNumber *)node)
RCT_EXPORT_VIEW_PROPERTY(onUpdate, RCTDirectEventBlock)

@end
