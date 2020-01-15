/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.util;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.os.Build;

import androidx.annotation.DrawableRes;
import androidx.annotation.NonNull;
import androidx.annotation.StringRes;

import com.americanwell.sdk.entity.visit.Visit;

import com.google.android.material.textfield.TextInputLayout;

import android.text.Html;
import android.text.InputType;
import android.text.Spanned;
import android.text.SpannedString;
import android.text.TextUtils;
import android.util.Patterns;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.TextView;

import com.americanwell.sdk.entity.Address;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.SDKErrorReason;
import com.americanwell.sdk.entity.SDKPasswordError;
import com.americanwell.sdk.entity.SDKResponseSuggestion;
import com.americanwell.sdk.entity.SDKSuggestion;
import com.americanwell.sdk.entity.VisitModality;
import com.americanwell.sdk.entity.VisitModalityType;
import com.americanwell.sdk.entity.pharmacy.Pharmacy;
import com.americanwell.sdk.entity.provider.ProviderVisibility;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.ValidationReason;

import com.rally.virtualvisit.BaseSampleNucleusActivity;
import com.rally.virtualvisit.app.AlertDialogFragment;
import com.rally.virtualvisit.app.AlertDialogResult;
import com.virtualvisit.R;

import java.lang.reflect.Field;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import static com.americanwell.sdk.entity.provider.ProviderVisibility.OFFLINE;
import static com.americanwell.sdk.entity.provider.ProviderVisibility.ON_CALL;
import static com.americanwell.sdk.entity.provider.ProviderVisibility.WEB_AVAILABLE;
import static com.americanwell.sdk.entity.provider.ProviderVisibility.WEB_BUSY;
import static com.rally.virtualvisit.app.AlertDialogResult.Action.NO_ACTION;

/**
 * Some common utilities used in the activities
 */
public class SampleUtils {

    private static final String LOG_TAG = SampleUtils.class.getName();

    private AWSDKLogger logger;


    public SampleUtils(AWSDKLogger logger) {
        this.logger = logger;
    }

    public void handleAuthError(BaseSampleNucleusActivity activity,
                                SDKError sdkError,
                                @AlertDialogResult.Action int resultCode) {
        //The message coming back for this error is not meant for users so we change the message in this instance to
        // something more human friendly. When dealing with the 401 error you should normally monitor for any
        // specific error messages indicating exactly why this is being thrown. If no message is provided it is
        // assumed that the token has simply expired.
        String message = activity.getString(R.string.sdkerrorreason_auth_failure);
        handleError(activity, getErrorTitle(activity, sdkError), message, resultCode);
    }

    // Handles a client side event which has left the app in a fatal/unknown state.
    public void handleFatalEvent(BaseSampleNucleusActivity activity,
                                 @AlertDialogResult.Action int resultCode) {
        String message = activity.getString(R.string.sdkerrorreason_fatal_event);
        handleError(
                activity,
                activity.getResources().getString(R.string.sdkerrorreason_fatal_event_title),
                message,
                resultCode);
    }

