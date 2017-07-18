//
//  CDAProfile.h
//  native
//
//  Created by Edwin Cen on 9/11/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLModel.h"
#import "CDABaseModel.h"
#import "CDAAddress.h"

@interface CDAProfile : CDABaseModel
@property (nonatomic, strong) NSString *nickname;
@property (nonatomic, strong) NSString *avatar;
@property (nonatomic, assign) int sex;
@property (nonatomic, strong) CDAAddress *address;

/**
 个性签名
 */
@property (nonatomic, strong) NSString *signature;

/**
 用户被关注数
 */
@property (nonatomic,assign)int fansCount;

/**
 用户关注数
 */
@property (nonatomic,assign)int followsCount;

/**
 是否是匿名用户
 */
@property (nonatomic,assign)BOOL isAnon;


@end

@interface CDAChatRoomProfile : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *avatar;

@end
