//
//  AWSDKAppearanceManager.h
//  AWSDK
//
//  Created by Rolin Nelson on 4/30/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Contains all of the available visual customization for the WebRTC console

 @since 5.0.0
 */
@interface AWSDKAppearanceManager : NSObject

#pragma mark - Consumer Video Console Customization properties

// MARK: - Camera customization

/**
 The color used for the `Camera` button background in the "on" state.

 @since 5.0.0
 */
@property (nonatomic) UIColor *cameraOnButtonBackgroundColor;

/**
 The color used for the `Camera` button tint in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *cameraOnButtonTintColor;

/**
 The image used for the `Camera` button in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *cameraOnButtonImage;

/**
 The color used for the `Camera` button background in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *cameraOffButtonBackgroundColor;

/**
 The color used for the `Camera` button tint in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *cameraOffButtonTintColor;

/**
 The image used for the `Camera` button in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *cameraOffButtonImage;

// MARK: - Microphone customization

/**
 The color used for the `Microphone` button background in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *microphoneOnButtonBackgroundColor;

/**
 The color used for the `Microphone` button tint in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *microphoneOnButtonTintColor;

/**
 The image used for the `Microphone` button in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *microphoneOnButtonImage;

/**
 The color used for the `Microphone` button background in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *microphoneOffButtonBackgroundColor;

/**
 The color used for the `Microphone` button tint in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *microphoneOffButtonTintColor;

/**
 The image used for the `Microphone` button in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *microphoneOffButtonImage;

// MARK: - Camera Switch customization

/**
 The color used for the `Camera Switch` button background.

 @since 5.0.0
*/
@property (nonatomic) UIColor *cameraSwitchButtonBackgroundColor;

/**
 The color used for the `Camera Switch` button tint.

 @since 5.0.0
*/
@property (nonatomic) UIColor *cameraSwitchButtonTintColor;

/**
 The image used for the `Camera Switch` button.

 @since 5.0.0
*/
@property (nonatomic) UIImage *cameraSwitchButtonImage;

/**
 The color used for the labels of all buttons.

 @since 5.0.0
*/
@property (nonatomic) UIColor *buttonsLabelTextColor;

/**
 The color used for the demographics labels.

 @since 5.0.0
 */
@property (nonatomic) UIColor *demographicsLabelTextColor;

// MARK: - Drawer Customization

/**
 The color used for the background of an item in the drawer.

 @since 5.0.0
 */
@property (nonatomic) UIColor *drawerItemBackgroundColor;

/**
 The color used for the background of the drawer.

 @since 5.0.0
 */
@property (nonatomic) UIColor *drawerBackgroundColor;

/**
 The color used for the `Invite` button background.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerInviteButtonBackgroundColor;

/**
 The color used for the `Invite` button tint.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerInviteButtonTintColor;

/**
 The image used for the `Invite` button.

 @since 5.0.0
*/
@property (nonatomic) UIImage *drawerInviteButtonImage;

/**
 The color used for the `Reload` button background.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerReloadButtonBackgroundColor;

/**
 The color used for the `Reload` button tint.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerReloadButtonTintColor;

/**
 The image used for the `Reload` button.

 @since 5.0.0
*/
@property (nonatomic) UIImage *drawerReloadButtonImage;

/**
 The color used for the `Speaker` button background in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerSpeakerOnButtonBackgroundColor;

/**
 The color used for the `Speaker` button tint in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerSpeakerOnButtonTintColor;

/**
 The image used for the `Speaker` button in the "on" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *drawerSpeakerOnButtonImage;

/**
 The color used for the `Speaker` button background in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerSpeakerOffButtonBackgroundColor;

/**
 The color used for the `Speaker` button tint in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerSpeakerOffButtonTintColor;

/**
 The image used for the `Speaker` button in the "off" state.

 @since 5.0.0
*/
@property (nonatomic) UIImage *drawerSpeakerOffButtonImage;

/**
 The color used for the labels of all buttons in the drawer.

 @since 5.0.0
*/
@property (nonatomic) UIColor *drawerButtonsLabelTextColor;

// MARK: - Side Drawer Customization

/**
 The gradient colors used for the background of the side drawer.

 @since 5.0.0
 */
@property (nonatomic) NSArray<UIColor *> *sideDrawerGradientColors;

/**
 The gradient stops used for the background of the side drawer.

 @since 5.0.0
 */
@property (nonatomic) NSArray<NSNumber *> *sideDrawerGradientLocations;