    // Simple error handling for an SDKError
    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity, SDKError sdkError) {
        return handleError(activity, sdkError, NO_ACTION);
    }

    // Simple error handling for a throwable
    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity, Throwable error) {
        logger.e(LOG_TAG, "handling error", error);
        return handleError(activity, error.getClass().getSimpleName(), error.getLocalizedMessage());
    }

    // Simple error handling for an SDKError with custom onclicklistener
    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity,
                                           SDKError sdkError,
                                           @AlertDialogResult.Action int resultCode) {
        logger.e(LOG_TAG, "handling error: " + sdkError.toString());
        return handleError(activity, getErrorTitle(activity, sdkError), getErrorBody(activity, sdkError), resultCode);
    }

    // Simple error handling for a throwable with custom onclicklistener
    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity,
                                           Throwable error,
                                           @AlertDialogResult.Action int resultCode) {
        logger.e(LOG_TAG, "handling error", error);
        return handleError(activity, error.getClass().getSimpleName(), error.getLocalizedMessage(), resultCode);
    }

    // Example error handling for password error
    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity, SDKPasswordError sdkError) {
        // Split this error because we do not want to send any message from the server to the logs in case it
        // contains PHI.
        logger.e(LOG_TAG, "handling error: " + sdkError.getSDKErrorReason());
        logger.d(LOG_TAG, "handling error: " + sdkError.toString());

        // build dialog message
        String body = sdkError.toString();
        final SDKResponseSuggestion suggestion = sdkError.getSDKResponseSuggestion();

        if (suggestion != null) {
            final StringBuilder bodyBuilder = new StringBuilder();

            List<String> errs = sdkError.getPasswordErrors();
            if (errs != null) {
                for (String e : errs) {
                    // bullet the list
                    final String error = "&#8226; " + e + "<br>";
                    final Spanned html;
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                        html = Html.fromHtml(error, Html.FROM_HTML_MODE_LEGACY);
                    }
                    else {
                        //noinspection deprecation
                        html = Html.fromHtml(error);
                    }
                    bodyBuilder.append(html);
                }
            }

            bodyBuilder.append("\n");
            bodyBuilder.append(suggestion.getSuggestion());
            body = bodyBuilder.toString();
        }

        return handleError(activity, getErrorTitle(activity, sdkError), body);
    }

    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity, String title, String message) {
        return handleError(activity, title, message, NO_ACTION);
    }

    public AlertDialogFragment handleError(BaseSampleNucleusActivity activity, String title,
                                           String message, @AlertDialogResult.Action int resultCode) {
        AlertDialogFragment dialogFrag = (AlertDialogFragment) new AlertDialogFragment.Builder(
                title,
                message,
                resultCode).create();

        dialogFrag.show(activity.getSupportFragmentManager(), "AlertDialog");

        return dialogFrag;
    }

    public String getErrorTitle(final Context context, final SDKError sdkError) {
        String title = sdkError.getSDKErrorReason() != null ?
                getSDKErrorReasonText(context, sdkError.getSDKErrorReason()) : "Error";
        final SDKResponseSuggestion suggestion = sdkError.getSDKResponseSuggestion();
        if (suggestion != null) {
            title = suggestion.getTitle();
        }
        return title;
    }

    public String getErrorBody(final Context context, final SDKError sdkError) {
        String body = sdkError.toString();
        final SDKResponseSuggestion suggestion = sdkError.getSDKResponseSuggestion();
        // NOTE: this sample code will check for an "SDKSuggestion" in the error response
        // and use that in the alert dialog text, if available.
        // Please note that those suggestions are not always what a production application would want
        // to render.  You may want to provide your own messaging for these errors, and you can do that
        // in any way you like.  We also provide a sample implementation of looking up string resource values
        // based on the ENUM codes, as well.
        if (suggestion != null) {
            body = getSDKSuggestionText(context, suggestion.getSDKSuggestion()) +
                    "\n\n" +
                    suggestion.getSuggestion();
        }
        return body;
    }

    // The code below demonstrates a mechanism for the app to provide more friendly text for the various
    // error enums that may be sent from the server
    // They're called "override strings" and consist of a prefix that corresponds to the ENUM class
    // and a suffix that corresponds to the ENUM value sent.  lowercased.
    // For example: R.string.sdkerrorreason_auth_access_denied is for an SDKErrorReason value of AUTH_ACCESS_DENIED
    // If there is no string resource found, the error code is returned as-is

    private static final String PREFIX_SDK_ERROR_REASON = "sdkerrorreason_";
    private static final String PREFIX_SDK_SUGGESTION = "sdksuggestion_";
    private static final String PREFIX_VALIDATION_REASON = "validationreason_";

    public String getSDKErrorReasonText(@NonNull final Context context,
                                        @NonNull final @SDKErrorReason String sdkErrorReason) {
        return getOverrideString(context, PREFIX_SDK_ERROR_REASON, sdkErrorReason);
    }

    public String getSDKSuggestionText(@NonNull final Context context,
                                       @NonNull final @SDKSuggestion String sdkSuggestion) {
        return getOverrideString(context, PREFIX_SDK_SUGGESTION, sdkSuggestion);
    }

    public String getValidationReasonText(@NonNull final Context context,
                                          @NonNull final @ValidationReason String validationReason) {
        return getOverrideString(context, PREFIX_VALIDATION_REASON, validationReason);
    }

    /**
     * Provided a prefix and a string, will return a String either with a resolved found resource or
     * returns the key if a resource is not found
     */
    public String getOverrideString(final Context context, final String prefix, final String key) {
        try {
            final String resName = prefix + key.toLowerCase();
            Class res = R.string.class;
            Field field = res.getField(resName);
            int resId = field.getInt(null);
            return context.getString(resId);
        }
        catch (Exception e) {
            return key;
        }
    }

    public int getOverrideInt(final Context context, final String prefix, final String key) {
        final int resId = context.getResources().getIdentifier(
                prefix + key.toLowerCase(), "integer", context.getPackageName());
        return context.getResources().getInteger(resId);
    }


    private DialogInterface.OnClickListener defaultErrorOnClickListener() {
        return new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        };
    }

    /**
     * This method demonstrates one simplistic way of handling validation failures.
     * The {@link com.americanwell.sdk.manager.SDKValidatedCallback#onValidationFailure(Map)} has a
     * map of sdk field names and {@link ValidationReason}s.  The Javadoc for each SDK validation
     * call lists the possible field names and error codes.  This doc can be used to write robust
     * validation code. In this example, another Map called "views" contains a mapping of the
     * fieldName to a UI view. The String key can then be used to find both the error code and
     * the associated view.  A third static Map contains a set of standard string resource id's
     * for validation errors.  This can, of course, be made more specific if so desired.  For
     * this sample, it's kept simple.
     *
     * @param activity
     * @param views
     * @param errors
     */
    public void handleValidationFailures(final BaseSampleNucleusActivity activity,
                                         final Map<String, View> views,
                                         final Map<String, String> errors) {
        handleValidationFailures(activity, views, errors, NO_ACTION);
    }

    /**
     * This method demonstrates one simplistic way of handling validation failures.
     * The {@link com.americanwell.sdk.manager.SDKValidatedCallback#onValidationFailure(Map)} has a
     * map of sdk field names and {@link ValidationReason}s.  The Javadoc for each SDK validation
     * call lists the possible field names and error codes.  This doc can be used to write robust
     * validation code. In this example, another Map called "views" contains a mapping of the
     * fieldName to a UI view. The String key can then be used to find both the error code and
     * the associated view.  A third static Map contains a set of standard string resource id's
     * for validation errors.  This can, of course, be made more specific if so desired.  For
     * this sample, it's kept simple.
     *
     * @param activity
     * @param views
     * @param errors
     * @param resultCode
     */
    public void handleValidationFailures(final BaseSampleNucleusActivity activity,
                                         final Map<String, View> views,
                                         final Map<String, String> errors,
                                         final @AlertDialogResult.Action int resultCode) {
        final StringBuilder unmappedMessages = new StringBuilder();
        if (errors != null) {
            for (final String field : errors.keySet()) {// loop thru the errors
                final @ValidationReason
                String validationReason = errors.get(field); // get the error code
                final String errorString = getValidationReasonText(activity, validationReason);
                View view = null;
                if (views != null) {
                    view = views.get(field); // do we have a corresponding field?
                }
                if (view != null) {
                    if (view.getVisibility() == View.VISIBLE) { //if the view is not visible we should not display any errors
                        if (view instanceof TextView) { // is it a textview?  set the error
                            ((TextView) view).setError(errorString);
                        }
                        else if (view instanceof TextInputLayout) {
                            ((TextInputLayout) view).setError(errorString);
                        }
                        else {
                            unmappedMessages.append(activity.getString(R.string.validation_generic_message, field, errorString));
                        }
                        view.requestFocus();
                    }
                    // This sample only demonstrates handling TextViews, but if you have other types of
                    // views with other types of possible error handling, you can implement that here.
                }
                else {
                    unmappedMessages.append(activity.getString(R.string.validation_generic_message, field, errorString));
                }
            }
            // this code will clear out any errors on views given that do not have a
            // corresponding error.  If you are bundling this validation with your own validation
            // this code could potentially clear out an error it didn't create
            // if you are in this situation you should either run this validation first
            // or refactor the validation mechanism to your liking
            if (views != null) {
                for (final String field : views.keySet()) {
                    if (!errors.containsKey(field)) {
                        final View view = views.get(field);
                        if (view instanceof TextView) {
                            ((TextView) view).setError(null);
                        }
                        else if (view instanceof TextInputLayout) {
                            ((TextInputLayout) view).setError(null);
                        }
                    }
                }
            }

            if (unmappedMessages.length() > 0) {
                handleError(activity, activity.getString(R.string.validation_generic_title), unmappedMessages.toString(), resultCode);
            }
        }
    }

    public String getProviderAvailabilityString(final Resources res,
                                                final @ProviderVisibility String availability,
                                                final Integer waitingRoomCount) {
        String availabilityString;

        switch (availability) {
            case WEB_AVAILABLE:
                availabilityString = res.getString(R.string.provider_details_available_now);
                break;
            case WEB_BUSY:
                availabilityString = getWaitingRoomString(res, waitingRoomCount);
                break;
            case ON_CALL:
                availabilityString = getWaitingRoomString(res, waitingRoomCount);
                break;
            case OFFLINE:
            default:
                availabilityString = res.getString(R.string.provider_details_offline);
                break;
        }

        return availabilityString;
    }

    private String getWaitingRoomString(final Resources res, final Integer count) {
        int finalCount;

        //      Because we don't want to display any string when the count is less than 1 we
        //      first check for these values
        if (count != null && count >= 1) {
            finalCount = count;
        }
        else {
            finalCount = 1;
        }

        //      Using the quantity string gives us more power as to how to handle the localization in
        //      the future
        return res.getQuantityString(0, finalCount, finalCount);
    }

    // utility method for Pharmacy activities
    public String buildPharmacyDisplayText(final Context context,
                                           final Pharmacy pharmacy,
                                           final boolean includeContact,
                                           final boolean isMultiCountry,
                                           final Locale locale) {
        final StringBuilder pharmacyTextBuilder = new StringBuilder();
        pharmacyTextBuilder.append(pharmacy.getName());
        if (pharmacy.getType() != null) {
            pharmacyTextBuilder.append(" (");
            pharmacyTextBuilder.append(pharmacy.getType());
            pharmacyTextBuilder.append(")");
        }

        final Address address = pharmacy.getAddress();

        if (address != null) {
            pharmacyTextBuilder.append("\n");
            pharmacyTextBuilder.append(address.getAddress1());

            String address2 = address.getAddress2();

            if (address2 != null) {
                pharmacyTextBuilder.append("\n");
                pharmacyTextBuilder.append(address.getAddress2());
            }

            pharmacyTextBuilder.append("\n");
            pharmacyTextBuilder.append(String.format("%s, %s %s",
                    address.getCity(), address.getState().getCode(), address.getZipCode()));

            if (isMultiCountry) {
                pharmacyTextBuilder.append("\n");
                pharmacyTextBuilder.append(address.getCountry().getName());
            }
        }

        if (pharmacy.getDistance() > 0) {
            String formattedDistance = formatDistance(pharmacy.getDistance());

            pharmacyTextBuilder.append("\n");
            pharmacyTextBuilder.append(context.getString(R.string.pharmacy_distance));
            pharmacyTextBuilder.append(formattedDistance);
            pharmacyTextBuilder.append("\n");
        }

        if (includeContact) {

            final LocaleUtils localeUtils = new LocaleUtils(locale, context.getResources());

            final String phone = pharmacy.getPhone();
            if (phone != null) {
                pharmacyTextBuilder.append("\n");
                pharmacyTextBuilder.append(localeUtils.getFormattedPhoneNumber(phone));
            }

            final String fax = pharmacy.getFax();
            if (fax != null) {
                pharmacyTextBuilder.append("\n");
                pharmacyTextBuilder.append(localeUtils.getFormattedPhoneNumber(fax));
            }

            final String email = pharmacy.getEmail();
            if (email != null) {
                pharmacyTextBuilder.append("\n");
                pharmacyTextBuilder.append(email);
            }
        }

        return pharmacyTextBuilder.toString();
    }

    public String stripNonDigitCharacters(final String input) {

        String result = "";
        List<Character> digitChars = getFormattingDigitsAsList();
        if (input != null) {
            for (int i = 0; i < input.length(); i++) {
                Character ch = input.charAt(i);
                if (digitChars.contains(ch)) {
                    result += ch.toString();
                }
            }
        }
        return result;
    }

    public List<Character> getFormattingDigitsAsList() {

        final String digitCharacters = "0123456789";
        List<Character> digitChars = new ArrayList<>();
        char charArray[] = digitCharacters.toCharArray();
        for (char ch : charArray) {
            digitChars.add(ch);
        }
        return digitChars;
    }


    public static String formatDistance(double distance) {
        DecimalFormat df2 = new DecimalFormat("#,###.00 mi");
        return df2.format(distance);
    }

    public static boolean isValidEmail(CharSequence target) {
        return target != null && android.util.Patterns.EMAIL_ADDRESS.matcher(target).matches();
    }

    public static boolean isValidPhoneNumber(CharSequence target) {
        if (!TextUtils.isEmpty(target) && target.length() >= 10) {
            return android.util.Patterns.PHONE.matcher(target).matches();
        }
        return false;
    }

    /**
     * Hide keyboard
     *
     * @param activity activity
     */
    public static void hideKeyboard(final Activity activity) {
        hideKeyboard(activity, null);
    }

    /**
     * Hide keyboard
     *
     * @param activity activity
     * @param view     the view
     */
    public static void hideKeyboard(final Activity activity, final View view) {
        if (activity != null) {
            final InputMethodManager imm = (InputMethodManager)
                    activity.getSystemService(Context.INPUT_METHOD_SERVICE);
            final View focusedView = view != null ? view : activity.getCurrentFocus();
            if (focusedView != null) {
                imm.hideSoftInputFromWindow(focusedView.getWindowToken(), 0);
            }
        }
    }

    public static boolean isDirty(String currentValue, String updateValue) {
        return !bothEmpty(currentValue, updateValue) &&
                !updateValue.equals(currentValue);
    }

    public static boolean bothEmpty(String currentValue, String updateValue) {
        return TextUtils.isEmpty(currentValue) && TextUtils.isEmpty(updateValue);
    }

    // checks if the text is a url.
    public static boolean isUrl(String text) {
        return Patterns.WEB_URL.matcher(text.trim()).matches();
    }

    /**
     * An extension to the functionality provided by {@link Context#getText(int)} by using Html escape sequences
     * to have parameterized and styled text formatting functionality. It combines the functionalities of
     * {@link Context#getText(int)} and {@link String#format(String, Object...)}.
     *
     * @param context     Context to use to extract the {@code stringResId}.
     * @param stringResId Resource identifier for the parameterized string resource.
     * @param args        Arguments referenced by the parameter specifiers in the {@code stringResId} string.
     */
    public static CharSequence getText(@NonNull Context context, @StringRes int stringResId, @NonNull Object... args) {
        CharSequence resString = context.getText(stringResId);
        for (int i = 0; i < args.length; ++i)
            args[i] = args[i] instanceof String ? TextUtils.htmlEncode((String) args[i]) : args[i];
        String htmlEscapedString = Html.toHtml(new SpannedString(resString));
        String formattedString = String.format(htmlEscapedString, args);
        return Html.fromHtml(formattedString).toString().trim();
    }

    /**
     * Disable soft keyboard from appearing.
     *
     * @param editText
     */
    public static void disableSoftInputFromAppearing(EditText editText) {
        editText.setRawInputType(InputType.TYPE_CLASS_TEXT);
        editText.setTextIsSelectable(true);
    }


    /**
     * Return a {@link DrawableRes} for the give VisitModality
     *
     * @param visitModality - modality of the visit
     * @return The resource id of the {@link Drawable}
     */

//    public static @DrawableRes
//    int getModalityDrawable(VisitModality visitModality) {
//        @DrawableRes
//        int drawableRes = 0;
//        if (visitModality != null) {
//            switch (visitModality.getModalityType()) {
//                case VisitModalityType.PHONE:
//                    drawableRes = R.drawable.icon_phone_visit_appt_list;
//                    break;
//                case VisitModalityType.VIDEO:
//                    drawableRes = R.drawable.icon_video_visit_appt_list;
//                    break;
//                default:
//                    break;
//            }
//        }
//        return drawableRes;
//    }

}
