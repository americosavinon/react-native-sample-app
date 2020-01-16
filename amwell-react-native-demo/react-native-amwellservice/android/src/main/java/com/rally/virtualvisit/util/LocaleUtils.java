/*
 * Copyright 2017 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.util;

import android.app.Activity;
import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.TimePickerDialog;
import android.app.TimePickerDialog.OnTimeSetListener;
import android.content.Context;
import android.content.res.Resources;
import android.telephony.PhoneNumberUtils;
import android.text.TextUtils;
import android.view.View;
import android.widget.DatePicker;
import android.widget.EditText;


import java.text.DateFormat;
import java.text.MessageFormat;
import java.text.NumberFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Currency;
import java.util.Date;
import java.util.List;
import java.util.Locale;

import androidx.annotation.NonNull;


import com.rally.virtualvisit.R;

import static android.content.DialogInterface.BUTTON_NEGATIVE;
import static android.content.DialogInterface.BUTTON_POSITIVE;

/**
 * Common utilities for formatting dates, times, and currency.
 */

public class LocaleUtils {

    private Locale locale;
    private SimpleDateFormat dateFormat;
    private SimpleDateFormat appointmentDateFormat;
    private SimpleDateFormat appointmentSlotFormat;
    private SimpleDateFormat appointmentTimeFormat;
    private SimpleDateFormat visitSummaryDateFormat;
    private SimpleDateFormat visitSummaryTimeFormat;
    private SimpleDateFormat techChechDateFormat;
    private SimpleDateFormat trackerDateFormat;
    private SimpleDateFormat measurementDateFormat;
    private SimpleDateFormat addMeasurementDateFormat;
    private SimpleDateFormat addMeasurementTimeFormat;
    private NumberFormat currencyFormat;

    public LocaleUtils(@NonNull Locale locale, @NonNull Resources res) {
        this.locale = locale;
        dateFormat = new SimpleDateFormat(res.getString(R.string.dateFormat), locale);
        appointmentDateFormat = new SimpleDateFormat(res.getString(R.string.appointmentDateFormat), locale);
        appointmentSlotFormat = new SimpleDateFormat(res.getString(R.string.appointmentSlotFormat), locale);
        appointmentTimeFormat = new SimpleDateFormat(res.getString(R.string.appointmentTimeFormat), locale);
        visitSummaryDateFormat = new SimpleDateFormat(res.getString(R.string.visitSummaryDateFormat), locale);
        visitSummaryTimeFormat = new SimpleDateFormat(res.getString(R.string.visitSummaryTimeFormat), locale);
        techChechDateFormat = new SimpleDateFormat(res.getString(R.string.techCheckDateFormat), locale);
        trackerDateFormat = new SimpleDateFormat(res.getString(R.string.trackerDateFormat), locale);
        measurementDateFormat = new SimpleDateFormat(res.getString(R.string.measurementDateFormat), locale);
        addMeasurementDateFormat = new SimpleDateFormat(res.getString(R.string.addMeasurementDateFormat), locale);
        addMeasurementTimeFormat = new SimpleDateFormat(res.getString(R.string.addMeasurementTimeFormat), locale);
        currencyFormat = NumberFormat.getCurrencyInstance(locale);
    }

