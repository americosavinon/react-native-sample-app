/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.app;

import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import androidx.annotation.NonNull;
import androidx.fragment.app.DialogFragment;
import androidx.appcompat.app.AlertDialog;
import android.text.TextUtils;

import com.rally.virtualvisit.BaseSampleNucleusActivity;
import com.rally.virtualvisit.R;

import static com.rally.virtualvisit.app.DialogData.CANCEL_ON_TOUCH_OUTSIDE;
import static com.rally.virtualvisit.app.DialogData.MESSAGE;
import static com.rally.virtualvisit.app.DialogData.NEGATIVE_TEXT;
import static com.rally.virtualvisit.app.DialogData.NEUTRAL_TEXT;
import static com.rally.virtualvisit.app.DialogData.POSITIVE_TEXT;
import static com.rally.virtualvisit.app.DialogData.RESULT_CODE;
import static com.rally.virtualvisit.app.DialogData.TITLE;

/**
 * Custom {@link DialogFragment} used to display error messages throughout the sample app.
 */

public class AlertDialogFragment extends DialogFragment {

    @NonNull
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        Bundle args = getArguments();
        final String title = args.getString(TITLE, null);
        final String message = args.getString(MESSAGE, null);
        final int resultCode = args.getInt(RESULT_CODE);

        final String posText = args.getString(POSITIVE_TEXT, null);
        final String neutralText = args.getString(NEUTRAL_TEXT, null);
        final String negText = args.getString(NEGATIVE_TEXT, null);

        final boolean canceledOnTouchOutside = args
                .getBoolean(CANCEL_ON_TOUCH_OUTSIDE, false);

        final DialogInterface.OnClickListener buttonListener = new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int whichButton) {
                ((BaseSampleNucleusActivity) getActivity()).onDialogResult(
                        resultCode, whichButton);
            }
        };

        AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(getActivity())
                .setTitle(title)
                .setMessage(message)
                .setCancelable(false);

        if (!TextUtils.isEmpty(posText)) {
            dialogBuilder.setPositiveButton(posText, buttonListener);
        }

        if (!TextUtils.isEmpty(negText)) {
            dialogBuilder.setNegativeButton(negText, buttonListener);
        }

        // assign a default 'OK' neutral button in the absence of all other buttons
        String tNeutralText = TextUtils.isEmpty(neutralText) &&
                TextUtils.isEmpty(posText) &&
                TextUtils.isEmpty(negText) ? getString(R.string.app_ok) : neutralText;

        if (!TextUtils.isEmpty(tNeutralText)) {
            dialogBuilder.setNeutralButton(tNeutralText, buttonListener);
        }

        Dialog dialog = dialogBuilder.create();
        dialog.setCanceledOnTouchOutside(canceledOnTouchOutside);

        return dialog;
    }

    /**
     * Builder class for creating a {@link AlertDialogFragment} instance.
     */
    public static class Builder extends DialogFragmentBuilder {

        public Builder(@AlertDialogResult.Action int resultCode) {
            super(resultCode);
        }

        public Builder(@NonNull String title, @AlertDialogResult.Action int resultCode) {
            super(title, resultCode);
        }

        public Builder(@NonNull String title,
                       @NonNull String message,
                       @AlertDialogResult.Action int resultCode) {
            super(title, message, resultCode);
        }

        @Override
        protected DialogFragment getBaseFragment() {
            return new AlertDialogFragment();
        }
    }
}
