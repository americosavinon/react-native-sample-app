//
//  AWSDKStatePrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/27/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKState.h>

@class AWSDKCountry;
/**
 A physical state such as 'New York' or 'Michigan'.

 @since 1.0.0
 */
@interface AWSDKState : AWSDKDataObject <AWSDKState>
#pragma mark Constructor

+ (instancetype)state;

+ (NSArray<AWSDKState *> *)statesFromArray:(NSArray *)statesArray;

+ (NSArray<AWSDKState *> *)statesFromArray:(NSArray *)statesArray inCountry:(AWSDKCountry *)country;

@property (nonatomic, assign, getter=isLegalResidence) BOOL legalResidence;

@property (nonatomic, readwrite) AWSDKCountry *country;

- (void)updateCode:(NSString *)code;

@end
