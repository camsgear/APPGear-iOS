//
//  CDAUserManager.h
//  native
//
//  Created by Edwin Cen on 9/20/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDAProfile.h"
#import "CDALocalMedia.h"
#import "CDAStringDef.h"
#import "CDAVIPRoleModel.h"



typedef void (^UserSuccessBlock)(id _Nonnull result);
typedef void (^UserFailureBlock)(NSError  * _Nonnull error);

@interface CDAUserManager : NSObject


///  配置用户信息
/// 需要在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions中添加
+ (void)setUpUserConfiguration;


+(instancetype _Nullable ) sharedManager;
///  发布视频总数
@property (nonatomic, assign, readonly) int currentUserPublishVideoCount;
///  发布图片总数
@property (nonatomic, assign, readonly) int currentUserPublishImageCount;
///  直播总数
@property (nonatomic, assign, readonly) int currentUserLiveCount;
///  私密直播数量
@property (nonatomic, assign ,readonly) int currentUserPrivateEventsCount;

///  是否登录
///
///  @return YES 登录成功 NO 登录失败
- (BOOL) isUserLogin;

///  是否关闭自动播放功能
///
///  @return YES 关闭  NO 开启
- (BOOL) isAutoPlayOff;

///  启用自动播放
- (void) enableAutoPlay;

///  禁用自动播放
- (void) disableAutoPlay;
///  当前用户头像
///
///  @return 头像地址
- (NSString *_Nullable)currentProfileAvatar;

///  当前用户昵称
///
///  @return 昵称
- (NSString *_Nullable)currentProfileNickname;

///  当前配置文件签名
///
///  @return signature
- (NSString *_Nullable)currentProfileSignature;


///  当前用户的角色
///
///  @return userRole
- (NSString *_Nullable)currentUserRole;
///  当前用户的Token
///
///  @return token
- (NSString *_Nullable)currentUserToken;

///  当前用户ID
///
///  @return userId
- (NSString *_Nullable)currentUserId;

///  vipRole类型
///
///  @return vip类型
- (CDAVIPRoleType)currentUserVIPRole;

////  使用手机登录/注册
///
///  @param phone   手机号码
///  @param code    手机验证码
///  @param success 成功回调
///  @param failure 失败回调
- (void) signinOrSignup: (nonnull NSString *)phone verificationCode:(nonnull NSString *) code success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;


///  获取手机验证码
///
///  @param phone   手机号码
///  @param type    验证类型 (signin, signup, signin_signup)
///  @param success 成功回调
///  @param failure 失败回调
- (void) getVerifyCodeWithPhone:(nonnull NSString *)phone type:(CDASignType)type success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;


/**
 使用邮箱登录

 @param mailAccount 邮箱账号
 @param passWord 密码
 @param success 成功回调
 @param failure 失败回调
 */
- (void) signinWithE_MailAccount:( nonnull NSString *)mailAccount passWord:( nonnull NSString *)passWord success:( nonnull UserSuccessBlock)success failure:( nonnull UserFailureBlock)failure;

///  退出登录
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) signOut: (nonnull UserSuccessBlock)success failure: (nonnull UserFailureBlock)failure;

///  第三方登录接口 注:此接口只提供 微博,微信,QQ登陆
///
///  @param userInfo 第三方授权成功后的userInfo.originalResponse
///  @param success  成功回调
///  @param failure  失败回调
///  @param platform 传到后台的第三方平台key 
- (void) CamdoraSignIn: (nonnull NSDictionary *)userInfo success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure Platform:(CDAThirdType)platform;

///  获取用户个人信息
///
///  @param uid     userID
///  @param success 成功回调
///  @param failure 失败回调
- (void)getUserInfoWithUserID:(nonnull NSString *)uid Success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  更新用户信息
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) updateCurrenUserProfile: (nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  提交 头像或封面
///
///  @param avatarPath 阿里云返回路径
///  @param success    成功回调
///  @param failure    失败回调
- (void) postAvatarOrCoverAvatarPath:(nonnull NSString *)avatarPath success:(nonnull UserSuccessBlock)success failure:(nonnull UserSuccessBlock)failure;

///  提交用户信息
///
///  @param uid        userID
///  @param name       name
///  @param avatarPath 头像地址
///  @param success    成功回调
///  @param failure    失败回调
- (void) patchInfoWithUserId:(nonnull NSString *)uid UserName:(nullable NSString *)name ImagePath:(nullable NSString *)avatarPath success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  提交用户信息
///
///  @param uid     userID
///  @param nickName 昵称
///  @param signature 签名
///  @param success 成功回调
///  @param failure 失败回调
- (void) patchInfoWithUserId:(nonnull NSString *)uid nickName:(nullable NSString *)nickName signature:(nullable NSString *)signature success:( nonnull UserFailureBlock)success failure:( nonnull UserFailureBlock)failure;

///  更新头像
///
///  @param avatarPath 头像地址
///  @param success    成功回调
///  @param failure    失败回调
- (void) postAvatarWithImagePath:(nonnull NSString *)avatarPath success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  绑定第三方账号
///
///  @param uid      userID
///  @param type     第三方 列:新浪微博:weibo 微信:wechat QQ:qq
///  @param userinfo userinfo.originalResponse
///  @param success  成功回调
///  @param failure  失败回调
- (void) postBindWithUserId:(nonnull NSString *)uid authType:(CDAThirdType)type userinfo:(nonnull NSDictionary *)userinfo success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  解绑第三方账号
///
///  @param type    第三方 列:新浪微博:weibo 微信:wechat QQ:qq
///  @param success 成功回调
///  @param failure 失败回调
- (void) getUnBindAuthType:(CDAThirdType)type success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure;

///  更新当前用户 发布,收藏,直播的数量
///
///  @param callback 回调
- (void) updateCurrentUserCountInfo: (nonnull CDAEmptyValueCallback)callback;

@end
