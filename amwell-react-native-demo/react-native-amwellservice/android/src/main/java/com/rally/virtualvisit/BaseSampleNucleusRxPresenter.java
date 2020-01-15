/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit;

import android.content.Intent;
import android.os.Bundle;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.*;
import com.americanwell.sdk.entity.consumer.BiologicalSex;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.consumer.Gender;
import com.americanwell.sdk.entity.consumer.GenderIdentity;
import com.americanwell.sdk.entity.provider.Provider;
import com.americanwell.sdk.entity.visit.ChatReport;
import com.americanwell.sdk.entity.visit.ConsumerInitiatedIVRStatus;
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.entity.visit.VisitContext;
import com.americanwell.sdk.entity.visit.VisitEndReason;
import com.rally.virtualvisit.rx.SDKIVRResponse;
import com.rally.virtualvisit.rx.SDKMatchmakerResponse;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKStartConferenceResponse;
import com.rally.virtualvisit.rx.SDKStartVisitResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;
import com.rally.virtualvisit.rx.SDKVisitTransferResponse;
import com.rally.virtualvisit.util.GenderUtil;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.PracticeProvidersManager;

import com.livefront.bridge.Bridge;
import com.rally.virtualvisit.util.LocaleUtils;
import com.rally.virtualvisit.util.StateUtils;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import javax.inject.Inject;

import io.reactivex.Observable;
import io.reactivex.functions.BiConsumer;
import nucleus5.presenter.Factory;
import nucleus5.presenter.RxPresenter;

/**
 * Base Nucleus Rx Presenter class for all Presenters
 */
public abstract class BaseSampleNucleusRxPresenter<V extends BaseSampleNucleusActivity> extends RxPresenter<V> {

    @Inject
    protected AWSDK awsdk;
    @Inject
    protected StateUtils stateUtils;
    @Inject
    protected AWSDKLogger logger; // provides a logger for all child classes

    @icepick.State
    protected ArrayList<Consumer> dependents;
    @icepick.State
    protected Consumer consumer;
    @icepick.State
    protected Consumer loginConsumer;

    protected V view; // make the view generally available.
    // it's not always available to make sure to check for nulls
    // unless you can be certain it will be populated at the point in the
    // lifecycle you expect

    protected LocaleUtils localeUtils;

    @Override
    public void onCreate(@Nullable Bundle savedState) {
        super.onCreate(savedState);
        // restore the awsdk instance state directly into the dagger component so the injection won't fail
        // without this, it can error injecting the managers in certain circumstances

        // SampleApplication.getPresenterComponent().awsdk().restoreInstanceState(savedState);

        injectPresenter();
        Bridge.restoreInstanceState(this, savedState);

        if (loginConsumer == null) {
            loginConsumer = stateUtils.getLoginConsumer();
        }
        else {
            stateUtils.setLoginConsumer(loginConsumer);
        }

        // all presenters have access to the current and logged in consumer
        if (consumer == null) {
            consumer = stateUtils.getConsumer();
        }
        else {
            stateUtils.setConsumer(consumer);
        }

        // all presenters have access to the dependents of the current and logged in consumer
        if (dependents == null) {
            dependents = stateUtils.getDependents();
        }
        else {
            stateUtils.setDependents(dependents);
        }
    }

    // each presenter must override this - even though the override code is always exactly the same
    // we need the specific "this" instance
    protected abstract void injectPresenter();

    @Override
    public void onSave(@NonNull Bundle state) {
        super.onSave(state);
        awsdk.saveInstanceState(state); // the AWSDK instance can have it's state restored here
        // without this you may get "sdk initialization is missing" errors
        // if the app is destroyed and recreated
        Bridge.saveInstanceState(this, state);
    }

    @Override
    public void onTakeView(V view) {
        this.view = view; // here's where we grab the view (activity) and make it available.
        super.onTakeView(view);

        localeUtils = new LocaleUtils(getPreferredLocale(), view.getResources());
        view.setLocaleUtils(localeUtils);
    }

    public void logOut() {
        awsdk.clearAuthentication();
    }

    protected boolean shouldBeInitialized() {
        return true;
    }

    protected boolean shouldHaveConsumer() {
        return true;
    }

    // Returns a list of "valid" (legal residence) states for a given country
    public List<State> getEnrollmentStates(@NonNull final Country country) {
        return awsdk.getConsumerManager().getEnrollmentStates(country);
    }

    // Return a list of states for a given country
    public List<State> getStates(@NonNull final Country country) {
        return awsdk.getStates(country);
    }

    // return a List of system supported countries
    public List<Country> getSupportedCountries() {
        return awsdk.getSupportedCountries();
    }

