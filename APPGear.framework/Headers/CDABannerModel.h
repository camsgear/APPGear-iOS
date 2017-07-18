//
//  CDABannerModel.h
//  Camdora
//
//  Created by wuping on 07/07/2017.
//  Copyright © 2017 camdora. All rights reserved.
//

#import "CDABaseModel.h"
#import "CDAUser.h"
#import "CDACamdoraMediaInfo.h"

@interface CDABannerModel : CDABaseModel

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subTitle;
@property (nonatomic, strong) NSString *videoDescription;
@property (nonatomic, assign) int viewsCount;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, assign) int votesCount;
@property (nonatomic, assign) BOOL isVoted;
@property (nonatomic, strong) CDAUser *user;
@property (nonatomic, strong) NSString *coverUrl;

@property (nonatomic, strong) NSString *videoUrl;
@property (nonatomic, strong) NSString *videoType;
@property (nonatomic, assign) int duration;
@property (nonatomic, assign) int size;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
@property (nonatomic, strong) NSString *recordId;
@property (nonatomic, strong) NSString *voteId;
@property (nonatomic, assign) BOOL isFollowed;
@property (nonatomic, assign) int commentsCount;
@property (nonatomic, copy) NSString *ownerId;
@property (nonatomic, strong) CDACamdoraMediaInfo *camdoraMediaInfo;
@property (nonatomic, assign) int filterID;
@property (nonatomic, strong) NSString *dataType; // 数据类型，视频(video)或图片(image)
@property (nonatomic, strong) NSString *type;

@property (nonatomic, assign) BOOL isRemoved;  //该视频是否被删除

@property (nonatomic, copy) NSString *banner;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, assign) BOOL requireToken;

@end
