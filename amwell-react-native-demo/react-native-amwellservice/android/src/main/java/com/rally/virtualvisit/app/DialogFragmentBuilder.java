
/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.app;

import android.os.Bundle;
import androidx.annotation.NonNull;
import androidx.fragment.app.DialogFragment;

import static com.rally.virtualvisit.app.DialogData.CANCEL_ON_TOUCH_OUTSIDE;
import static com.rally.virtualvisit.app.DialogData.MESSAGE;
import static com.rally.virtualvisit.app.DialogData.NEGATIVE_TEXT;
import static com.rally.virtualvisit.app.DialogData.NEUTRAL_TEXT;
import static com.rally.virtualvisit.app.DialogData.POSITIVE_TEXT;
import static com.rally.virtualvisit.app.DialogData.RESULT_CODE;
import static com.rally.virtualvisit.app.DialogData.TITLE;

/**
 * Abstract builder class for creating a {@link DialogFragment} instance.
 */

public abstract class DialogFragmentBuilder {

    private Bundle args = new Bundle();

    public DialogFragmentBuilder(int resultCode) {
        args.putInt(RESULT_CODE, resultCode);
    }

    public DialogFragmentBuilder(@NonNull String title, int resultCode) {
        this(title, null, resultCode);
    }

    public DialogFragmentBuilder(@NonNull String title, @NonNull String message, int resultCode) {
        args.putInt(RESULT_CODE, resultCode);
        setTitle(title);
        setMessage(message);
    }

    public DialogFragmentBuilder setTitle(@NonNull String title) {
        args.putString(TITLE, title);
        return this;
    }

    public DialogFragmentBuilder setMessage(@NonNull String message) {
        args.putString(MESSAGE, message);
        return this;
    }

    public DialogFragmentBuilder setPositiveText(@NonNull String posText) {
        args.putString(POSITIVE_TEXT, posText);
        return this;
    }

    public DialogFragmentBuilder setNeutralText(@NonNull String neutralText) {
        args.putString(NEUTRAL_TEXT, neutralText);
        return this;
    }

    public DialogFragmentBuilder setNegativeText(@NonNull String negativeText) {
        args.putString(NEGATIVE_TEXT, negativeText);
        return this;
    }

    public DialogFragmentBuilder setCanceledOnTouchOutside(boolean canceledOnTouchOutside) {
        args.putBoolean(CANCEL_ON_TOUCH_OUTSIDE, canceledOnTouchOutside);
        return this;
    }

    protected abstract DialogFragment getBaseFragment();

    public DialogFragment create() {
        DialogFragment frag = getBaseFragment();
        frag.setArguments(args);
        return frag;
    }
}
