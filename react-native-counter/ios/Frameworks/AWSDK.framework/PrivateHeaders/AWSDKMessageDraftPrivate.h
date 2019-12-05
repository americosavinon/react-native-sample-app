//
//  AWSDKMessageDraftPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/21/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKMessageDraft.h>

@interface AWSDKMessageDraft ()

@property (nonatomic, readonly) NSString *actionType;

@property (nonatomic, readonly) NSString *sourceMessageId;

@property (nonatomic, readonly) NSString *sourceMessageType;

@property (nonatomic, readonly) NSString *consumerId;

//@property (nonatomic, readonly) NSString *mimeType;

- (BOOL)isValid;

- (NSDictionary *)toParams;

@end