    // return if system supports multi-country
    public boolean isMultiCountry() {
        return awsdk.getConfiguration().isMultiCountry();
    }

    // return List of system supported Locales
    protected List<Locale> getSupportedLocales() {
        return awsdk.getSupportedLocales();
    }

    // return if system supports multiple Locales
    protected boolean isMultiLocale() {
        return awsdk.getSupportedLocales().size() > 1;
    }

    // return a List of valid payment states
    public List<State> getValidPaymentMethodStates(final Country country) {
        return awsdk.getConsumerPaymentManager().getValidPaymentMethodStates(country);
    }

    // return a List of valid enrollment states based on determined country
    protected List<State> getPopulatorEnrollmentStates(final Country country) {
        // use default country when one is not previously populated
        final Country c = (country == null) ? getSupportedCountries().get(0) : country;
        return (isMultiCountry() && country == null) ?
                new ArrayList<State>() :
                this.getEnrollmentStates(c);
    }

    // return a List of valid payment states based on determined country
    protected List<State> getPopulatorPaymentStates(final Country country) {
        // use default country when one is not previously populated
        final Country c = (country == null) ? getSupportedCountries().get(0) : country;
        return (isMultiCountry() && country == null) ?
                new ArrayList<State>() :
                this.getValidPaymentMethodStates(c);
    }

    protected List<BiologicalSex> getSupportedBiologicalSexes() {
        final SystemConfiguration sysConfig = awsdk.getConfiguration();
        if(sysConfig.isGenderSupportEnabled()) {
            return sysConfig.getBiologicalSexes();
        }
        else {
            return GenderUtil.getDefaultBiologicalSexes(view);
        }
    }

    protected List<GenderIdentity> getSupportedGenderIdentities() {
        return awsdk.getConfiguration().getGenderIdentities();
    }

    public int getFilteredBiologicalSexIndex(final @Gender String genderKey) {
        return GenderUtil.getFilteredBiologicalSexIndex(view, awsdk.getConfiguration(), genderKey);
    }

    public int getSelectedGenderIdentityIndex(final String genderIdentityKey) {
        return GenderUtil.getSelectedGenderIdentityIndex(view, awsdk.getConfiguration(), genderIdentityKey);
    }

    // successfully fetched the dependents
    protected void setDependents(final ArrayList<Consumer> dependents) {
        if (dependents != null) {
            Collections.sort(dependents, new Comparator<Consumer>() {
                @Override
                public int compare(Consumer c1, Consumer c2) {
                    return c1.getFullName().compareToIgnoreCase(c2.getFullName());
                }
            });
        }
        this.dependents = dependents;
        stateUtils.setDependents(dependents);
    }

    // try not to use this, it's a special case for getting access to the manager in ProviderView
    public PracticeProvidersManager getPracticeProvidersManager() {
        return awsdk.getPracticeProvidersManager();
    }

    // get the preferred locale
    public Locale getPreferredLocale() {
        return awsdk.getPreferredLocale();
    }

    public LocaleUtils getLocaleUtils() {
        return localeUtils;
    }

    // formats a time stamp using preferred Locale
    public String formatTimeStamp(long timeStamp) {
        return localeUtils.formatTimeStamp(timeStamp);
    }

    // below are helper classes for the Nucleus Rx request calls
    // these are part of the RxJava / Nucleus implementation being used to handle the asynchronous network
    // requests.
    // the wrappers found in the "rx" package will place the various responses inside SDKResponse classes (or derivatives thereof).
    // These methods below provide common handling for the responses and errors

    // This implements Nucleus' Factory interface  and is used to provide common handling for all request submissions
    // all it really does is provide base implementation to always turn on the "busy" view when a
    // request starts
    public abstract class SampleRequestFactory<R extends SDKResponse> implements Factory<Observable<R>> {
        protected Integer requestId;

        public SampleRequestFactory(int requestId) {
            this.requestId = requestId;
        }

        @Override
        public Observable<R> create() {
            logger.d(this.getClass().getName(), "calling request. requestId = " + requestId);
            if (view != null) { // if the request is submitted before onTakeView() - view will be null - and spinner won't appear
                view.setSomethingIsBusy(true);  // launch the progress dialog or spinner, etc
            }
            return go();
        }

        public abstract Observable<R> go();
    }

