//
//  VersionUtils.h
//
//  Created by Ian.Albert on 11/14/11.
//  Adapted for use in this project by Calvin Chestnut on 8/31/15.
//  Copyright 2011 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, VersionCompatibility) { Compatible = 0, ServerVersionNotSupported, ClientVersionNotSupported };

/**
 * Server version ranges that support a given piece of functionality.
 * For use with the supportsFeature: function defined by this class.
 */

/**
 * Static utilities for comparing iOS network API version numbers. Version
 * numbers are of the form X99999, where X is a one-letter product component
 * code and 99999 is an integer version number. Currently supported product
 * component codes are 'J' (for Provider iOS app) and 'O' (for OnlineCare server).
 * Version numbers are monotonically increasing integers with an arbitrary
 * number of digits. Versions cannot be negative and cannot be 0.
 *
 * These methods will throw exceptions if a string is not standard in any way.
 * This includes nil strings, bad prefixes, and unparsable numeric portions.
 * Comparing version strings from different product components will also throw
 * an exception.
 */
@interface VersionUtils : NSObject

/**
 * Tests if two version strings are equal.
 */
+ (BOOL)isVersion:(NSString *)versionStringA equalToVersion:(NSString *)versionStringB;

/**
 * Tests if a version string represents a newer version than another version
 * string.
 */
+ (BOOL)isVersion:(NSString *)versionStringA greaterThanVersion:(NSString *)versionStringB;

/**
 * Tests if a version string represents an older version than another version
 * string.
 */
+ (BOOL)isVersion:(NSString *)versionStringA lessThanVersion:(NSString *)versionStringB;

/**
 * Tests if a version string represents a version that is at least as new as
 * another version string.
 */
+ (BOOL)isVersion:(NSString *)versionStringA greaterThanOrEqualToVersion:(NSString *)versionStringB;

/**
 * Tests if a version string represents a version that is at least as old as
 * another version string.
 */
+ (BOOL)isVersion:(NSString *)versionStringA lessThanOrEqualToVersion:(NSString *)versionStringB;

/**
 * Tests if the given string is a valid version string.
 */
+ (BOOL)isVersionStringValid:(NSString *)versionString;

/**
 * Tests if two version strings are for the same product component. If either
 * version string fails to parse this method returns NO without throwing an
 * exception.
 */
+ (BOOL)isVersion:(NSString *)versionStringA forSameComponentAsVersion:(NSString *)versionStringB;

/**
 * This app's current internal version. Defined in Info.plist under the key
 * InternalVersion.
 */
+ (NSString *)currentVersion;

/**
 * Returns a comma-separated list of supported OnlineCare server version ranges.
 */
+ (NSString *)supportedOnlineCareVersions;

/**
 * Tests whether the given OnlineCare version string is supported.
 */
+ (BOOL)isSupportedOnlineCareVersion:(NSString *)olcVersion;

/**
 * Tests whether a version string is supported by the given version set string.
 */
+ (BOOL)isVersionString:(NSString *)versionString supportedByVersionSet:(NSString *)versionSetString;

/**
 * Tests if another party's reported version and compatible iOS versions list
 * compatible with this app.
 */
+ (BOOL)isCompatibleVersionString:(NSString *)versionString andSupportedVersionsString:(NSString *)supportedVersionsString;

/**
 * Tests if two parties' versions and list of supported versions are compatible.
 * See OnlineCare's VersionUtils.areVersionsCompatible javadoc for full
 * explanation. In short, versionStringA must be contained in
 * supportedVersionsStringB and versionStringB must be contained in
 * supportedVersionsStringA (crossover).
 * @param versionStringA Party A's own version.
 * @param supportedVersionsStringA Party A's supported versions of party B.
 * @param versionStringB Party B's own version.
 * @param supportedVersionsStringB Party B's supported versions of party A.
 * @return YES if the versions are mutually compatible; NO if not
 */
+ (BOOL)isVersionString:(NSString *)versionStringA
     andSupportedVersionsString:(NSString *)supportedVersionsStringA
    compatibleWithVersionString:(NSString *)versionStringB
     andSupportedVersionsString:(NSString *)supportedVersionsStringB;

@end
