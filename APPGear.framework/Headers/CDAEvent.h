//
//  CDAEvent.h
//  Camdora
//
//  Created by Edwin Cen on 18/10/2016.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDABaseModel.h"
#import "CDAProfile.h"
#import "CDAUser.h"

@interface CDAStream : CDABaseModel
@property (nonatomic, strong) NSString *adapter;
@property (nonatomic, assign, readonly) BOOL isLive;
@property (nonatomic, strong) NSString *serialNumber;
@property (nonatomic, strong) NSString *rtmpPushURL;
@property (nonatomic, strong) NSString *rtmpPullURL;
@property (nonatomic, strong) NSString *hlsPullURL;
@property (nonatomic, strong) NSString *snapshotURL;
@end

@interface CDAChannel : CDABaseModel

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subTitle;
@property (nonatomic, strong) NSString *channelDescription;
@property (nonatomic, strong) CDAStream *stream;
@property (nonatomic, strong) NSString *videoType;
@property (nonatomic, strong) NSString *coverURL;
@property (nonatomic, strong) NSString *coverPath;
@property (nonatomic, strong) NSString *chatroomId;
@property (nonatomic, strong) NSString *owner;
@property (nonatomic, assign) int viewsCount;
@property (nonatomic, assign) int filterID;
@property (nonatomic, strong) CDACamdoraMediaInfo *camdoraMediaInfo;
///校正参数
@property (nonatomic,copy) NSString *calibrationData;


@end

//RLM_ARRAY_TYPE(CDAChannel)
@interface CDAEvent : CDABaseModel

@property  NSString *title;
@property  NSString *subTitle;
@property  NSString *eventDescription;
@property  NSArray *tags;
@property  NSString *ownerId;

/**
 直播id
 */
@property  NSString *liveId;
@property  int viewsCount;
@property  CDAUser *user;
@property  NSString *coverUrl;
@property  CDAChannel *channel;
@property  NSArray *channels;
@property  NSString *coverPath;
@property  BOOL isLive;
//关注
@property BOOL isFollowed;

///3.0版本新增属性
@property BOOL isPublic;
@property NSUInteger userLimit;
@property NSUInteger ticketPrice;

///  管理用户列表
@property (nonatomic,strong)NSArray *managers;

@end
