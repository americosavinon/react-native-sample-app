/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit;

import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;

import androidx.annotation.LayoutRes;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.StringRes;

import com.google.android.material.textfield.TextInputLayout;

import androidx.fragment.app.DialogFragment;

import android.view.MenuItem;
import android.view.View;

import com.americanwell.sdk.entity.NamedSDKEntity;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.SDKPasswordError;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.util.ConfigurationWrapper;
import com.livefront.bridge.Bridge;
import com.rally.virtualvisit.app.AlertDialogResult;
import com.rally.virtualvisit.util.LocaleUtils;
import com.rally.virtualvisit.util.SampleNamedNothingSelectedSpinnerAdapter;
import com.rally.virtualvisit.util.SampleUtils;
import com.rally.virtualvisit.util.FileUtils;

import java.net.ConnectException;
import java.net.HttpURLConnection;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import javax.inject.Inject;

import butterknife.ButterKnife;
import icepick.State;
import nucleus5.view.NucleusAppCompatActivity;

import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_DEFAULT;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.FATAL_EVENT;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.FINISH;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.GOTO_LOGIN;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.GO_HOME;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.NO_ACTION;

/**
 * Base class for all activities in this application provides some common implementation and
 * extends the use of the Nucleus MVP library (https://github.com/konmik/nucleus)
 */
public abstract class BaseSampleNucleusActivity<P extends BaseSampleNucleusRxPresenter> extends NucleusAppCompatActivity<P> {

    private static final String LOG_TAG = BaseSampleNucleusActivity.class.getName();

    protected static final int PROGRESS_DIALOG_DELAY_MS = 500;

    protected static Locale preferredLocale = Locale.getDefault();

    @Inject
    protected SampleUtils sampleUtils; // provides this to all child classes
    @Inject
    FileUtils fileUtils; // this one's just used here.  other activities can inject independently
    @Inject
    protected AWSDKLogger logger; // provides a logger for all child classes

//    @Nullable
//    @BindView(R.id.toolbar)
//    protected Toolbar toolbar; // common toolbar storage
//    @Nullable
//    @BindView(R.id.fab)
//    protected FloatingActionButton fab; // common fab storage

//    @BindString(R.string.app_default_indeterminate)
//    String indeterminate;

    // This count is to keep track of how many "things" (aka asynchronous requests) are currently
    // being waited for.  typically controlled by the presenter, a call to setSomethingIsBusy(true) will increment
    // the counter, while a call with the parameter as "false" will decrement.
    // this count is used to show and hide the progress bar.  (the progress bar paradigm can be overridden in the
    // activity if there's a different way to show the "waiting" mode)
    @State
    int busyCount = 0;

