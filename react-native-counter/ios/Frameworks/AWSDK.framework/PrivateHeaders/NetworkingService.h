//
//  NetworkingService.h
//
//  Created by Calvin Chestnut on 8/31/15.
//  Copyright (c) 2014 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

@import UIKit;

#import "AWJSONResponse.h"
#import "BasicAuthCredentials.h"

static NSString *const kUseJsonSerializer = @"jsonSerializer";
static NSString *const kUseAcceptHeaderVersion = @"acceptHeader";

typedef void (^NetworkSuccessBlock)(NSURLSessionDataTask *task, AWJSONResponse *response);
typedef void (^NetworkSuccessBlockNoContent)(NSURLSessionDataTask *task);
typedef void (^NetworkProgressBlock)(NSProgress *task);
typedef void (^DataSuccessBlock)(NSURLSessionDataTask *task, NSData *response);
typedef void (^ImageSuccessBlock)(NSURLSessionDataTask *task, UIImage *image);
typedef void (^NetworkSimpleSuccessBlock)(NSURLSessionDataTask *task, AWJSONResponse *error);
typedef void (^NetworkFailureBlock)(NSURLSessionDataTask *task, NSError *error);

@interface NetworkingService : NSObject

#pragma mark - Shared Instance
+ (instancetype)sharedInstance;

#pragma mark - Static Methods
+ (void)HEAD:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlockNoContent)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

+ (void)GETImage:(NSString *)url success:(ImageSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

+ (void)GETData:(NSString *)url success:(DataSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

+ (void)GETData:(NSString *)url parameters:(id)parameters success:(DataSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

+ (void)GET:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

+ (void)DELETE:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

+ (void)PUT:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

+ (void)POST:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

+ (void)POSTMultiPart:(NSString *)url
           parameters:(id)parameters
                 data:(NSData *)data
             filename:(NSString *)filename
             mimeType:(NSString *)mimeType
            fieldName:(NSString *)fieldName
             progress:(NetworkProgressBlock)progress
              success:(NetworkSuccessBlock)success
              failure:(NetworkFailureBlock)failure
          credentials:(id<NetworkCredentials>)credentials
              options:(NSDictionary *)dict;

#pragma mark - Certificate pinning
+ (void)addCertificate:(NSData *)certificate;

#pragma mark - Dynamic Methods

/**
 Used for logging reasons only. Helps to associate a session with a network call
 */
@property (nonatomic, readwrite) NSUUID *callerID;

- (void)GETImage:(NSString *)url success:(ImageSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

- (void)GETData:(NSString *)url success:(DataSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

- (void)GETData:(NSString *)url parameters:(id)parameters success:(DataSuccessBlock)success failure:(NetworkFailureBlock)failure credentials:(id<NetworkCredentials>)credentials;

- (void)GET:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

- (void)DELETE:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

- (void)PUT:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

- (void)POST:(NSString *)url
     parameters:(NSDictionary<NSString *, id> *)parameters
        success:(NetworkSuccessBlock)success
        failure:(NetworkFailureBlock)failure
    credentials:(id<NetworkCredentials>)credentials
        options:(NSDictionary *)dict;

- (void)POSTMultiPart:(NSString *)url
           parameters:(NSDictionary<NSString *, id> *)parameters
                 data:(NSData *)data
             filename:(NSString *)filename
             mimeType:(NSString *)mimeType
            fieldName:(NSString *)fieldName
             progress:(NetworkProgressBlock)progress
              success:(NetworkSuccessBlock)success
              failure:(NetworkFailureBlock)failure
          credentials:(id<NetworkCredentials>)credentials
              options:(NSDictionary *)dict;
@end
