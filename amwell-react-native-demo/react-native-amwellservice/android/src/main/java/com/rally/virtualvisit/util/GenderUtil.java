/*
 * Copyright 2019 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.util;

import android.content.Context;
import android.text.TextUtils;

import com.americanwell.sdk.entity.SystemConfiguration;

import com.americanwell.sdksample.R;
import com.americanwell.sdk.entity.consumer.BiologicalSex;
import com.americanwell.sdk.entity.consumer.Gender;
import com.americanwell.sdk.entity.consumer.GenderIdentity;
import com.americanwell.sdk.internal.entity.consumer.BiologicalSexImpl;
import com.americanwell.sdk.internal.entity.consumer.GenderIdentityImpl;
import com.americanwell.sdksample.BaseSampleNucleusActivity;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import androidx.annotation.NonNull;
import androidx.annotation.VisibleForTesting;

/**
 *
 * @since AWSDK 5.4
 */
public class GenderUtil {

    public static boolean isGenderSupportEnabled(final SystemConfiguration systemConfiguration) {
        return systemConfiguration.isGenderSupportEnabled();
    }

    /**
     * Get a list of biological sex values.
     *
     * @param context context
     * @param systemConfiguration system configuration
     * @return List, return list of supported biological sex
     */
    public static List<BiologicalSex> getBiologicalSexList(final Context context,
                                                           final SystemConfiguration systemConfiguration) {
        final List<BiologicalSex> biologicalSexArray = new ArrayList<>();
        //Add default selection 'Select *'.
//        biologicalSexArray.add(new BiologicalSexImpl(null, context.getString(R.string.app_spinner_unselected_default),
//                null));

        if(isGenderSupportEnabled(systemConfiguration)) {
            //Returns a list of biological sex. MALE and FEMALE should always be present.
            final List<BiologicalSex> serverConfiguredBiologicalSexes = systemConfiguration.getBiologicalSexes();
            //Add biological sexes from the server.
            biologicalSexArray.addAll(serverConfiguredBiologicalSexes);
        }
        else {
            biologicalSexArray.addAll(getDefaultBiologicalSexes(context));
        }
        return biologicalSexArray;
    }

    /**
     * Get the default list of Biological Sex that has been traditionally supported by the platform
     *
     * @param context context
     * @return List, return list of default biological sex
     */
    public static List<BiologicalSex> getDefaultBiologicalSexes(final Context context) {
        final List<BiologicalSex> defaultBiologicalSexes = new ArrayList<>();
//        defaultBiologicalSexes.add(new BiologicalSexImpl(Gender.MALE, context.getString(R.string.app_male),
//                context.getString(R.string.app_male_symbol)));
//        defaultBiologicalSexes.add(new BiologicalSexImpl(Gender.FEMALE, context.getString(R.string.app_female),
//                context.getString(R.string.app_female_symbol)));
        return defaultBiologicalSexes;
    }

    /**
     * Get a list of gender identity values.
     *
     * @return List, return list.
     */
    public static List<GenderIdentity> getGenderIdentityList(final Context context,
                                                             final SystemConfiguration systemConfiguration) {

        final List<GenderIdentity> genderIdentityArray = new ArrayList<>();

        if(isGenderSupportEnabled(systemConfiguration)) {
            //Returns a list of genderIdentities. MALE and FEMALE should always be present.
            final List<GenderIdentity> serverConfiguredIdentities = systemConfiguration.getGenderIdentities();

            //Add default selection 'Select *'.
//            genderIdentityArray.add(new GenderIdentityImpl(null, context.getString(R.string.app_spinner_unselected_default)));
            //Add genderIdentities from the server.
            genderIdentityArray.addAll(serverConfiguredIdentities);
        }
        return genderIdentityArray;
    }

    /**
     * Gets the index of selected gender identity.
     *
     * @return int.
     */
    public static int getSelectedGenderIdentityIndex(final Context context,
                                                     final SystemConfiguration systemConfiguration,
                                                     final String key) {
        int position = 0;
        if(!TextUtils.isEmpty(key) && isGenderSupportEnabled(systemConfiguration)) {
            final List<GenderIdentity> genderIdentityValues = getGenderIdentityList(context, systemConfiguration);
            for(final GenderIdentity genderIdentity : genderIdentityValues) {
                if(!(TextUtils.isEmpty(genderIdentity.getGenderKey())) && genderIdentity.getGenderKey().equalsIgnoreCase(key)){
                    position = genderIdentityValues.indexOf(genderIdentity);
                }
            }
        }
        return position;
    }

    /**
     * Gets the index of selected biological sex.
     *
     * @return int.
     */
    public static int getFilteredBiologicalSexIndex(final Context context,
                                                    final SystemConfiguration systemConfiguration,
                                                    final String key) {
        int position = 0;
        final List<BiologicalSex> biologicalSexValues = getBiologicalSexList(context, systemConfiguration);
        for(final BiologicalSex biologicalSexValue : biologicalSexValues) {
            if(!TextUtils.isEmpty(key) && !(TextUtils.isEmpty(biologicalSexValue.getGender())) &&
                    biologicalSexValue.getGender().equalsIgnoreCase(key)){
                position = biologicalSexValues.indexOf(biologicalSexValue);
            }
        }
        return position;
    }
}
