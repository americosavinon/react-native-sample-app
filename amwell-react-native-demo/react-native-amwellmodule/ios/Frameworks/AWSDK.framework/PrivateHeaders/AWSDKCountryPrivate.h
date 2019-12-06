//
//  AWSDKCountryPrivatePrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 10/20/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCountry.h>

@class AWSDKState;

@interface AWSDKCountry : AWSDKDataObject <AWSDKCountry>

/**
 Parses json and returns a list of countries.

 @param countriesArray JSON array of coutnries
 @return An array of AWSDKCountries with a fully populated object graph

 @since 4.0.0
 */
+ (NSArray<AWSDKCountry *> *)countriesFromArray:(NSArray<NSDictionary<NSString *, id> *> *)countriesArray;

/**
 Parses json and returns a list of countries. The additional states parameter is used to associate pre-existing states with the newly parsed and populated countries

 @param countriesArray JSON array of countries
 @param states Array of AWSDKStates that will be updated and associated with the newly parsed countries
 @return An array of AWSDKCountries with a fully populated object graph

 @since 4.0.0
 */
+ (NSArray<AWSDKCountry *> *)countriesFromArray:(NSArray<NSDictionary<NSString *, id> *> *)countriesArray updatingStates:(NSArray<AWSDKState *> *)states;

@end
