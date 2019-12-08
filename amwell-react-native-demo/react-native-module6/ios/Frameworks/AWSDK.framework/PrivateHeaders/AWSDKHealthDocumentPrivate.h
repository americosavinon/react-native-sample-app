//
//  AWSDKHealthDocumentPrivate.h
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

#import "AWSDKAttachmentPrivate.h"
#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKHealthDocument.h>

/**
 A health document containing an attachment.

 @since 2.0.0
 */
@interface AWSDKHealthDocument : AWSDKDataObject <AWSDKHealthDocument>

/**
 NSDate representing when the document was uploaded in the source system.

 @since 4.1.1
 */
@property (nonatomic, readonly, nonnull) NSDate *sourceRecordedDate;

// Not exposed with no way to populate it
@property (nonatomic, nullable) NSString *documentDescription;

@property (nonatomic, nullable) NSData *cachedData;

@property (nonatomic, nullable) NSString *consumerAuthKey;

+ (nonnull NSArray *)documentsFromArray:(nonnull NSArray *)array withAuthKey:(nonnull NSString *)consumerAuthKey;

@end
