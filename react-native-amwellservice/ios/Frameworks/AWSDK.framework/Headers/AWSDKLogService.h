//
//  AWSDKLogService.h
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

#import <Foundation/Foundation.h>

#pragma mark - Log Level
/**
 @name Log Level
 */

/**
 NS_ENUM representing the log level to write to file or console.

 @since 2.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKLogLevel) {
    /**
     No messages will logged.

     @since 2.0.0
     */
    AWSDKLogLevelOff = 0,
    /**
     A failure in the application.

     @since 2.0.0
     */
    AWSDKLogLevelError = 1,
    /**
     Something is amiss and may cause other failures.

     @since 2.0.0
     */
    AWSDKLogLevelWarn = 2,
    /**
     Lowest priority level for informational purposes.

     @since 2.0.0
     */
    AWSDKLogLevelInfo = 3,
    /**
     Lowest priority only for messages from the kernel or server.

     @since 2.0.0
     */
    AWSDKLogLevelDebug = 4,
    /**
     All messages will be logged.

     @since 2.0.0
     */
    AWSDKLogLevelVerbose = 5,
};

#pragma mark - Macros
/**
 @name Macros
 */

/**
 AWSDKLog macros to inject logs into American Well log files.

 @discussion Each macro logs at a different AWSDKLogLevel. These macros add the timestamp, method, and line number in the log statement.

 @param fmt Formatted string similar to NSLog(fmt, ...).
 @param ... Arguments associated with fmt.

 @since 2.0.0
 */
#define AWSDKLogError(fmt, ...) AWSDKLog(AWSDKLogLevelError, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__);
#define AWSDKLogWarn(fmt, ...) AWSDKLog(AWSDKLogLevelWarn, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__);
#define AWSDKLogInfo(fmt, ...) AWSDKLog(AWSDKLogLevelInfo, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__);
#define AWSDKLogDebug(fmt, ...) AWSDKLog(AWSDKLogLevelDebug, __PRETTY_FUNCTION__, __LINE__, fmt, ##__VA_ARGS__);

/**
 A protocol that describes an object that receives log messages from the AWSDKLogService

 @since 4.1.0
 */
@protocol AWSDKLogServiceDelegate
/**
 Method that is called when the AWSDK has a log message to write

 @param message NSString representation of the log message

 @since 4.1.0
 */
- (void)didReceiveLogMessage:(NSString *)message;
@end

/**
 Logging service to handle SDK internal logging as well as provide an entry point to inject external logs and events.

 @discussion Logs are created in <App Documents>/AWSDKLogs. 1 Log file is created per day, and deletes the oldest log depending on the number of files set. This is by default 7 files. AWSDKLogService
 will also output to console internal and external logs.

 @warning Please do not add any other files to the directory where logs are saved, as they may be deleted without warning.

 @since 2.0.0
 */
@interface AWSDKLogService : NSObject

#pragma mark - Functions
/**
 @name Functions
 */

/**
 Sends a message to the console or file for logging, given formatting parameters.

 @discussion It is recommended to use the given macros defined above rather than calling this function.

 @param level    AWSDKLogLevel defined for the log.
 @param function Method the call was called within.
 @param line     Line number of the log call.
 @param format   Format similar to NSLog's formatting.
 @param ...      Additional variables or arguments used in conjunction with format.

 @since 2.0.0
 */
void AWSDKLog(AWSDKLogLevel level, const char *function, int line, NSString *format, ...) NS_FORMAT_FUNCTION(4, 5);

#pragma mark - Configuration Setters
/**
 @name Configuration Setters
 */

/**
 Sets the sync logging feature to the desired state.  Defaults to NO.

 @discussion Logging synchronously ensures that all logs are written to console or file in the event of an exception or fault. By default, logs using AWSDKLogService are written asynchronously since
 it is not performant to block threads for logging in a production application

 @since 3.2.0
 */
@property (class, nonatomic, readwrite) BOOL synchronousLogging;

/**
 The delegate object that will receive all log messages that the AWSDK outputs.

 @discussion You can use this object to receive all log messages that the AWSDK outputs in order to append to your own log file.

 @note The delegate will only receive log messages that are less than or equal to the verbosity of the consoleLogLevel.

 @since 4.1.0
 */
@property (class, nonatomic, readwrite) id<AWSDKLogServiceDelegate> logDelegate;

/**
 Sets the level of priority for the logging service to log client messages to file.

 @Note Default is set to AWSDKLogLevelDebug.

 @param level AWSDKLogLevel of the highest priority to log client messages to file.

 @since 2.0.0
 */
+ (void)setLogFileLevel:(AWSDKLogLevel)level;

/**
 Sets the level of priority for the logging service for client messages displaying in console.

 @note Default is set to AWSDKLogLevelDebug

 @param level AWSDKLogLevel of the highest priority to log client messages to Console

 @since 2.0.0
 */
+ (void)setConsoleLogLevel:(AWSDKLogLevel)level;

/**
 Sets the number of log files saved before the oldest file is deleted.

 @note Default is set to 7 log files.

 @param files Unsigned integer of how many files to save before deleting the oldest.

 @since 2.0.0
 */
+ (void)setNumberOfFilesSaved:(NSUInteger)files;

#pragma mark - Configuration Getters
/**
 @name Configuration Getters
 */

/**
 Returns the currently set AWSDKLogLevel for client messages writing to file.

 @return AWSDKLogLevel currently set for client messages writing to file.

 @since 2.0.0
 */
+ (AWSDKLogLevel)fileLevel;

/**
 Returns the currently set AWSDKLogLevel for client messages displaying to console.

 @return AWSDKLogLevel currently set for client messages display to console.

 @since 2.0.0
 */
+ (AWSDKLogLevel)consoleLevel;

/**
 Returns the currently set number of files saved before deletion.

 @return Unsigned integer currently set for how many files to be saved.

 @since 2.0.0
 */
+ (NSUInteger)filesSaved;

/**
 Returns the path on disk where the current log file resides

 @return NSURL representing the absolute location of the current log file

 @since 4.0.0
 */
+ (NSURL *)currentLogFilePath;

/**
 Enable printing out network request/response logs including headers and body of request.

 @discussion You must enable SDKLog level of DEBUG or greater for the network logs to show.

 @since 2.1
 */
+ (void)enableNetworkLogs;

/**
 Disable printing out network request/response logs.

 @since 2.1
 */
+ (void)disableNetworkLogs;

@end
