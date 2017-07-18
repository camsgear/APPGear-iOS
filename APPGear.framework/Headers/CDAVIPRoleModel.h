//
//  CDAVIPRoleModel.h
//  Camdora
//
//  Created by wuping on 2017/6/19.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import "CDABaseModel.h"

typedef NS_ENUM(NSUInteger, CDAVIPRoleType) {
    CDAVIPRoleTypeNormal = 0,   // 没有VIP
    CDAVIPRoleTypeSigned,       // 签约VIP
    CDAVIPRoleTypeLifeLong,     // 终身VIP
    CDAVIPRoleTypeCustomer,     // VIP身份过期
};

@interface CDAVIPRoleModel : CDABaseModel

@property (nonatomic, copy) NSString *entity;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *vipDescription;

@property (nonatomic, assign) CDAVIPRoleType vipType;

@end