/**
 The color used for the background of the side drawer.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerBackgroundColor;

/**
 The color used for the `Invite` button background.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerInviteButtonBackgroundColor;

/**
 The color used for the `Invite` button tint.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerInviteButtonTintColor;

/**
 The image used for the `Invite` button.

 @since 5.0.0
 */
@property (nonatomic) UIImage *sideDrawerInviteButtonImage;

/**
 The color used for the `Reload` button background.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerReloadButtonBackgroundColor;

/**
 The color used for the `Reload` button tint.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerReloadButtonTintColor;

/**
 The image used for the `Reload` button.

 @since 5.0.0
 */
@property (nonatomic) UIImage *sideDrawerReloadButtonImage;

/**
 The color used for the `Speaker` button background in the "on" state.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerSpeakerOnButtonBackgroundColor;

/**
 The color used for the `Speaker` button tint in the "on" state.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerSpeakerOnButtonTintColor;

/**
 The image used for the `Speaker` button in the "on" state.

 @since 5.0.0
 */
@property (nonatomic) UIImage *sideDrawerSpeakerOnButtonImage;

/**
 The color used for the `Speaker` button background in the "off" state.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerSpeakerOffButtonBackgroundColor;

/**
 The color used for the `Speaker` button tint in the "off" state.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerSpeakerOffButtonTintColor;

/**
 The image used for the `Speaker` button in the "off" state.

 @since 5.0.0
 */
@property (nonatomic) UIImage *sideDrawerSpeakerOffButtonImage;

/**
 The color used for the labels of all buttons in the drawer.

 @since 5.0.0
 */
@property (nonatomic) UIColor *sideDrawerButtonsLabelTextColor;

#pragma mark - Navigation Bar Customization

/**
 The color used for the `Title` in the navigation bar.

 @since 5.0.0
*/
@property (nonatomic) UIColor *navigationBarTitleColor;

/**
 The color used for the navigation bar tint.

 @since 5.0.0
*/
@property (nonatomic) UIColor *navigationBarTintColor;

/**
 The color used for the navigation bar background.

 @since 5.0.0
*/
@property (nonatomic) UIImage *navigationBarBackgroundImage;

/**
 The gradient colors used for the navigation bar background.

 @since 5.0.0
 */
@property (nonatomic) NSArray<UIColor *> *navigationBarGradientColors;

/**
 The gradient stops used for the navigation bar background.

 @since 5.0.0
 */
@property (nonatomic) NSArray<NSNumber *> *navigationBarGradientLocations;

/**
 The color used for the `End` button background.

 @since 5.0.0
 */
@property (nonatomic) UIColor *navigationBarEndButtonBackgroundColor;

/**
 The color used for the `End` button tint.

 @since 5.0.0
 */
@property (nonatomic) UIColor *navigationBarEndButtonTintColor;

/**
 The image used for the `End` button.

 @since 5.0.0
*/
@property (nonatomic) UIImage *navigationBarEndButtonImage;

/**
 The color used for the `Timer` normal text.

 @since 5.0.0
*/
@property (nonatomic) UIColor *navigationBarTimerNormalColor;

/**
 The color used for the `Timer` ending soon text.

 @since 5.0.0
*/
@property (nonatomic) UIColor *navigationBarTimerEndingColor;

#pragma mark - Invite Guest Customization

/**
 The color used for the `Title` in the navigation bar.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestNavigationBarTitleColor;

/**
 The color used for the navigation bar tint.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestNavigationBarTintColor;

/**
 The image used for the navigation bar background.

 @since 5.0.0
*/
@property (nonatomic) UIImage *guestNavigationBarBackgroundImage;

/**
 The gradient colors used for the navigation bar background.

 @since 5.0.0
 */
@property (nonatomic) NSArray<UIColor *> *guestNavigationBarGradientColors;

/**
 The gradient stops used for the navigation bar background.

 @since 5.0.0
 */
@property (nonatomic) NSArray<NSNumber *> *guestNavigationBarGradientLocations;

/**
 The color used for the badge text.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestBadgeTextColor;

/**
 The color used for the badge background.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestBadgeBackgroundColor;

/**
 The color used for the `Add Another Guest` button text.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestAddAnotherButtonTextColor;

/**
 The color used for the `Send Invite` button text.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestSendInviteButtonTitleColor;

/**
 The color used for the `Send Invite` button background.

 @since 5.0.0
*/
@property (nonatomic) UIColor *guestSendInviteButtonBackgroundColor;

@end
