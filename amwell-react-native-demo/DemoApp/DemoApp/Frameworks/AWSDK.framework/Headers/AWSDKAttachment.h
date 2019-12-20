//
//  AWSDKAttachment.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 Attachment protocol with name, type, size and data.

 @since 3.1.0
 */
@protocol AWSDKAttachment <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString name of the attachment.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString attachment type represented as a mime type.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *type;

/**
 NSUInteger size of the attachment in bytes.
 */
@property (readonly) NSUInteger size;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the attachment data.

 @param completion DataResultCompletionBlock containing the attachment as NSData, or an NSError with failure details.

 @since 2.0.0
 */
- (void)fetchAttachmentAsData:(nullable DataResultCompletionBlock)completion;
@end
