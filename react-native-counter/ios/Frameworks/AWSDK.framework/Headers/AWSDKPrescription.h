//
//  AWSDKPrescription.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/20/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A prescription prescribed by a provider during or after a visit.

 @since 1.0.0
 */
@protocol AWSDKPrescription <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the description of the medication.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *medicationDescription;

/**
 NSString representing the displayable name of the medication.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *displayName;

/**
 NSString representing instructions for the consumer for taking the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *instructions;

/**
 NSString representing additional instructions for the consumer taking the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *additionalInstructions;

/**
 NSDate when the provider wrote the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSDate *prescribedDate;

/**
 NSString representing the dosage amount of the medication taken at any one time.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *dosage;

/**
 NSString representing the duration during which the prescription should be taken.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *duration;

/**
 NSString representing the frequency which the consumer should take the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *frequency;

/**
 NSString representing the measurement unit the prescription will be given in for an individual dose.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *unit;

/**
 _TRUE_ if the consumer should take the medication when needed, otherwise _FALSE_ if the medication should only be taken as prescribed.

 @since 1.0.0
 */
@property (nonatomic, readonly, assign) BOOL takeAsNeeded;

/**
 _TRUE_ if the patient should take the medication until directed by the doctor to stop, otherwise _FALSE_ and only take with the duration, frequency, and dosage as directed.

 @since 1.0.0
 */
@property (nonatomic, readonly, assign) BOOL stopWhenDirected;

/**
 NSInteger representing the quantity of the medication to be prescribed.

  @since 1.0.0
 */
@property (nonatomic, readonly, assign) NSInteger quantity;

/**
 NSInteger representing the number of times the patient is allowed to refill the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, assign) NSInteger refills;

/**
 NSInteger representing the standard National Drug Code of the prescription.

 @since 1.0.0
 */
@property (nonatomic, readonly, assign) NSInteger code;

@end
