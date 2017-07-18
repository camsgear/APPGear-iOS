//
//  CDAPhoto.h
//  Camdora
//
//  Created by wuping on 2017/5/27.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import "CDABaseModel.h"
#import "CDAProfile.h"
#import "CDAUser.h"

@interface CDAPhoto : CDABaseModel

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) CDAProfile *profile;

@property (nonatomic, strong) NSString *photoUrl;
@property (nonatomic, strong) NSString *photoType;

@property (nonatomic, assign) int size;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@end
