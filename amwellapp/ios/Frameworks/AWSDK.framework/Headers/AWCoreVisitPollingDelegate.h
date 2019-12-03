//
//  VisitPollingDelegate.h
//  AWCoreSDK
//
//  Created by Stephen Ciauri on 2/1/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#ifndef VisitPollingDelegate_h
#define VisitPollingDelegate_h

@protocol AWCoreVisitPollingDelegate
- (void)visitDidUpdate;
- (void)visitUpdateFailed;
@end
#endif /* VisitPollingDelegate_h */
