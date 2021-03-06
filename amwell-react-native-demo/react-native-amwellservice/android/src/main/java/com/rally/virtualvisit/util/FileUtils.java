/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.util;

import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Environment;
import android.provider.OpenableColumns;
import androidx.core.content.FileProvider;
import android.webkit.MimeTypeMap;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.FileAttachment;
import com.americanwell.sdk.entity.UploadAttachment;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import okhttp3.MediaType;

/**
 * Utilities for File handling
 */
public class FileUtils {

    /**
     * Download the given {@link FileAttachment} into an actual File object
     *
     * @param context
     * @param fileAttachment
     * @return
     * @throws IOException
     */
    public File downloadAttachment(final Context context, final FileAttachment fileAttachment) throws IOException {
        final MediaType mediaType = MediaType.parse(fileAttachment.getType());
        String fileName = fileAttachment.getName();
        final String subDir = context.getString(context.getApplicationInfo().labelRes);
        final File path = new File(context.getExternalFilesDir(Environment.DIRECTORY_DOWNLOADS)
                + File.separator
                + subDir);
        path.mkdirs();
        if (!fileName.contains(".")) {
            fileName += "." + mediaType.subtype();
        }
        File file = new File(path, fileName);
        // if file with name already exists... rename with (1), (2), etc...
        int index = 1;
        final int dotIndex = fileName.lastIndexOf(".");
        final String fileNamePrefix = fileName.substring(0, dotIndex);
        final String fileNameExtension = fileName.substring(dotIndex + 1, fileName.length());
        while (file.exists()) {
            fileName = fileNamePrefix + " (" + index++ + ")." + fileNameExtension;
            file = new File(path, fileName);
        }

        FileOutputStream fos = new FileOutputStream(file);
        final OutputStream stream = new BufferedOutputStream(fos);
        int bufferSize = 1024;
        byte[] buffer = new byte[bufferSize];
        int len;
        while ((len = fileAttachment.getInputStream().read(buffer)) != -1) {
            stream.write(buffer, 0, len);
        }
        stream.close();

/*        Intent intent =
                new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE);
        intent.setData(Uri.fromFile(file));
        context.sendBroadcast(intent);*/

        return file;
    }

    /**
     * Get a new instance of an UploadAttachment for a given URI
     *
     * @param context
     * @param awsdk
     * @param uri
     * @return
     * @throws FileNotFoundException
     */
    public UploadAttachment getUploadAttachment(final Context context, final AWSDK awsdk, final Uri uri) throws FileNotFoundException {
        final InputStream inputStream = context.getContentResolver().openInputStream(uri);
        final String type = context.getContentResolver().getType(uri);
        final UploadAttachment uploadAttachment = awsdk.getNewUploadAttachment();
        uploadAttachment.setInputStream(inputStream);
        uploadAttachment.setType(type);
        uploadAttachment.setName(getFileName(context, uri));
        return uploadAttachment;
    }

    /**
     * return the filename for a given URI
     *
     * @param context
     * @param uri
     * @return
     */
    public String getFileName(final Context context, final Uri uri) {
        String result = null;
        if (uri.getScheme().equals("file")) {
            return uri.getLastPathSegment();
        }
        if (uri.getScheme().equals("content")) {
            Cursor cursor = context.getContentResolver().query(uri, null, null, null, null);
            try {
                if (cursor != null && cursor.moveToFirst()) {
                    result = cursor.getString(cursor.getColumnIndex(OpenableColumns.DISPLAY_NAME));
                }
            } finally {
                if (cursor != null) {
                    cursor.close();
                }
            }
        }
        if (result == null) {
            result = uri.getPath();
            int cut = result.lastIndexOf('/');
            if (cut != -1) {
                result = result.substring(cut + 1);
            }
        }
        return result;
    }

}
