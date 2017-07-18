//
//  CDAAddress.h
//  native
//
//  Created by Edwin Cen on 9/11/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CDAAddress : NSObject

@property (nonatomic, strong) NSString *raw;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, strong) NSString *province;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *cityCode;
@property (nonatomic, strong) NSString *district;
@property (nonatomic, strong) NSString *county;
@property (nonatomic, strong) NSString *street;
@property (nonatomic, strong) NSString *building;
@property (nonatomic, strong) NSString *room;
@property (nonatomic, strong) NSString *zipCode;
@property (nonatomic, strong) NSArray *geo;

@end