    // this is a sample BiConsumer for successful responses in the simple "SDKResponse" case
    // turns the "busy" view off, handles a "graceful" server-provided error, if exists, otherwise
    // calls the custom "onSuccess" handler in the presenter
    public abstract class SampleResponseBiConsumer<C, E extends SDKError, R extends SDKResponse<C, E>>
            implements BiConsumer<V, R> {
        protected Integer requestId;

        public SampleResponseBiConsumer(int requestId) {
            this.requestId = requestId;
        }

        @Override
        public void accept(V v, R r) {
            v.setSomethingIsBusy(false);
            if (r.getError() != null) {
                logger.d(this.getClass().getName(), "handling error response. requestId = " + requestId);
                onError(v, r.getError());
            }
            else {
                logger.d(this.getClass().getName(), "handling success response. requestId = " + requestId);
                onSuccess(v, r.getResult());
            }
        }

        public abstract void onSuccess(V v, C c);

        public void onError(V v, E e) {
            if (requestId != null) {
                stop(requestId); // stop the request on error so we don't restart it.
                // this may not necessarily be the behavior you want in a production app
                // if you want to retry things, you may not want to stop it in this may
                // for the context of this sample application, however, it's fine.
            }
            v.setError(e);
        }
    }

    // similar to above, but adds support for the SDKPasswordError
    public abstract class SamplePasswordResponseBiConsumer<
            C,
            E extends SDKPasswordError,
            R extends SDKResponse<C, E>>
            extends SampleResponseBiConsumer<C, E, R> {
        public SamplePasswordResponseBiConsumer(int requestId) {
            super(requestId);
        }

        public void onError(V v, E e) {
            if (requestId != null) {
                stop(requestId); // stop the request on error so we don't restart it.
                // this may not necessarily be the behavior you want in a production app
                // if you want to retry things, you may not want to stop it in this may
                // for the context of this sample application, however, it's fine.
            }
            v.setPasswordError(e);
        }
    }

    // similar to above, but adds support for the SDKValidatedResponse
    public abstract class SampleValidatedResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKValidatedResponse<C, E>>
            extends SampleResponseBiConsumer<C, E, R> {
        public SampleValidatedResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            if (r.getValidationReasons() != null) {
                logger.d(this.getClass().getName(), "handling validation. requestId = " + requestId);
                onValidationFailures(v, r.getValidationReasons());
            }
            else {
                super.accept(v, r);
            }
        }

