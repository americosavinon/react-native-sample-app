/**
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.util;

import android.content.Context;
import androidx.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.List;
import java.util.Locale;

/**
 * Adapter used for spinner of Locales.
 * Provides a nicer Locale display.
 */

public class LocaleArrayAdapter extends ArrayAdapter<Locale> {

    private int layoutRes;

    public LocaleArrayAdapter(@NonNull Context context, int layoutRes, List<Locale> locales) {
        super(context, layoutRes, locales);

        this.layoutRes = layoutRes;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(layoutRes, null);
        }
        Locale locale = getItem(position);
        ((TextView) convertView).setText(
                locale.getDisplayLanguage() + " (" + locale.getDisplayCountry() + ")");

        return convertView;
    }

    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent) {
        return getView(position, convertView, parent);
    }
}
