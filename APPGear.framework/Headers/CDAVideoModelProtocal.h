//
//  CDAVideoModelProtocal.h
//  native
//
//  Created by Edwin Cen on 9/18/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CDAVideoModelProtocal <NSObject>
@property (nonatomic, copy) NSString *mediaUrl;
@property (nonatomic, copy) NSString *thumbnailUrl;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *mediaType;
@end