        public void onValidationFailures(V v, Map<String, String> reasons) {
            if (requestId != null) {
                stop(requestId); // stop the request on error so we don't restart it.
                // this may not necessarily be the behavior you want in a production app
                // if you want to retry things, you may not want to stop it in this may
                // for the context of this sample application, however, it's fine.
            }
            v.setSomethingIsBusy(false); // turn off spinner
            v.setValidationReasons(reasons); // pass the validation reasons to the UI
        }
    }

    // similar to above but adds support for the SDKPasswordError
    public abstract class SampleValidatedPasswordResponseBiConsumer<
            C,
            E extends SDKPasswordError,
            R extends SDKValidatedResponse<C, E>>
            extends SampleValidatedResponseBiConsumer<C, E, R> {
        public SampleValidatedPasswordResponseBiConsumer(int requestId) {
            super(requestId);
        }

        public void onError(V v, E e) {
            if (requestId != null) {
                stop(requestId); // stop the request on error so we don't restart it.
                // this may not necessarily be the behavior you want in a production app
                // if you want to retry things, you may not want to stop it in this may
                // for the context of this sample application, however, it's fine.
            }
            v.setPasswordError(e);
        }
    }

    // similar to above but adds support for the SDKStartVisitResponse
    public abstract class SampleStartVisitResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKStartVisitResponse<C, E>>
            extends SampleValidatedResponseBiConsumer<C, E, R> {
        public SampleStartVisitResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            if (r.getIntent() != null) {
                logger.d(this.getClass().getName(), "handling intent. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onProviderEntered(v, r.getIntent());
            }
            else if (r.getVisitEndReason() != null) {
                logger.d(this.getClass().getName(), "handling visit end response. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onWaitingRoomEnded(v, r.getVisitEndReason());
            }
            else if (r.getPatientsAheadOfYou() > -1) {
                logger.d(this.getClass().getName(), "handling patients ahead count. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onPatientsAheadOfYouCountChanged(v, r.getPatientsAheadOfYou());
            }
            else if (r.isSuggestedTransfer()) { // since AWSDK 2.1
                logger.d(this.getClass().getName(), "handling suggested transfer. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onSuggestedTransfer(v);
            }
            else if (r.isSuggestFindFirstAvailable()) { // since AWSDK 4.1
                logger.d(this.getClass().getName(), "handling suggest Find First Available. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onSuggestFindFirstAvailable(v);
            }
            else if (r.getChatReport() != null) { // since AWSDK 2.1
                logger.d(this.getClass().getName(), "handling chat report. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onChat(v, r.getChatReport());
            }
            else {
                super.accept(v, r);
            }
        }

        @Override
        public void onSuccess(V v, C c) {
        }

        public abstract void onProviderEntered(V v, Intent intent);

        public abstract void onWaitingRoomEnded(V v, @VisitEndReason String visitEndReason);

        public abstract void onPatientsAheadOfYouCountChanged(V v, int count);

        public abstract void onSuggestedTransfer(V v); // since AWSDK 2.1

        public abstract void onSuggestFindFirstAvailable(V v); // since AWSDK 4.1

        public abstract void onChat(V v, ChatReport chatReport); // since AWSDK 2.1
    }

    // similar to above but adds support for the SDKMatchmakerResponse
    public abstract class SampleMatchmakerResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKMatchmakerResponse<C, E>>
            extends SampleResponseBiConsumer<C, E, R> {
        public SampleMatchmakerResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            if (r.getProvider() != null) {
                logger.d(this.getClass().getName(), "handling provider accepted response. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onProviderAccepted(v, r.getProvider());
            }
            else if (r.isProviderListExhausted()) {
                logger.d(this.getClass().getName(), "handling provider exhausted response. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onProviderListExhausted(v);
            }
            else if (r.isRequestGone()) {
                logger.d(this.getClass().getName(), "handling request gone response. requestId = " + requestId);
                v.setSomethingIsBusy(false);
                onRequestGone(v);
            }
            else {
                super.accept(v, r);
            }
        }

        @Override
        public void onSuccess(V v, C c) {
        }

        public abstract void onProviderAccepted(V v, Provider provider);

        public abstract void onProviderListExhausted(V v);

        public abstract void onRequestGone(V v);
    }

    public abstract class SampleStartConferenceResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKStartConferenceResponse<C, E>>
            extends SampleResponseBiConsumer<C, E, R> {
        public SampleStartConferenceResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            view.setSomethingIsBusy(false);
            if (r.getIntent() != null) {
                onConferenceReady(v, r.getIntent());
            }
            else if (r.isConferenceCanceled()) {
                onConferenceCanceled(v);
            }
            else if (r.isConferenceEnded()) {
                onConferenceEnded(v);
            }
            else {
                super.accept(v, r);
            }
        }

        @Override
        public void onSuccess(V v, C c) {
        }

        public abstract void onConferenceReady(V v, Intent intent);

        public abstract void onConferenceCanceled(V v);

        public abstract void onConferenceEnded(V v);
    }


    // this provides common failure handling
    public class SampleFailureBiConsumer implements BiConsumer<V, Throwable> {
        protected Integer requestId;

        public SampleFailureBiConsumer(int requestId) {
            this.requestId = requestId;
        }

        @Override
        public void accept(V v, Throwable throwable) {
            logger.d(this.getClass().getName(), "handling failure response. requestId = " + requestId);
            v.setSomethingIsBusy(false);
            onFailure(v, throwable);
        }

        public void onFailure(final V v, final Throwable throwable) { // override this if you want to do something different
            v.onFailure(throwable); // tell the activity about the failure, in the case of the sample app, we have common failure handling
        }
    }

    // similar to above, but adds support for the SDKVisitTransferResponse
    public abstract class SampleVisitTransferResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKVisitTransferResponse<C, E>>
            extends SampleResponseBiConsumer<C, E, R> {
        public SampleVisitTransferResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            if (r.getVisitRedirect() != null) {
                onVisitTransfer(r.getVisitRedirect());
            }
            else if (r.getVisitContext() != null) {
                onNewVisitContext(r.getVisitContext());
            }
            else if (r.isProviderUnavailable() == true) {
                onProviderUnavailable();
            }
            else if (r.getNewVisit() != null) {
                onStartNewVisit(r.getNewVisit());
            }
            else {
                super.accept(v, r);
            }
        }

        @Override
        public void onSuccess(V v, C c) {
            // no-op default behavior
        }

        public abstract void onVisitTransfer(Visit visit);

        public abstract void onProviderUnavailable();

        public abstract void onStartNewVisit(Visit visit);

        public abstract void onNewVisitContext(VisitContext visitContext);
    }

    // similar to above but adds support for the SDKStartVisitResponse
    public abstract class SampleIVRResponseBiConsumer<
            C,
            E extends SDKError,
            R extends SDKIVRResponse<C, E>>
            extends SampleValidatedResponseBiConsumer<C, E, R> {
        public SampleIVRResponseBiConsumer(int requestId) {
            super(requestId);
        }

        @Override
        public void accept(V v, R r) {
            @ConsumerInitiatedIVRStatus
            String status = r.getStatus();
            int retryCount = r.getRetryCount();
            onUpdate(v, status, retryCount);
        }

        @Override
        public void onSuccess(V v, C c) {
        }

        public abstract void onUpdate(V v, @ConsumerInitiatedIVRStatus String status, int retryCount);
    }
}
