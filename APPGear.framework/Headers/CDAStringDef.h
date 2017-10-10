//
//  CDAStringDef.h
//  native
//
//  Created by Edwin Cen on 9/9/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#ifndef CDAStringDef_h
#define CDAStringDef_h

#import <Foundation/Foundation.h>


#ifndef __OPTIMIZE__
#define CDALog(msg,...)\
{NSLog(@"< - %@ - > %@",[NSString stringWithUTF8String:__FUNCTION__], [NSString stringWithFormat:(msg), ##__VA_ARGS__]);}
#else
#define NSLog(...) {}
#endif



//NSNotification
#define CDA_APP_SIGNOUT       @"cda_app_signOut"//401错误,退出登录
#define CDA_NOTIFICATION_CDAReachabilityStatus @"CDAReachabilityStatus"//网络状态


typedef NS_ENUM(NSInteger,CDALiveType){
    
    CDALiveType_Home_Live = 0, //首页直播观看
    CDALiveType_Home_privateLive, //私密直播观看
    CDALiveType_Home_monitoring  //监控
};

typedef NS_ENUM(NSInteger,CDAMediaIsBelongToMe){
    
    CDABeLongToMe_Video = 0, //video
    CDABeLongToMe_image //image
};

typedef NS_ENUM(NSInteger,CDAUpLoadDataType){
    
    CDAUpLoad_avatar = 0, //上传头像
    CDAUpLoad_covers, //上传直播封面
    CDAUpLoad_videoThumbnail, //发布视频封面路径
    CDAUpLoad_images_cover  //发布图片路径
};

typedef NS_ENUM(NSInteger,CDAFollowOrFans){
    
    CDAFollowOrFans_Follow = 0, //关注
    CDAFollowOrFans_Fans, //粉丝
};

typedef NS_ENUM(NSInteger,CDARechargeOrConsume){
    
    CDARechargeOrConsume_recharge = 0, //充值明细
    CDARechargeOrConsume_consume, //消费明细
    CDARechargeOrConsume_income, //收入明细
};
//signin, signup, signin_signup
typedef NS_ENUM(NSInteger,CDASignType){
    
    CDASignType_signin = 0, //登录
    CDASignType_signup, //登出
    CDASignType_signin_signup, //登录和登出
};

typedef NS_ENUM(NSInteger,CDAThirdType){
    
    CDAThirdType_weibo = 0, //微博
    CDAThirdType_wechat, //微信
    CDAThirdType_qq, //QQ
};

typedef NS_ENUM(int,CDAPicNum){
    
    CDAPicNum_2D = 1,
    CDAPicNum_3D = 2
    
};

typedef NS_ENUM(int,CDAFov){
    
    CDAFov_0 = 0,
    CDAFov_185 = 180,
    CDAFov_180 = 185,
    CDAFov_190 = 190,
    CDAFov_210 = 210,
    CDAFov_220 = 220
    
};

typedef NS_ENUM(int,CDAOrientation){
    CDAOrientation_0 = 0,
    CDAOrientation_90 = 90,
    CDAOrientation_180 = 180,
    CDAOrientation_270= 270
};

typedef NS_ENUM(int,CDACategoryType){
    CDACategoryType_home = 0,
    CDACategoryType_video = 1,
    CDACategoryType_image = 2,
    CDACategoryType_live = 3,
};


typedef void (^CDAEmptyValueCallback)();


#endif /* CDAStringDef_h */




