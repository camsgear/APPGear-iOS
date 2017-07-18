//
//  CDAVideoModel.h
//  native
//
//  Created by Edwin Cen on 9/11/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import "CLModel.h"
#import "CDABaseModel.h"
#import "CDAProfile.h"
#import "CDAUser.h"

@interface CDAVideo : CDABaseModel

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

///校正参数
@property (nonatomic,copy) NSString *calibrationData;



@end

@interface CDACommnet : CDABaseModel
///  评论id
@property (nonatomic,copy) NSString *commentId;
///  评论内容
@property (nonatomic,copy) NSString *content;

///  评论者ID
@property (nonatomic, copy) NSString *ownerId;

@property (nonatomic,strong) CDAUser *user;
///  评论对象类型
@property (nonatomic,copy) NSString *entityRef;
///  是否推荐置顶
@property (nonatomic,assign)BOOL promoted;
///  评论点赞数
@property (nonatomic,assign)NSInteger votesCount;
///  我是否点赞这条评论
@property (nonatomic,assign)BOOL isVoted;

///  回复评论
@property (nonatomic,strong)CDACommnet *replyComment;

///  是否有回复信息
@property (nonatomic,assign)BOOL replied;

@property (nonatomic,assign)BOOL shouldUpdateCache;

@property (nonatomic,assign)NSInteger cellHeight;

@end
