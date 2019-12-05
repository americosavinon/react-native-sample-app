//
//  AWCoreNameProtocol.h
//  AWCoreSDK
//
//  Created by Stephen Ciauri on 2/2/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#ifndef AWCoreNameProtocol_h
#define AWCoreNameProtocol_h

#import <Foundation/Foundation.h>

@protocol AWCoreNameProtocol

@property (strong, nonatomic, readonly, nonnull) NSString *firstName;
@property (strong, nonatomic, readonly, nullable) NSString *middleInitial;
@property (strong, nonatomic, readonly, nullable) NSString *middleName;
@property (strong, nonatomic, readonly, nonnull) NSString *lastName;
@property (strong, nonatomic, readonly, nonnull) NSString *fullName;

@end

#endif /* AWCoreNameProtocol_h */
