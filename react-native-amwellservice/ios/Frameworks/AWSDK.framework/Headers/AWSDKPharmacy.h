//
//  AWSDKPharmacy.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/20/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>
#import <MapKit/MapKit.h>

@protocol AWSDKAddress;

/**
 A pharmacy protocol to handle prescriptions prescribed by a provider.

 @since 3.1.0
 */
@protocol AWSDKPharmacy <AWSDKDataObject>
#pragma mark - Read-Only Details
/**
 @name Read-Only Details
 */

/**
 NSString representing the display name of the pharmacy.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString representing the contact email address of the pharmacy.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *contactEmail;

/**
 NSString representing the unformatted contact phone number for the pharmacy.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *contactPhone;

/**
 NSString representing the formatted phone number for the pharmacy.

 @since 4.2.0
 */
@property (nonatomic, readonly, nonnull) NSString *formattedPhoneNumber;

/**
 NSString representing the unformatted contact fax number.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *contactFax;

#pragma mark - Read-Only Location Details
/**
 @name Read-Only Location Details
 */

/**
 AWSDKAddress representing the physical address of the pharmacy.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKAddress> address;

/**
 CLLocationCoordinate2D representing the latitude and longitude for pharmacy.

 @discussion If coordinate == kCLLocationCoordinate2DInvalid, no coordinate is supplied.

 @since 2.0.0
 */
@property (assign, nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 NSNumber distance in miles from the center coordinate provided when searching pharmacies by region given a center and radius.

 @discussion Note that this property will only be populated if you have called [AWSDKPharmacyService fetchPharmaciesWithRegion:completion:]
 Otherwise is will be _nil_ and the distance from a location can be calculated using the provided coordinate property.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSNumber *distance;

#pragma mark - Read-Only Feature Details
/**
 @name Read-Only Feature Details
 */

/**
 BOOL set _TRUE_ if the pharmacy is a mail order pharmacy, otherwise _FALSE_ if not.

 @since 1.0.0
 */
@property (assign, readonly) BOOL isMailOrder;

/**
 BOOL set _TRUE_ if prescriptions are available at the pharmacy, otherwise _FALSE_ if not available.

 @since 1.0.0
 */
@property (assign, readonly) BOOL rxEnabled;

@end
