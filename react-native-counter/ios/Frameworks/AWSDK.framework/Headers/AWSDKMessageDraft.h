//
//  AWSDKMessageDraft.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKConsumer, AWSDKInboxMessageDetails, AWSDKMessage, AWSDKContact, AWSDKMessageTopic, AWSDKAttachment;
// clang-format on

/**
 A message draft protocol.

 @since 3.1.0
 */
@protocol AWSDKMessageDraft <AWSDKDataObject>
#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 Creates a new instance of AWSDKMessageDraft with an empty body, subject, and recipient.

 @param consumer     AWSDKConsumer representing the sender of the message.
 @param completion   MessageDraftCompletionBlock containing the new AWSDKMessageDraft, otherwise an NSError explaining what went wrong.

 @since 1.0.0
 */
+ (void)createMessageDraftFromConsumer:(nonnull id<AWSDKConsumer>)consumer completion:(nonnull MessageDraftCompletionBlock)completion;

/**
 Creates a new instance of an AWSDKMessageDraft set up as a reply to a source message.

 @param sourceMessage    AWSDKInboxMessageDetails representing the original message being replied to.
 @param consumer         AWSDKConsumer whose account the message will be from.
 @param completion       MessageDraftCompletionBlock containing the new AWSDKMessageDraft, otherwise an NSError explaining what went wrong.

 @discussion This draft will have the source message's body with a separator indicating the start of the replied message. The source message's subject will be prepended with 'RE: ' and the recipient
 prepopulated with the source message sender.

 @note Only the body and the subject may be edited by the consumer.

 @since 1.0.0
 */
+ (void)createReplyDraftForMessage:(nonnull id<AWSDKInboxMessageDetails>)sourceMessage fromConsumer:(nonnull id<AWSDKConsumer>)consumer completion:(nonnull MessageDraftCompletionBlock)completion;

/**
 Creates a new instance of an AWSDKMessageDraft set up as a forward of a source message.

 @param sourceMessage    AWSDKInboxMessageDetails representing the original message being forwarded.
 @param consumer         AWSDKConsumer whose account the message will be from.
 @param completion       MessageDraftCompletionBlock containing the new AWSDKMessageDraft, otherwise an NSError explaining what went wrong.

 @discussion This draft will have the source message's body with a separator indicating the start of the forward body. The source message's subject will be prepended with 'FW: '.

 @note The AWSDKMessageTopic of the AWSDKMessageDraft must be the same as the sourceMessage.

 @since 1.0.0
 */
+ (void)createForwardDraftForMessage:(nonnull id<AWSDKMessage>)sourceMessage fromConsumer:(nonnull id<AWSDKConsumer>)consumer completion:(nonnull MessageDraftCompletionBlock)completion;

#pragma mark - Allowed Attachment Types
/**
 @name Allowed Attachment Types
 */

/**
 Retrives the whitelist of MIME types that are allowed as message attachments. No other MIME types will be allowed.

 @return The set of all white listed MIME types.

 @note As of 2.1.0, a whitelist for MIME types allowed is used instead of a blacklist for MIME types not allowed.

 @since 2.1.0
 */
+ (nonnull NSSet *)attachmentMIMETypeWhitelist;

#pragma mark Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKContact representing the user the message will be sent to.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKContact> recipient;

/**
 AWSDKMessageTopic representing the specified topic of the message.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKMessageTopic> topic;

/**
 AWSDKAttachment containing data, name, size, and type.

 @since 2.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKAttachment> draftAttachment;

/**
 NSArray of AWSDKAttachment objects attached to the source message.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKAttachment>> *sourceAttachments;

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSString representing the subject of the message.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *subject;

/**
 NSString representing the body of the message.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *messageBody;

/**
 Set _TRUE_ if the system should attach the consumer's health summary to the message, otherwise set _FALSE_ to not share the health summary.

 @since 1.0.0
 */
@property (readwrite, assign) BOOL shareHealthSummary;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Updates the chosen recipient for the message.

 @note This cannot be changed in the case of reply messages. This will send an AWSDKErrorCodeCannotChangeRecipient error.

 @param newRecipient AWSDKContact representing the new recipient of the message.
 @param completion   GenericCompletionBlock containing _TRUE_ if updating the recipient was successful, otherwise _FALSE_ and an NSError explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeCannotChangeRecipient     The recipient cannot be changed due to being a reply message where the recipient is fixed.

 @since 1.0.0
 */

- (void)updateRecipient:(nonnull id<AWSDKContact>)newRecipient withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Updates the current topic of the message.

 @param topic           AWSDKMessageTopic representing the new message topic to set.
 @param completion      GenericCompletionBlock containing _TRUE_ if updating the message topic was successful, otherwise _FALSE_ and an NSError explaining any failures.

 @since 1.0.0
 */
- (void)setTopic:(nonnull id<AWSDKMessageTopic>)topic withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Adds a new attachment to the message.

 @param attachmentData NSDate representing the attachment file.
 @param type           NSString representing the standard MIME type of the attachment.
 @param filename       NSString representing the filename of the attachment.
 @param completion     GenericCompletionBlock containing _TRUE_ if attachment successfully added, otherwise _FALSE_ and an NSError explaining any failures.

 @since 2.0.0
 */
- (void)addAttachmentData:(nonnull NSData *)attachmentData withMimeType:(nonnull NSString *)type withFilename:(nullable NSString *)filename completion:(nullable GenericCompletionBlock)completion;

/**
 Finds a file at a specified path and attaches the file to the message draft.

 @param filePath   NSString representing the full path to the specified file.
 @param completion GenericCompletionBlock containing _TRUE_ if attachment successfully added, otherwise _FALSE_ and an NSError explaining any failures.

 @since 1.0.0
 */
- (void)addAttachmentFromPath:(nonnull NSString *)filePath completion:(nullable GenericCompletionBlock)completion;

/**
 Clears any attachments of the message draft, if one exists.

 @since 1.0.0
 */
- (void)clearAttachment;

@end

/**
 A message draft to be sent.

 @since 1.0.0
 */
@interface AWSDKMessageDraft : AWSDKDataObject <AWSDKMessageDraft>

@end
