README
======

If you want to publish the lib as a maven dependency, follow these steps before publishing a new version to npm:

1. Be sure to have the Android [SDK](https://developer.android.com/studio/index.html) and [NDK](https://developer.android.com/ndk/guides/index.html) installed
2. Be sure to have a `local.properties` file in this folder that points to the Android SDK and NDK
```
ndk.dir=/Users/{username}/Library/Android/sdk/ndk-bundle
sdk.dir=/Users/{username}/Library/Android/sdk
```
3. Delete the `maven` folder
4. Run `./gradlew installArchives`
5. Verify that latest set of generated files is in the maven folder with the correct version number

## AWSDK v6.0

We included Amwell SDK v6.0 for this service.

The AWSDK/sdk directory contains the Android library AAR file, corresponding Javadoc in a JAR file, and a small build
.gradle.
