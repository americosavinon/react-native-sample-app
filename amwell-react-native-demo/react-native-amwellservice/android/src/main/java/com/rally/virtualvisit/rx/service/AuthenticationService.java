/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx.service;

import android.net.Uri;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.Authentication;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.exception.AWSDKInitializationException;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.SDKResponse;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link AWSDK} authentication calls and RxAndroid.
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
public class AuthenticationService extends BaseObservableService<AWSDK> {

    public AuthenticationService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected AWSDK getManager(AWSDK awsdk) {
        return awsdk;
    }

    public Observable<SDKResponse<Void, SDKError>> initializeSdk(
            @NonNull final String baseServiceUrl,
            @NonNull final String clientKey,
            @NonNull final Uri launchUri,
            @Nullable final UUID callerId) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        final Map<Integer, Object> initParams = new HashMap<>();
                        initParams.put(AWSDK.InitParam.BaseServiceUrl, baseServiceUrl);
                        initParams.put(AWSDK.InitParam.ApiKey, clientKey);
                        initParams.put(AWSDK.InitParam.LaunchIntentData, launchUri);
                        initParams.put(AWSDK.InitParam.CallerId, callerId);

                        try {
                            getManager().initialize(
                                    initParams,
                                    new ObservableEmitterSDKCallback(emitter, log)
                            );
                        }
                        catch (AWSDKInitializationException e) {
                            emitter.onError(e);
                        }
                    }
                }
        );
    }

    public Observable<SDKResponse<Authentication, SDKError>> authenticate(
            @NonNull final String email,
            @NonNull final String password) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Authentication, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Authentication, SDKError>> e) throws Exception {
                        getManager().authenticate(
                                email,
                                password,
                                new ObservableEmitterSDKCallback(e, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Authentication, SDKError>> thirdPartyAuthenticate(
            @NonNull final String authToken) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Authentication, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Authentication, SDKError>> emitter) throws Exception {
                        getManager().authenticateMutual(
                                authToken,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
