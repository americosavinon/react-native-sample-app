//
//  AWSDKRemoteLogMessage.h
//  AWSDK
//
//  Created by Rolin Nelson on 9/6/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKRemoteLogMessageParamPrivate.h>
#import <Foundation/Foundation.h>

#pragma mark - Log Level
/**
 @name Log Level
 */

/**
 NS_ENUM representing the log level to write to file or console.

 @since 4.2.0
 */
typedef NS_ENUM(NSInteger, AWSDKRmtLogMsgLevel) {
    /**
     No messages will logged.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelOff = -1,
    /**
     A fatal error in the application.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelFatal = 0,
    /**
     A failure in the application.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelError = 1,
    /**
     Something is amiss and may cause other failures.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelWarn = 2,
    /**
     Lowest priority level for informational purposes.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelInfo = 3,
    /**
     Lowest priority only for messages from the kernel or server.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelDebug = 4,
    /**
     All messages will be logged.

     @since 4.2.0
     */
    AWSDKRmtLogMsgLevelTrace = 5,
};

#pragma mark - Macros
/**
 @name Macros
 */

/**
 AWSDKLog macros to inject logs into American Well log files.

 @discussion Each macro logs at a different AWSDKRmtLogMsgLevel. These macros add the timestamp, method, and line number in the log statement.

 @param fmt Formatted string similar to NSLog(fmt, ...).
 @param ... Arguments associated with fmt.

 @since 4.2.0
 */
#define AWSDKRmtLogMsgFatal(params, fmt, ...)                                                                                                                                                          \
    LSLogError(fmt, ##__VA_ARGS__);                                                                                                                                                                    \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelFatal, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)
#define AWSDKRmtLogMsgError(params, fmt, ...)                                                                                                                                                          \
    LSLogError(fmt, ##__VA_ARGS__);                                                                                                                                                                    \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelError, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)
#define AWSDKRmtLogMsgWarn(params, fmt, ...)                                                                                                                                                           \
    LSLogWarn(fmt, ##__VA_ARGS__);                                                                                                                                                                     \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelWarn, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)
#define AWSDKRmtLogMsgInfo(params, fmt, ...)                                                                                                                                                           \
    LSLogInfo(fmt, ##__VA_ARGS__);                                                                                                                                                                     \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelInfo, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)
#define AWSDKRmtLogMsgDebug(params, fmt, ...)                                                                                                                                                          \
    LSLogDebug(fmt, ##__VA_ARGS__);                                                                                                                                                                    \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelDebug, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)
#define AWSDKRmtLogMsgTrace(params, fmt, ...)                                                                                                                                                          \
    LSLogVerbose(fmt, ##__VA_ARGS__);                                                                                                                                                                  \
    AWSDKRmtLogMsg(AWSDKRmtLogMsgLevelTrace, __PRETTY_FUNCTION__, __LINE__, params, fmt, ##__VA_ARGS__)

/**
 Logging service to log all key events to the server.

 @since 4.2.0
 */
@interface AWSDKRemoteLogMessage : NSObject

#pragma mark - Functions
/**
 @name Functions
 */

/**
 Sends a message to the console or file for logging, given formatting parameters.

 @discussion It is recommended to use the given macros defined above rather than calling this function.

 @param level    AWSDKRmtLogMsgLevel defined for the log.
 @param function Method the call was called within.
 @param line     Line number of the log call.
 @param format   Format similar to NSLog's formatting.
 @param ...      Additional variables or arguments used in conjunction with format.

 @since 2.0.0
 */
void AWSDKRmtLogMsg(AWSDKRmtLogMsgLevel level, const char *_Nonnull function, int line, NSArray<AWSDKRemoteLogMessageParam *> *_Nullable params, NSString *_Nullable format, ...)
    NS_FORMAT_FUNCTION(5, 6);

@end

@interface AWSDKRemoteLogMessage ()

@property (assign, nonatomic, readwrite) AWSDKRmtLogMsgLevel level;
@property (nonatomic, readwrite, nonnull) NSString *message;

+ (nullable instancetype)sharedInstance;
- (void)logMessage:(NSString *_Nonnull)message withParameters:(nullable NSArray<AWSDKRemoteLogMessageParam *> *)parameters withLevel:(AWSDKRmtLogMsgLevel)level;
- (void)logMessage:(NSString *_Nonnull)message
    withParameters:(nullable NSArray<AWSDKRemoteLogMessageParam *> *)parameters
         withLevel:(AWSDKRmtLogMsgLevel)level
        completion:(nullable GenericCompletionBlock)completion;

@end
