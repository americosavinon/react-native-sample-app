//
//  AWSDKAttachmentPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 7/26/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKAttachment.h>

/**
 Attachment with name, type, size and data.

 @note Replaced AWSDKMessageAttachment as of 2.0.0.

 @since 2.0.0
 */
@interface AWSDKAttachment : AWSDKDataObject <AWSDKAttachment>

+ (NSArray *)attachmentsFromArray:(NSArray *)array withAuthKey:(NSString *)consumerAuthKey;

@property (nonatomic) NSData *cachedData;

@property (nonatomic) NSString *consumerAuthKey;

- (void)setName:(NSString *)name;
- (void)setType:(NSString *)type;
- (void)setSize:(NSUInteger)size;

@end
