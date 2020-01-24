/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx;

import android.content.Intent;

import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.visit.ChatReport;
import com.americanwell.sdk.entity.visit.VisitEndReason;

import java.util.Map;

/**
 * This is a custom variation of SDKResponse used to handle the responses from
 * StartVisitCallback
 */
public class SDKStartVisitResponse<T, E extends SDKError> extends SDKValidatedResponse<T, E> {

    private Intent intent;
    private @VisitEndReason String visitEndReason;
    private int patientsAheadOfYou = -1;
    private boolean suggestedTransfer = false;
    private boolean suggestFindFirstAvailable = false;
    private ChatReport chatReport;

    public SDKStartVisitResponse(T result, E error, Map<String, String> validationReasons) {
        super(result, error, validationReasons);
    }

    public SDKStartVisitResponse() {
        super(null, null, null);
    }

    public Intent getIntent() {
        return intent;
    }

    public void setIntent(Intent intent) {
        this.intent = intent;
    }

    public @VisitEndReason
    String getVisitEndReason() {
        return visitEndReason;
    }

    public void setVisitEndReason(@VisitEndReason String visitEndReason) {
        this.visitEndReason = visitEndReason;
    }

    public int getPatientsAheadOfYou() {
        return patientsAheadOfYou;
    }

    public void setPatientsAheadOfYou(int patientsAheadOfYou) {
        this.patientsAheadOfYou = patientsAheadOfYou;
    }

    public boolean isSuggestedTransfer() {
        return suggestedTransfer;
    }

    public void setSuggestedTransfer(boolean suggestedTransfer) {
        this.suggestedTransfer = suggestedTransfer;
    }

    public boolean isSuggestFindFirstAvailable() {
        return suggestFindFirstAvailable;
    }

    public void setSuggestFindFirstAvailable(boolean suggestFindFirstAvailable) {
        this.suggestFindFirstAvailable = suggestFindFirstAvailable;
    }

    public ChatReport getChatReport() {
        return chatReport;
    }

    public void setChatReport(ChatReport chatReport) {
        this.chatReport = chatReport;
    }
}
