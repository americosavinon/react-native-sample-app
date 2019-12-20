//
//  AWSDKHealthDocument.h
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

@protocol AWSDKAttachment;

/**
 A health document protocol containing an attachment.

 @since 3.1.0
 */
@protocol AWSDKHealthDocument <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the supplied name of the document.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString representing the sourceId of the document.

 @since 4.1.1
 */
@property (nonatomic, readonly, nullable) NSString *sourceId;

/**
 NSDate representing the date the document was uploaded.

 @since 4.1.1
 */
@property (nonatomic, readonly, nonnull) NSDate *uploadDate;

/**
 AWSDKAttachment used to fetch the attachment data.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKAttachment> attachment;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Removes the AWSDKHealthDocument from the given consumer's profile.

 @param completion GenericCompletionBlock containing _TRUE_ if the health document was successfully removed, otherwise _FALSE_ and an NSError explaining any failures.

 @since 2.0.0
 */
- (void)removeHealthDocumentWithCompletion:(nullable GenericCompletionBlock)completion;

@end
