//
//  AWCoreGuestConsoleDelegate.h
//  AWCoreSDK
//
//  Created by Calvin Chestnut on 4/29/16.
//  Copyright © 2017 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#ifndef AWCoreGuestConsoleDelegate_h
#define AWCoreGuestConsoleDelegate_h

#import "AWCoreVisitEndReason.h"

/**
 Allows listening to events in the guest visit flow.

 @since 2.0.0
 */
@protocol AWCoreGuestConsoleDelegate

/**
 Called when the guest leaves the visit and the console should be dismissed.

 @param reason AWCoreVisitEndReason representing why the visit ended.

 @since 2.0.0
 */
- (void)leftVisitWithReason:(AWCoreVisitEndReason)reason;

@end

#endif
