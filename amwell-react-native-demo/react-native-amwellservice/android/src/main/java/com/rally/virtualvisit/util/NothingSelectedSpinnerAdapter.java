/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.util;


import android.content.Context;
import android.database.DataSetObserver;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.SpinnerAdapter;

/**
 * http://stackoverflow.com/questions/867518/how-to-make-an-android-spinner-with-initial-text-select-one
 */

/**
 * Decorator Adapter to allow a Spinner to show a 'Nothing Selected...' initially
 * displayed instead of the first choice in the Adapter.
 */
public class NothingSelectedSpinnerAdapter implements SpinnerAdapter, ListAdapter {

    protected static final int EXTRA = 1;
    protected ArrayAdapter adapter;
    protected Context context;
    protected int nothingSelectedLayout;
    protected int nothingSelectedDropdownLayout;
    protected LayoutInflater layoutInflater;
    protected boolean allowNone = false;
    protected boolean displayNothingSelectedOnEmpty = false;

    /**
     * Use this constructor to have NO 'Select One...' item, instead use
     * the standard prompt or nothing at all.
     *
     * @param spinnerAdapter        An ArrayAdapter.
     * @param nothingSelectedLayout layout for nothing selected, perhaps
     *                              you want text grayed out like a prompt...
     * @param context
     */
    public NothingSelectedSpinnerAdapter(ArrayAdapter spinnerAdapter,
                                         int nothingSelectedLayout,
                                         Context context) {

        this(spinnerAdapter, nothingSelectedLayout, -1, context, false);
    }


    /**
     * Use this constructor to have NO 'Select One...' item, instead use
     * the standard prompt or nothing at all.
     *
     * @param spinnerAdapter                An ArrayAdapter.
     * @param nothingSelectedLayout         layout for nothing selected, perhaps
     *                                      you want text grayed out like a prompt...
     * @param context
     * @param displayNothingSelectedOnEmpty when set true, this mode will display "nothing selected"
     *                                      message when this adapter is empty
     */
    public NothingSelectedSpinnerAdapter(ArrayAdapter spinnerAdapter,
                                         int nothingSelectedLayout,
                                         Context context,
                                         boolean displayNothingSelectedOnEmpty) {

        this(spinnerAdapter, nothingSelectedLayout, -1, context, displayNothingSelectedOnEmpty);
    }


    /**
     * Use this constructor to Define your 'Select One...' layout as the first
     * row in the returned choices.
     * If you do this, you probably don't want a prompt on your spinner or it'll
     * have two 'Select' rows.
     *
     * @param spinnerAdapter                An ArrayAdapter. Should probably return false for
     *                                      isEnabled(0)
     * @param nothingSelectedLayout         layout for nothing selected, perhaps you want
     *                                      text grayed out like a prompt...
     * @param nothingSelectedDropdownLayout layout for your 'Select an Item...' in
     *                                      the dropdown.
     * @param context
     */
    public NothingSelectedSpinnerAdapter(ArrayAdapter spinnerAdapter,
                                         int nothingSelectedLayout,
                                         int nothingSelectedDropdownLayout,
                                         Context context) {
        this(spinnerAdapter, nothingSelectedLayout, nothingSelectedDropdownLayout, context, false);
    }

    /**
     * Use this constructor to Define your 'Select One...' layout as the first
     * row in the returned choices.
     * If you do this, you probably don't want a prompt on your spinner or it'll
     * have two 'Select' rows.
     *
     * @param spinnerAdapter                An ArrayAdapter. Should probably return false for
     *                                      isEnabled(0)
     * @param nothingSelectedLayout         layout for nothing selected, perhaps you want
     *                                      text grayed out like a prompt...
     * @param nothingSelectedDropdownLayout layout for your 'Select an Item...' in
     *                                      the dropdown.
     * @param context
     * @param displayNothingSelectedOnEmpty when set true, this mode will display "nothing selected"
     *                                      message when this adapter is empty
     */

    public NothingSelectedSpinnerAdapter(ArrayAdapter spinnerAdapter,
                                         int nothingSelectedLayout,
                                         int nothingSelectedDropdownLayout,
                                         Context context,
                                         boolean displayNothingSelectedOnEmpty) {
        this.adapter = spinnerAdapter;
        this.context = context;
        this.nothingSelectedLayout = nothingSelectedLayout;
        this.nothingSelectedDropdownLayout = nothingSelectedDropdownLayout;
        this.displayNothingSelectedOnEmpty = displayNothingSelectedOnEmpty;

        layoutInflater = LayoutInflater.from(context);
    }

    @Override
    public final View getView(int position, View convertView, ViewGroup parent) {
        // This provides the View for the Selected Item in the Spinner, not
        // the dropdown (unless dropdownView is not set).
        if (position == 0 || (displayNothingSelectedOnEmpty && isEmpty())) {
            return getNothingSelectedView(parent);
        }
        return adapter.getView(position - EXTRA, null, parent); // Could re-use
        // the convertView if possible.
    }

    /**
     * View to show in Spinner with Nothing Selected
     * Override this to do something dynamic... e.g. "37 Options Found"
     *
     * @param parent
     * @return
     */
    protected View getNothingSelectedView(ViewGroup parent) {
        return layoutInflater.inflate(nothingSelectedLayout, parent, false);
    }

    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent) {
        // Android BUG! http://code.google.com/p/android/issues/detail?id=17128 -
        // Spinner does not support multiple view types
        if (position == 0 || (displayNothingSelectedOnEmpty && isEmpty())) {
            return nothingSelectedDropdownLayout == -1 ?
                    new View(context) :
                    getNothingSelectedDropdownView(parent);
        }

        // Could re-use the convertView if possible, use setTag...
        return adapter.getDropDownView(position - EXTRA, null, parent);
    }

    /**
     * Override this to do something dynamic... For example, "Pick your favorite
     * of these 37".
     *
     * @param parent
     * @return
     */
    protected View getNothingSelectedDropdownView(ViewGroup parent) {
        return layoutInflater.inflate(nothingSelectedDropdownLayout, parent, false);
    }

    @Override
    public int getCount() {
        int count = adapter.getCount();
        return count == 0 ? (displayNothingSelectedOnEmpty ? 1 : 0) : count + EXTRA;
    }

    @Override
    public Object getItem(int position) {
        return position == 0 ? null : adapter.getItem(position - EXTRA);
    }

    @Override
    public int getItemViewType(int position) {
        return 0;
    }

    @Override
    public int getViewTypeCount() {
        return 1;
    }

    @Override
    public long getItemId(int position) {
        return position >= EXTRA ? adapter.getItemId(position - EXTRA) : position - EXTRA;
    }

    @Override
    public boolean hasStableIds() {
        return adapter.hasStableIds();
    }

    @Override
    public boolean isEmpty() {
        return adapter.isEmpty();
    }

    @Override
    public void registerDataSetObserver(DataSetObserver observer) {
        adapter.registerDataSetObserver(observer);
    }

    @Override
    public void unregisterDataSetObserver(DataSetObserver observer) {
        adapter.unregisterDataSetObserver(observer);
    }

    @Override
    public boolean areAllItemsEnabled() {
        return false;
    }

    @Override
    public boolean isEnabled(int position) {
        return allowNone || position != 0; // Don't allow the 'nothing selected'
        // item to be picked.
    }

    public int getPosition(Object item) {
        return adapter.getPosition(item) + 1;
    }

    public void setAllowNone(final boolean allowNone) {
        this.allowNone = allowNone;
    }
}
