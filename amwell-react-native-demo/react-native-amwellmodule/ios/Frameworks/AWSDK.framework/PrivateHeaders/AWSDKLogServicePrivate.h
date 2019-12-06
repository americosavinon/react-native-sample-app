//
//  AWSDKLogServicePrivate.h
//  AWSDK
//
//  Created by Steven Uy on 8/2/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKServicePrivate.h"

#import <AWSDK/AWSDKLogService.h>
#import <os/activity.h>
#import <os/log.h>

#pragma mark Internal Macros

/**
 For internal use only! Do not expose these macros
 */
#define LSLogError(fmt, ...) LSLog(AWSDKLogLevelError, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LSLogWarn(fmt, ...) LSLog(AWSDKLogLevelWarn, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LSLogInfo(fmt, ...) LSLog(AWSDKLogLevelInfo, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LSLogDebug(fmt, ...) LSLog(AWSDKLogLevelDebug, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LSLogVerbose(fmt, ...) LSLog(AWSDKLogLevelVerbose, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define STR_VALUE(arg) #arg

#pragma mark - API logging helpers

/**
 So, I wouldn't exactly call this a 'hack' per se, but it's a bit unconventional.
 In order to execute a log statement upon completion of an API call, we have to modify the completion block that's passed in.
 The APILog*Completion macros use the 'block' parameter and wraps it with a log statement (or whatever else we decide to add to the APILogBegin/End calls)
 */
#define APILogBegin(apiName, verboseArg)                                                                                                                                                               \
    NSAssert([AWSDKService isInitialized], @"The SDK must be initialized before using this resource.");                                                                                                \
    os_activity_t activity = os_activity_create(apiName, OS_ACTIVITY_CURRENT, OS_ACTIVITY_FLAG_DEFAULT);                                                                                               \
    __block struct os_activity_scope_state_s scope;                                                                                                                                                    \
    os_activity_scope_enter(activity, &scope);                                                                                                                                                         \
    LSLogAPI(__PRETTY_FUNCTION__, __LINE__, @"🕒", verboseArg)

#define APILogEnd(error) LSLogAPI(__PRETTY_FUNCTION__, __LINE__, error ? [NSString stringWithFormat:@"🆘 - %@", error] : @"✅", @"")

// Have to explicitly define the BOOL,NSError completion block since you can't pass value types as ids.
#define APILogGenericCompletion(name, block)                                                                                                                                                           \
    APILogBegin(name, @"");                                                                                                                                                                            \
    block = ^(BOOL result, NSError * error) {                                                                                                                                                          \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, error);                                                                                                                                                                      \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

#define APILogGenericCompletionWithStateString(name, block, string)                                                                                                                                    \
    APILogBegin(name, [@" - " stringByAppendingString:string]);                                                                                                                                        \
    block = ^(BOOL result, NSError * error) {                                                                                                                                                          \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, error);                                                                                                                                                                      \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

// This should work with most of the 2-item completion blocks
#define APILogDefaultCompletion(name, block)                                                                                                                                                           \
    APILogBegin(name, @"");                                                                                                                                                                            \
    block = ^(id result, NSError * error) {                                                                                                                                                            \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, error);                                                                                                                                                                      \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

#define APILogDefaultCompletionWithStateString(name, block, string)                                                                                                                                    \
    APILogBegin(name, [@" - " stringByAppendingString:string]);                                                                                                                                        \
    block = ^(id result, NSError * error) {                                                                                                                                                            \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, error);                                                                                                                                                                      \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

// For those tricky 3 argument blocks...
#define APILogDefault3ArgCompletion(name, block)                                                                                                                                                       \
    APILogBegin(name, @"");                                                                                                                                                                            \
    block = ^(id result, id result2, NSError * error) {                                                                                                                                                \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, result2, error);                                                                                                                                                             \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

#define APILogDefault3ArgCompletionWithStateString(name, block, string)                                                                                                                                \
    APILogBegin(name, [@" - " stringByAppendingString:string]) block = ^(id result, id result2, NSError * error) {                                                                                     \
        APILogEnd(error);                                                                                                                                                                              \
        os_activity_scope_enter(activity, &scope);                                                                                                                                                     \
                                                                                                                                                                                                       \
        if (block) {                                                                                                                                                                                   \
            block(result, result2, error);                                                                                                                                                             \
        }                                                                                                                                                                                              \
        os_activity_scope_leave(&scope);                                                                                                                                                               \
    }

@interface AWSDKLogService ()

+ (instancetype)sharedInstance;

@property (nonatomic) AWSDKLogLevel fileLevel;
@property (nonatomic) AWSDKLogLevel consoleLevel;
@property (nonatomic) os_log_t awsdkLogger;
@property (nonatomic) NSUInteger filesSaved;

// Internal
void LSLog(AWSDKLogLevel level, const char *function, int line, NSString *format, ...) NS_FORMAT_FUNCTION(4, 5);
void LSLogAPI(const char *function, int line, NSString *status, NSString *verboseArg);

@end
