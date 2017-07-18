//
//  CDABaseModal.h
//  native
//
//  Created by Edwin Cen on 9/9/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLModel.h"
#import "CDACamdoraMediaInfo.h"

@interface CDABaseModel :NSObject

@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, strong) NSString *id;

@end
