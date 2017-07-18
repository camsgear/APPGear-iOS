//
//  CDAImage.h
//  Camdora
//
//  Created by wuping on 2017/5/31.
//  Copyright © 2017年 camdora. All rights reserved.
//
#import "CDABaseModel.h"
#import "CDAProfile.h"
#import "CDAUser.h"
#import "CLModel.h"

@interface CDAImage : CDABaseModel

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subTitle;
@property (nonatomic, strong) NSString *imageDescription; ///
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSString *coverUrl;
@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic, strong) NSString *imagePath;
@property (nonatomic, strong) NSString *imageOss;
@property (nonatomic, assign) NSInteger votesCount;
@property (nonatomic, assign) NSInteger viewsCount;
@property (nonatomic, assign) NSInteger *commentsCount;
@property (nonatomic, strong) NSString *originId;
@property (nonatomic, strong) NSString *originName;
@property (nonatomic, strong) NSString *ownerId;
@property (nonatomic, strong) CDAUser *user;
@property (nonatomic, assign) BOOL isFollowed;
@property (nonatomic, assign) BOOL isVoted;
@property (nonatomic, strong) CDACamdoraMediaInfo *camdoraMediaInfo;
///校正参数
@property (nonatomic,copy) NSString *calibrationData;


@end
