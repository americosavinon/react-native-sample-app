//
//  AWSDKMessageFolderPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 1/11/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKMessageFolder.h>

@class AWSDKConsumer;

/**
 Message folder used by AWSDKMessageFolderInbox and AWSDKMessageFolderSent

 @since 1.0.0
 */
@interface AWSDKMessageFolder : AWSDKDataObject <AWSDKMessageFolder>

@property (nonatomic) AWSDKConsumer *consumer;

- (void)mergeMessageArray:(NSArray *)newMessages;

- (void)updateMessages:(NSArray *)newMesssages;

- (void)overrideMessages:(NSArray *)newMesssages;

@end
