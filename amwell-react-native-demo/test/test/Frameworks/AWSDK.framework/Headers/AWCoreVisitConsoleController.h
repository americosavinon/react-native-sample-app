//
//  AWCoreVisitConsoleController.h
//  AWCoreSDK
//
//  Created by Calvin Chestnut on 11/5/15.
//  Copyright © 2017 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#ifndef AWCoreVisitConsoleController_h
#define AWCoreVisitConsoleController_h

#import <UIKit/UIKit.h>

/**
 Base controller for the American Well Telehealth visit console for a video conference.

 @discussion [AWSDKVisitService createVisitConsoleForVisit:withCompletion:] creates an instance of AWCoreVisitConsoleController to present modally given an AWSDKVisit. This should not be presented
 until the provider accepts the visit, see [AWSDKVisitDelegate providerDidEnterVisit] and should be dismissed when [AWSDKVisitDelegate visitDidComplete:withEndReason:].

 @note Split screen is not supported by the AWCoreVisitConsoleController. The video chat will only be displayed when in full screen. The Conference controller will disable orientation changes until
 the visit begins

 @since 1.0.0
 */
@interface AWCoreVisitConsoleController : UINavigationController

#pragma mark - UI Configurations
/**
 @name UI Configurations
 */

/**
 Sets the tint color of the visit console.

 @param tintColor UIColor to set.

 @since 1.0.0
 */
- (void)setTintColor:(nonnull UIColor *)tintColor;

/**
 Sets the navigation bar background color of the visit console.

 @param barColor UIColor to set.

 @since 1.0.0
 */
- (void)setNavBarBackgroundColor:(nonnull UIColor *)barColor;

/**
 Begins the visit with the camera disabled.

 @note This property must be set before presenting this ViewController or else it will have no effect.

 @since 3.2.1
 */
@property (nonatomic) BOOL beginVisitWithCameraMuted;

/**
 Shows the privacy view whenever the camera is muted

 @note Defaults to NO. If privacyView is set and beginVisitWithCameraMuted is YES, privacyView will only be displayed upon entering the visit. If set to YES, privacyView will be displayed any time the
 camera is muted.

 @since 3.2.1
 */
@property (nonatomic) BOOL mutingCameraShowsPrivacyView;

/**
 The custom view that will cover the video feed when the visit is started with beginVisitWithCameraMuted set to true

 @since 3.2.1
 */
@property (nonatomic, nullable) UIView *privacyView;

@end

#endif
