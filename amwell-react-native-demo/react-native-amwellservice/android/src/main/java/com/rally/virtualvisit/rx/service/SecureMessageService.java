/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx.service;

import androidx.annotation.NonNull;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.AttachmentReference;
import com.americanwell.sdk.entity.FileAttachment;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.securemessage.detail.MessageDetail;
import com.americanwell.sdk.entity.securemessage.detail.MessageDraft;
import com.americanwell.sdk.entity.securemessage.detail.SecureMessageContact;
import com.americanwell.sdk.entity.securemessage.mailbox.Inbox;
import com.americanwell.sdk.entity.securemessage.mailbox.InboxMessage;
import com.americanwell.sdk.entity.securemessage.mailbox.MailboxMessage;
import com.americanwell.sdk.entity.securemessage.mailbox.SentMessages;
import com.americanwell.sdk.manager.SecureMessageManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;


import java.util.List;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link SecureMessageManager} calls and RxAndroid.
 * Provides Observable wrappers for all calls.
 * <p>
 * This is just one way of handling this, one which we think is a good practice. The use of
 * RxAndroid here, in combination with an MVP framework such as Nucleus, allows for nice handling
 * of long-running asynchronous requests - detached from the tricks of the Activity lifecycle.
 * If you have a preferred pattern, of course give it a try.
 * <p>
 * The ObservableEmitter for the Observable is passed into one of several variations of
 * ObservableEmitterSDKCallback which handles the callback methods and delegates to the ObservableEmitter methods
 */
public class SecureMessageService extends BaseObservableService<SecureMessageManager> {

    public SecureMessageService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected SecureMessageManager getManager(AWSDK awsdk) {
        return awsdk.getSecureMessageManager();
    }

    // secure messaging
    public Observable<SDKResponse<Inbox, SDKError>> getInbox(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Inbox, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Inbox, SDKError>> emitter) throws Exception {
                        getManager().getInbox(
                                consumer,
                                null,
                                SecureMessageManager.GET_ALL_MESSAGES,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<MessageDetail, SDKError>> removeMessage(
            @NonNull final Consumer consumer,
            @NonNull final MailboxMessage message) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<MessageDetail, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<MessageDetail, SDKError>> emitter) throws Exception {
                        getManager().removeMessage(
                                consumer,
                                message,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<SentMessages, SDKError>> getSentMessages(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<SentMessages, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<SentMessages, SDKError>> emitter) throws Exception {
                        getManager().getSentMessages(
                                consumer,
                                null,
                                SecureMessageManager.GET_ALL_MESSAGES,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<MessageDetail, SDKError>> getMessageDetail(
            @NonNull final Consumer consumer,
            @NonNull final MailboxMessage mailboxMessage) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<MessageDetail, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<MessageDetail, SDKError>> emitter) throws Exception {
                        getManager().getMessageDetail(
                                consumer,
                                mailboxMessage,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }


    public Observable<SDKResponse<MessageDetail, SDKError>> updateMessageRead(
            @NonNull final InboxMessage inboxMessage) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<MessageDetail, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<MessageDetail, SDKError>> emitter) throws Exception {
                        getManager().updateMessageRead(
                                inboxMessage,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<FileAttachment, SDKError>> getAttachment(
            @NonNull final Consumer consumer,
            @NonNull final AttachmentReference attachmentReference) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<FileAttachment, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<FileAttachment, SDKError>> emitter) throws Exception {
                        getManager().getAttachment(
                                consumer,
                                attachmentReference,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<MessageDetail, SDKError>> removeMessage(
            @NonNull final Consumer consumer,
            @NonNull final MessageDetail messageDetail) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<MessageDetail, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<MessageDetail, SDKError>> emitter) throws Exception {
                        getManager().removeMessage(
                                consumer,
                                messageDetail,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<SecureMessageContact>, SDKError>> getContacts(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<SecureMessageContact>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<SecureMessageContact>, SDKError>> emitter) throws Exception {
                        getManager().getContacts(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> sendMessage(
            @NonNull final Consumer consumer,
            @NonNull final MessageDraft messageDraft) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().sendMessage(
                                consumer,
                                messageDraft,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