    // default standard progress dialog, will say "Please wait..."
    private ProgressDialog progressDialog;
    protected Dialog datePickerDialog;
    protected LocaleUtils localeUtils;

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        boolean forcePortrait = getResources().getBoolean(0);
        if (forcePortrait) {
            getLogger(this).d(LOG_TAG, "forced video to portrait orientation as per config");
            setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        }
        // use Icepick to save/restore state
        Bridge.restoreInstanceState(this, savedInstanceState);
    }

    @Override
    protected void onResume() {
        super.onResume();
        progressDialog = new ProgressDialog(this); // instantiate the progress bar
//        progressDialog.setMessage(indeterminate);
        progressDialog.setIndeterminate(true);
        progressDialog.setCancelable(false);
        showBusy(busyCount > 0); // this will put the progress bar back up on rotate, if necessary
    }

    @Override
    protected void onPause() {
        super.onPause();
        showBusy(false); // hide the progressbar to avoid hanging on to resources, etc
        dismissDialogs();
    }

    protected void dismissDialogs() {
        dismissDialog(progressDialog);
        dismissDialog(datePickerDialog);
    }

    protected void dismissDialog(Dialog dialog) {
        if (dialog != null) {
            dialog.dismiss();
        }
    }

    protected void dismissDialog(DialogFragment dialog) {
        if (dialog != null) {
            dialog.dismiss();
        }
    }

    @Override
    public void setContentView(@LayoutRes int layoutResID) {
        super.setContentView(layoutResID);
        ButterKnife.bind(this); // use Butterknife to bind the activity views
//        if (toolbar != null) {
//            setSupportActionBar(toolbar);
//            getSupportActionBar().setDisplayHomeAsUpEnabled(showBackButton());
//        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home: // generic back-arrow handling - just make it do what the back button does
                onBackPressed();
                return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        Bridge.saveInstanceState(this, outState); // always use icepick to save state
    }

    // Validation and Error Handling methods

    /**
     * Call this if validation fails
     *
     * @param validationReasons
     */
    public void setValidationReasons(@Nullable final Map<String, String> validationReasons) {
        sampleUtils.handleValidationFailures(this, getValidationViews(), validationReasons);
    }

    /**
     * Call this if validation fails
     *
     * @param validationReasons
     * @param resultCode
     */
    public void setValidationReasons(@Nullable final Map<String, String> validationReasons,
                                     final @com.rally.virtualvisit.app.AlertDialogResult.Action int resultCode) {
        sampleUtils.handleValidationFailures(
                this, getValidationViews(), validationReasons, resultCode);
    }

    /**
     * When dealing with a SDKValidatedCallback, you may get an array of key/value pairs with
     * validation failures.  There is standard handling for this in sampleUtils.  If you return
     * a Map of the expected keys to views in your UI, the standard handling will call 'setError' on
     * the views.  otherwise the default handling is a pop-up dialog.
     *
     * @return
     */
    protected Map<String, View> getValidationViews() {
        return null; // override if you have any
    }

    public void setError(@NonNull final SDKError error) {
        setNothingIsBusy();
        if (error.getHttpResponseCode() == HttpURLConnection.HTTP_UNAUTHORIZED) {
            handleAuthError(error);
        }
        else {
            sampleUtils.handleError(this, error);
        }
    }

    public void setPasswordError(@NonNull final SDKPasswordError passwordError) {
        setNothingIsBusy();
        if (passwordError.getHttpResponseCode() == HttpURLConnection.HTTP_UNAUTHORIZED) {
            handleAuthError(passwordError);
        }
        else {
            sampleUtils.handleError(this, passwordError);
        }
    }

    public void setError(@NonNull final Throwable throwable) {
        setNothingIsBusy();
        sampleUtils.handleError(this, throwable);
    }

    public void setError(@NonNull final String title,
                         @NonNull final String message) {
        setNothingIsBusy();
        sampleUtils.handleError(this, title, message);
    }

    /**
     * Whether or not to show a progress bar with a cyclic animation without an indication of
     * progress.
     */
    public void setSomethingIsBusy(final boolean busy) {
        if (busy) {
            busyCount++;
        }
        else if (busyCount > 0) {
            busyCount--;
        }
        logger.d(LOG_TAG, "setting busy to " + busy + ". count = " + busyCount);
        showBusy(busyCount > 0);
    }

    // Runnable for displaying the progress dialog
    final Runnable busyTimerRunnable = new Runnable() {
        @Override
        public void run() {
            if (busyCount > 0) {
                progressDialog.show();
            }
        }
    };
    final Handler busyTimer = new Handler(Looper.getMainLooper());

    /**
     * default behavior for showBusy(), which is to put up the progress dialog
     * override this if your activity has different requirements
     *
     * @param show
     */
    protected void showBusy(final boolean show) {
        if (show) {
            if (progressDialog != null && !progressDialog.isShowing()) {
                // set up a timer to show the progress dialog
                busyTimer.postDelayed(busyTimerRunnable, PROGRESS_DIALOG_DELAY_MS);
            }
        }
        else {
            busyTimer.removeCallbacks(busyTimerRunnable);
            if (progressDialog != null) {
                progressDialog.dismiss();
            }
        }
    }

    /**
     * clear out the busy count and hide the busy business
     */
    public void setNothingIsBusy() {
        busyCount = 0;
        showBusy(false);
    }

    /**
     * presenter will call this if there's an error
     *
     * @param throwable
     */
    public void onFailure(@NonNull Throwable throwable) {
        setNothingIsBusy();

        // This demonstrates on possible (rudimentary) way to handle the case when the server is
        // unavailable.  If we are thrown a ConnectException, rather than having a series of
        // errors, or a crash downstream, we redirect back to the login page... which will also
        // error with a ConnectException until the server is available.  There are certainly more
        // elegant ways to deal with the ConnectException - but this will at least avoid crashes.
        int resultCode = (throwable instanceof ConnectException) ? GOTO_LOGIN : NO_ACTION;
        sampleUtils.handleError(this, throwable, resultCode);
    }

    protected void setTextViewError(final boolean bIsError,
                                    @NonNull final TextInputLayout view,
                                    @StringRes final int resId) {
        if (bIsError) {
            setSomethingIsBusy(false);
            view.setError(getString(resId));
            view.requestFocus();
        }
        else {
            view.setError(null);
        }
    }


    // show an error and then go home
    public void handleFatalError(final SDKError sdkError) {
        setNothingIsBusy();
        int errorCode = sdkError.getHttpResponseCode();
        if (HttpURLConnection.HTTP_UNAUTHORIZED == errorCode) {
            handleAuthError(sdkError);
        }
        else {
            sampleUtils.handleError(this, sdkError, GO_HOME);
        }
    }

    // show an error and then go home
    public void handleFatalError(final Throwable throwable) {
        setNothingIsBusy();
        sampleUtils.handleError(this, throwable, GO_HOME);
    }

    public void handleAuthError(final SDKError sdkError) {
        sampleUtils.handleAuthError(this, sdkError, GOTO_LOGIN);
    }

    public void handleFatalEvent() {
        sampleUtils.handleFatalEvent(this, FATAL_EVENT);
    }

    // show an error and finish
    public void handleErrorAndFinish(final SDKError sdkError) {
        setNothingIsBusy();
        sampleUtils.handleError(this, sdkError, FINISH);
    }

    protected SampleNamedNothingSelectedSpinnerAdapter populateAdapter(
            @Nullable List<? extends NamedSDKEntity> list,
            @LayoutRes final int resLayout) {

        return new SampleNamedNothingSelectedSpinnerAdapter(
                this,
                list == null ? new ArrayList() : list,
                resLayout);
    }

    protected SampleNamedNothingSelectedSpinnerAdapter populateAdapter(
            @Nullable List<? extends NamedSDKEntity> list,
            @LayoutRes final int resLayout,
            boolean displayNothingSelectedOnEmpty) {

        return new SampleNamedNothingSelectedSpinnerAdapter(
                this,
                list == null ? new ArrayList() : list,
                resLayout, displayNothingSelectedOnEmpty);
    }

    protected boolean showBackButton() {
        return true;
    }

    @Override
    protected void attachBaseContext(Context newBase) {
        // this code demonstrates a mechanism for overriding the Locale for resource retrieval
        // for example, if the device is in English, but we want it to be in Spanish
        // this will take the "preferred locale" from the AWSDK and force the Context to use it
        getLogger(newBase).d(LOG_TAG, "attaching base context");
        super.attachBaseContext(ConfigurationWrapper.wrapLocale(newBase, preferredLocale));
    }

    /**
     * Need to provide a mechanism to get the logger internally as inject()
     * may not have been called in this abstract base class.
     */
    private AWSDKLogger getLogger(Context ctx) {
        // return ((SampleApplication) ctx.getApplicationContext()).getAWSDK().getDefaultLogger();
        return null;
    }

    public void onDialogResult(@AlertDialogResult.Action int resultCode, int whichButton) {
        switch (resultCode) {
            case GO_HOME:
                // goHome();
                break;
            case FINISH:
                finish();
                break;
            case GOTO_LOGIN:
            case FATAL_EVENT:
                // logOut();
                break;
            case NO_ACTION:
                getLogger(this).w(LOG_CATEGORY_DEFAULT, LOG_TAG, "Dialog dismissed. No action required");
                break;
            default:
                getLogger(this).w(LOG_CATEGORY_DEFAULT, LOG_TAG, "Unhandled dialog result.");
                break;
        }
    }

    public AWSDKLogger getDefaultLogger() {
        return logger;
    }

    public void setPreferredLocale(@NonNull final Locale locale) {
        preferredLocale = locale;
    }

    protected void setLocaleUtils(final LocaleUtils localeUtils) {
        this.localeUtils = localeUtils;
    }
}