    // show a date picker
    public Dialog showDatePicker(final EditText editText,
                                 final Activity context,
                                 boolean allowFuture) {
        final Calendar calendar = Calendar.getInstance();
        String dateText = editText.getText().toString();

        if (dateText.length() > 0) {
            Date date;
            try {
                date = dateFormat.parse(dateText);
            }
            catch (ParseException exception) {
                throw new RuntimeException(exception);
            }

            calendar.setTime(date);
        }

        DatePickerDialog.OnDateSetListener dateSetListener = new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
                calendar.set(Calendar.YEAR, year);
                calendar.set(Calendar.MONTH, monthOfYear);
                calendar.set(Calendar.DAY_OF_MONTH, dayOfMonth);
                editText.setText(dateFormat.format(calendar.getTime()));
            }
        };

        // hide keyboard before displaying date picker
        SampleUtils.hideKeyboard(context);

        DatePickerDialog datePickerDalog = getDatePickerDialog(
                calendar,
                context,
                allowFuture,
                dateSetListener);

        datePickerDalog.show();
        return datePickerDalog;
    }

    /**
     * Instantiate a {@link DatePickerDialog} and initialize with {@code calendar}
     *
     * @param calendar        use this to preset the DatePicker
     * @param context         the context
     * @param allowFuture     if future dates should be allowed
     * @param dateSetListener listener when the date is chosen
     * @return a {@link DatePickerDialog} instance
     */

    public DatePickerDialog getDatePickerDialog(final Calendar calendar,
                                                final Context context,
                                                boolean allowFuture,
                                                DatePickerDialog.OnDateSetListener dateSetListener) {
        DatePickerDialog datePickerDialog = new DatePickerDialog(
                context,
                R.style.DatePickerDialog,
                dateSetListener,
                calendar.get(Calendar.YEAR),
                calendar.get(Calendar.MONTH),
                calendar.get(Calendar.DAY_OF_MONTH));

        datePickerDialog.setButton(BUTTON_POSITIVE, context.getString(R.string.app_ok), datePickerDialog);
        datePickerDialog.setButton(BUTTON_NEGATIVE, context.getString(R.string.app_cancel), datePickerDialog);

        if (!allowFuture) {
            datePickerDialog.getDatePicker().setMaxDate(System.currentTimeMillis());
        }

        return datePickerDialog;
    }

    /**
     * Instantiate a {@link com.wdullaer.materialdatetimepicker.date.DatePickerDialog} and
     * initialize with {@code calendar}
     *
     * @param calendar        use this to preset the DatePicker
     * @param selectableDates selectable dates
     * @param allowFuture     if future dates should be allowed
     * @param listener        listener when the date is chosen
     * @return a {@link com.wdullaer.materialdatetimepicker.date.DatePickerDialog} instance
     */
    public com.wdullaer.materialdatetimepicker.date.DatePickerDialog getDatePickerDialog(
            final Calendar calendar,
            final List<Calendar> selectableDates,
            boolean allowFuture,
            com.wdullaer.materialdatetimepicker.date.DatePickerDialog.OnDateSetListener listener) {

        com.wdullaer.materialdatetimepicker.date.DatePickerDialog datePicker =
                com.wdullaer.materialdatetimepicker.date.DatePickerDialog.newInstance(
                        listener,
                        calendar.get(Calendar.YEAR),
                        calendar.get(Calendar.MONTH),
                        calendar.get(Calendar.DAY_OF_MONTH)
                );

        datePicker.setStyle(R.style.DatePickerDialog, 0);
        datePicker.setOkText(R.string.app_ok);
        datePicker.setCancelText(R.string.app_cancel);

        if (!allowFuture) {
            datePicker.setMaxDate(Calendar.getInstance());
        }

        if (selectableDates != null && !selectableDates.isEmpty()) {
            datePicker.setSelectableDays(selectableDates.toArray(new Calendar[0]));
        }

        return datePicker;
    }

    public TimePickerDialog getTimePickerDialog(final Context context,
                                                final Calendar calendar,
                                                final OnTimeSetListener listener) {
        return new TimePickerDialog(
                context,
                R.style.TimePickerDialog,
                listener,
                calendar.get(Calendar.HOUR_OF_DAY),
                calendar.get(Calendar.MINUTE),
                android.text.format.DateFormat.is24HourFormat(context));
    }

    public String formatAppointmentDate(final Date date) {
        return formatDate(date, appointmentDateFormat);
    }

    public String formatAppointmentSlot(final Date date) {
        return formatDate(date, appointmentSlotFormat);
    }

    public String formatAppointmentTime(final Date date) {
        return formatDate(date, appointmentTimeFormat);
    }

    public String formatVisitSummaryDate(final Date date) {
        return formatDate(date, visitSummaryDateFormat);
    }

    public String formatVisitSummaryTime(final Date date) {
        return formatDate(date, visitSummaryTimeFormat);
    }

    public String formatTechCheckDate(final Date date) {
        return formatDate(date, techChechDateFormat);
    }

    public String formatTrackerDate(final Date date) {
        return formatDate(date, trackerDateFormat);
    }

    public String formatMeasurementDate(final Date date) {
        return formatDate(date, measurementDateFormat);
    }

    public String formatAddMeasurementDate(final Date date) {
        return formatDate(date, addMeasurementDateFormat);
    }

    public String formatAddMeasurementTime(final Date date) {
        return formatDate(date, addMeasurementTimeFormat);
    }

    public String formatDate(Date date, SimpleDateFormat sdf) {
        return (date == null) ? null : sdf.format(date);
    }

    // format a Locale based date/time given a Date
    // for no args passed, we assume date and time detail
    public String formatTimeStamp(Date date) {
        return formatTimeStamp(date.getTime(), DateFormat.LONG, DateFormat.LONG);
    }

    // format a Locale based date/time given a time in millis
    public String formatTimeStamp(long timeStamp) {
        return formatTimeStamp(timeStamp, DateFormat.LONG, DateFormat.LONG);
    }

    // format a date given a time in millis, Locale, and date style
    public String formatTimeStamp(long timeStamp, final int dateStyle) {
        return formatTimeStamp(timeStamp, dateStyle, DateFormat.LONG);
    }

    // format a date/time given a time in millis, Locale, date style, and time style
    public String formatTimeStamp(final long timeStamp,
                                  final int dateStyle,
                                  final int timeStyle) {
        DateFormat df = DateFormat.getDateTimeInstance(dateStyle, timeStyle, locale);
        return df.format(new Date(timeStamp));
    }

    // Handy date-formatting utils
    public String smartFormatTimeStamp(final Context ctx,
                                       final long timeStamp) {
        // create a bunch of calendars to help us categorize the time below
        final Calendar cal = Calendar.getInstance();
        final Calendar midnight7DaysAgo = getMidnight7DaysAgo(cal);
        final Calendar midnightYesterday = getMidnightYesterday(cal);
        final Calendar midnightToday = getMidnightToday(cal);
        final Calendar midnightTomorrow = getMidnightTomorrow(cal);

        int resId = -1;

        if (timeStamp < midnight7DaysAgo.getTimeInMillis()) {
            // earlier than 7 days ago
            resId = R.string.format_pastDate_other;
        }
        else if (timeStamp < midnightYesterday.getTimeInMillis()) {
            // sometime in past 7 days
            resId = R.string.format_pastDate_thisWeek;
        }
        else if (timeStamp < midnightToday.getTimeInMillis()) {
            // sometime yesterday
            resId = R.string.format_pastDate_yesterday;
        }
        else if (timeStamp < midnightTomorrow.getTimeInMillis()) {
            // sometime today
            resId = R.string.format_pastDate_today;
        }
        else {
            // tomorrow or later
            return formatTimeStamp(timeStamp, DateFormat.SHORT, DateFormat.SHORT);
        }

        return MessageFormat.format(ctx.getString(resId), timeStamp);

    }

    /**
     * Returns a calendar 1 day after given calendar and with time set to 00:00:00. For example if
     * it is 13:45 on 05/27/12, it will return calendar set to 00:00:00 on 05/28/12.
     *
     * @param calendar calendar
     * @return Calendar set to tomorrow at midnight
     */
    public Calendar getMidnightTomorrow(final Calendar calendar) {

        final Calendar cal = (Calendar) calendar.clone();

        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);

        cal.add(Calendar.DAY_OF_MONTH, 1);

        return cal;
    }

    /**
     * Returns the current year
     *
     * @return Calendar set to tomorrow at midnight
     */
    public Integer getCurrentYear() {
        final Calendar cal = Calendar.getInstance();
        return cal.get(Calendar.YEAR);
    }

    /**
     * Returns a calendar 1 day before given calendar and with time set to 00:00:00. For example if
     * it is 13:45 on 05/29/12, it will return calendar set to 00:00:00 on 05/28/12.
     *
     * @param calendar calendar
     * @return Calendar set to yesterday at midnight
     */
    public Calendar getMidnightYesterday(final Calendar calendar) {

        final Calendar cal = (Calendar) calendar.clone();

        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);

        cal.add(Calendar.DAY_OF_MONTH, -1);

        return cal;
    }

    /**
     * Returns a calendar 7 days before given calendar and with time set to 00:00:00. For example if
     * it is currently 6:15 on 05/29/12, it will return calendar set to 00:00:00 on 05/22/12.
     *
     * @param calendar calendar
     * @return Calendar set to 7 days ago at midnight
     */
    public Calendar getMidnight7DaysAgo(final Calendar calendar) {

        final Calendar cal = (Calendar) calendar.clone();

        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);

        cal.add(Calendar.DAY_OF_MONTH, -7);

        return cal;
    }

    /**
     * Returns a calendar with same date as given calendar but with time set to 00:00:00.
     *
     * @param calendar calendar
     * @return Calendar at midnight
     */
    public Calendar getMidnightToday(final Calendar calendar) {

        final Calendar cal = (Calendar) calendar.clone();

        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);

        return cal;
    }

    /**
     * Returns a currency formatted String representation for a Locale.
     *
     * @param value
     * @param currencyCode
     * @return
     */
    public String formatCurrency(double value, String currencyCode) {
        return formatCurrency(value, Currency.getInstance(currencyCode));
    }

    /**
     * Returns a currency formatted String representation for a Locale.
     *
     * @param value
     * @return {@link Currency} currency
     */
    public String formatCurrency(double value, Currency currency) {
        currencyFormat.setCurrency(currency);
        return currencyFormat.format(value);
    }

    /**
     * Return a formatted phone number
     *
     * @param number
     * @return
     */
    public String getFormattedPhoneNumber(final String number) {
        final String formattedNumber;
        String countryCode = locale.getCountry();
        formattedNumber = PhoneNumberUtils.formatNumber(number, countryCode);
        return formattedNumber;
    }

    public boolean isRTLDisplay() {
        return TextUtils.getLayoutDirectionFromLocale(Locale.getDefault()) == View.LAYOUT_DIRECTION_RTL;
    }
}


