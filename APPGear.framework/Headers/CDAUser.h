//
//  CDAUser.h
//  native
//
//  Created by Edwin Cen on 9/11/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLModel.h"
#import "CDABaseModel.h"
#import "CDAProfile.h"
#import "CDAAuthProvider.h"
#import "CDAVIPRoleModel.h"

@interface CDAUser : CDABaseModel

@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *role;
@property (nonatomic, strong) NSString *chatRoomToken;
@property (nonatomic, assign) int fansCount;
@property (nonatomic, assign) int followsCount;
@property (nonatomic, strong) CDAProfile *profile;
@property (nonatomic,copy) NSString *uid;
@property (nonatomic,assign)BOOL isFollowed;
@property (nonatomic,assign)NSInteger videosCount;
@property (nonatomic,assign)NSInteger eventsCount;
@property (nonatomic,assign)BOOL isNew;  //是否是第一次登录
@property (nonatomic, strong) NSArray *oauthProviders;  //第三方是否绑定

///  关注关联表id
@property (nonatomic,copy)NSString *recordId;

///  是否是匿名用户
@property (nonatomic,assign)BOOL isAnon;

//@property (nonatomic,assign)BOOL vip; // v3.0.0后弃用，使用vipRole

@property (nonatomic, strong) CDAVIPRoleModel *vipRole;


/**
 头像原地址
 */
@property (nonatomic,copy)NSString *avatarOSS;

/***
 是否选中，用于标识（邀请好友列表中用到）
 */
@property (nonatomic, assign) BOOL isSelected;
/***
 是否受过邀请，用于标识（邀请好友列表中用到）
 */
@property (nonatomic, assign) BOOL isPermission;

@end
