
## 集成
- [手动集成](#手动集成)
- CocoaPod (即将支持)
### 手动集成
#### 1. 下载APPGear-iOS SDK [下载地址](https://github.com/camsgear/APPGear-iOS/releases/tag/1.0.2)
#### 2. 接入APPGear-iOS SDK
- 将APPGear-iOS SDK添加到工程
- 添加项目配置
- `Build Settings` -> `Linking` -> `Ohter linker Flags` 中添加`-ObjC`
- `Build Settings` -> `Architectures` -> `Architectures`中添加`armv7s` 
- `Build Settings` -> `Architectures` -> `Build Active Architecture Only` 改为`NO`
#### 3. 加入依赖库
- `Build phases` -> `Link Binary With Libraries` 中添加 `libresolv.9.tbd`
- `Build phases` -> `Link Binary With Libraries` 中添加 `APPGear-iOS.framework`
#### 4. 初始化
- 在`AppDelegate.m`中添加 `#import <APPGear/APPGear.h>`
- 在`(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions`中添加一下代码:
```Objective-C
(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
///  配置API信息
[CDAAPIManager setUpConfiguration];

///  配置用户信息
[CDAUserManager setUpUserConfiguration];

return YES;
}
```

## 功能模块
- [用户模块](#用户模块)
- [获取手机验证码](#获取手机验证码)
- [登录](#登录)
- [第三方登录](#第三方登录)
- [注销](#注销)
- [获取账户余额](#获取账户余额)
- [视频模块](#视频模块)
- [获取视频数据](#获取视频数据)
- [下拉获取最新数据](#下拉获取最新数据)
- [上拉获取更多视频数据](#上拉获取更多视频数据)
- [发布视频](#发布视频)
- [直播模块](#直播模块)
- [获取直播数据](#获取直播数据)
- [下拉获取最新直播数据](#下拉获取最新直播数据)
- [上拉获取更多直播数据](#上拉获取更多直播数据)
- [获取直播详情数据](#获取直播详情数据)
- [获取直播在线人数及直播状态](#获取直播在线人数及直播状态)

### 用户模块
- [获取手机验证码](#获取手机验证码)
- [登录](#登录)
- [注销](#注销)

#### 获取手机验证码
##### 函数定义
```Objective-C
- (void)getVerifyCodeWithPhoneNumber:(NSString *)phoneNumber
type:(NSString *)type 
success:(UserSuccessBlock)success 
failure:(UserFailureBlock)failure
```
##### 参数说明
- ```phoneNumber``` - 手机号码
- ```type``` - 验证类型 (signin:登录, signup:注册, signin_signup:登录注册通用)
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
[[CDAUserManager sharedManager]getVerifyCodeWithPhoneNumber:self.phoneNumber.text
type:@"signin_signup" 
success:^(id result) {
[SVProgressHUD showSuccessWithStatus:@"获取验证码成功,请注意查看短信"];
} failure:^(NSError *error) {
NSLog(@"%@",error);
[SVProgressHUD showErrorWithStatus:@"获取验证失败,请确认手机号书否输入正确"];
}];
```
---

#### 登录
##### 函数定义
```Objective-C
- (void)signinOrSignup:(NSString *)phone 
verificationCode:(NSString *)code
success:(UserSuccessBlock)success 
failure:(UserFailureBlock)failure
```
##### 参数说明
- ```phone``` - 手机号码
- ```code``` - 手机验证码
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
[[CDAUserManager sharedManager]signinOrSignup:self.phoneNumber.text 
verificationCode:self.verificationCode.text
success:^(id result) {
[SVProgressHUD showSuccessWithStatus:@"登录成功"];
} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"登录失败,请确认手机号和验证码是否输入正确"];
}];
```
---

####第三方登录
#####函数定义

```Objective-C
- (void) CamdoraSignIn: (nullable NSDictionary *)userInfo success:(nonnull UserSuccessBlock)success failure:(nonnull UserFailureBlock)failure Platform:(CDAThirdType)platform
```
##### 参数说明
- ```userInfo``` - 第三方授权成功后的userInfo.originalResponse
-  ```Platform``` -平台类型
- ```success``` - 成功回调
- ```failure``` - 失败回调

##### 示例
```
[[CDAUserManager sharedManager]CamdoraSignIn:@{} success:^(id  _Nonnull result) {

} failure:^(NSError * _Nonnull error) {

} Platform:CDAThirdType_wechat];

```


#### 注销
##### 函数定义

```Objective-C
- (void)signOut: (UserSuccessBlock)success failure: (UserFailureBlock)failure;
```
##### 参数说明
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例

```
- (IBAction)clickOnTheExitTheLogInButton:(id)sender {
[[CDAUserManager sharedManager]signOut:^(id result) {
[SVProgressHUD showSuccessWithStatus:@"注销成功"];
} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"注销失败"];
}];
}
```
#### 获取账户余额
##### 函数定义

```Objective-C
- (void)getWalletSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例

```
[[CDAAPIManager sharedManager]getWalletSuccess:^(id result) {

[SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"%@",result]];
} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"获取失败"];
}];
```

---

### 视频模块
- [获取视频数据](#获取视频数据)
- [下拉获取最新数据](#下拉获取最新数据)
- [上拉获取更多视频数据](#上拉获取更多视频数据)
- [发布视频](#发布视频)

#### 获取视频数据
##### 函数定义
```Objective-C
- (void) getLatestVideos: (APISuccessBlock)success failure:(APIFailureBlock)failure;
```
##### 参数说明
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
//block返回的result已经是转过模型的CDAVideo对象,可直接使用
[[CDAAPIManager sharedManager]getLatestVideos:^(NSArray *result) {
[self.videos addObjectsFromArray:result];
[SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"加载了%ld条数据",(unsigned long)result.count]];
NSLog(@"--视频数据:%@",result);
} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"加载失败"];
}];
```
---

#### 下拉获取最新数据
##### 函数定义
```Objective-C
- (void) getVideosBefore:(NSString *)videoId 
UserId:(NSString *)userId 
success:(APISuccessBlock)success 
failure:(APIFailureBlock)failure
```
##### 参数说明
- ```videoId``` - 当前列表的第一条video数据的id
- ```userId``` - 用户id为想获取视频的用户id, `nil`则获取广场数据，下同
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
CDAVideo *firstVideo = [self.videos firstObject];
//tips: userid区分 获取广场数据,还是个人数据
[[CDAAPIManager sharedManager] getVideosBefore:firstVideo.id UserId:nil success:^(id result) {
NSLog(@"--下拉视频数据:%@",result);
} failure:^(NSError *error) {
}];
```
---
#### 上拉获取更多视频数据
##### 函数定义
```Objective-C
- (void) getVideosAfter:(NSString *)videoId 
UserId:(NSString *)userId 
success:(APISuccessBlock)success 
failure:(APIFailureBlock)failure;
```
##### 参数说明
- ```videoId``` - 当前列表的最后一条video数据的id
- ```userId``` - 用户id
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
CDAVideo *lastVideo = self.videos.lastObject;
//tips: userid区分 获取广场数据,还是个人数据
[[CDAAPIManager sharedManager]getVideosAfter:lastVideo.id UserId:nil success:^(id result) {
NSLog(@"--上拉视频数据:%@",result);
} failure:^(NSError *error) {
}];
```
---
#### 发布视频
##### 函数定义
```Objective-C
- (void)releaseMediaByLocalMedia:(nullable CDALocalMedia *)localMedia MediaType:(CDAMediaIsBelongToMe)mediaType image:(nullable UIImage *)image success:(nonnull APISuccessBlock)success uploadProgress:(nonnull APIUploadProgressBlock)progress failure:(nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```localMedia``` - 待上传的视频对象
- ```mediaType``` - 发布类型
- ```image``` - 视频封面，可为空，为空则取视频第一帧为封面
- ```success``` - 成功回调
- ```progress``` - Progress回调
- ```failure``` - 失败回调
##### 示例

```
Objective-C
- (IBAction)clickPostVideo:(id)sender {

CDALocalMedia *localMedia = [[CDALocalMedia alloc] init];
localMedia.title = @"test";
localMedia.name = @"test";
NSString *mp4Path = [[NSBundle mainBundle]pathForResource:@"test" ofType:@"mp4"];
NSString *imagePath = [[NSBundle mainBundle]pathForResource:@"226.jpg" ofType:nil];
localMedia.mediaUrl = mp4Path;
localMedia.thumbnailUrl = imagePath;
localMedia.videoDescription = @"shahjahjkasjkg";
localMedia.id = [[NSUUID UUID]UUIDString];
localMedia.createdAt = [NSDate date];
localMedia.size = 36841966;
localMedia.duration = 130;
localMedia.width = [UIScreen mainScreen].bounds.size.width;
localMedia.height = [UIScreen mainScreen].bounds.size.width;
localMedia.mediaType = @"videos";

//如果是需要标定参数的视频,需要按如下要求传
localMedia.calibrationData = @"version=v1&type=1&data=0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.,0.0,0.0,0.0,0.0;0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0"; //第二组;

//如果MediaInfo没有 ,需要创建MediaInfo
CDACamdoraMediaInfo *mediaInfo = [CDACamdoraMediaInfo creatMediaInfoWithPicNum:CDAPicNum_2D width:1080 height:1080 fov:CDAFov_185 order:CDACamdoraMediaInfoOrderLeft2Right orientation:CDAOrientation_90 mount:CDACamdoraMediaInfoMountDesktop projection:CDACamdoraMediaInfoProjectionFisheye needStitch:YES fps:30];
localMedia.camdoraMediaInfo = mediaInfo;


[[CDAAPIManager sharedManager]releaseMediaByLocalMedia:localMedia MediaType:CDABeLongToMe_Video image:nil success:^(id result) {

[SVProgressHUD showSuccessWithStatus:@"发布成功"];
} uploadProgress:^(int64_t bytesSent, int64_t totalByteSent, int64_t totalBytesExpectedToSend) {
float percent = 0.8 + 0.2 * totalByteSent / totalBytesExpectedToSend;

[SVProgressHUD showProgress:percent];

} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"发布失败"];

}];


}

```
---

### 直播模块
- [获取直播数据](#获取直播数据)
- [下拉获取最新直播数据](#下拉获取最新直播数据)
- [上拉获取更多直播数据](#上拉获取更多直播数据)
- [获取直播详情数据](#获取直播详情数据)
- [获取直播在线人数及直播状态](#获取直播在线人数及直播状态)
- [获取观看直播权限](#获取观看直播权限)

---


#### 获取直播数据
##### 函数定义
```Objective-C
- (void)getLatestEventsByUserId:(nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```success``` - 成功回调
- ```type``` - type
- ```failure``` - 失败回调
##### 示例

```Objective-C
//block返回的result已经是转过模型的CDAEvent对象,可直接使用
[[CDAAPIManager sharedManager] getLatestEventsByUserId:nil withLiveType:CDALiveType_Home_Live success:^(NSArray *result) {
[self.events addObjectsFromArray:result];

[SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"加载了%ld条数据",(unsigned long)result.count]];


NSLog(@"--直播数据:%@",result);

} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"加载失败"];
}];

```
---
#### 下拉获取最新直播数据
##### 函数定义
```Objective-C
- (void) getEventsBefore: ( nonnull NSString *)eventId UserId:( nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```videoId``` - 当前列表的第一条直播数据的id
- ```userId``` - 用户id为想获取直播的用户id, `nil`则获取广场数据，
- ```type``` - type
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
CDAEvent *firstEvent = self.events.firstObject;//取event的第一条数据
//tips: userid区分 获取广场数据,还是个人数据
[[CDAAPIManager sharedManager]getEventsBefore:firstEvent.id UserId:nil withLiveType:CDALiveType_Home_Live success:^(id result) {
NSLog(@"--下拉直播数据:%@",result);
} failure:^(NSError *error) {

}];
```
---
#### 上拉获取更多直播数据
##### 函数定义
```Objective-C
- (void) getEventsAfter: ( nonnull NSString *)eventId UserId:( nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```videoId``` - 当前列表的最后一条直播数据的id
- ```userId``` - 用户id
- ```type``` - type
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例
```Objective-C
CDAEvent *lastEvent = self.events.lastObject;
//tips: userid区分 获取广场数据,还是个人数据
[[CDAAPIManager sharedManager] getEventsAfter:lastEvent.id UserId:nil withLiveType:CDALiveType_Home_Live success:^(id result) {
NSLog(@"--上拉直播数据:%@",result);

} failure:^(NSError *error) {

}];
```
---

#### 获取直播详情数据
##### 函数定义
```Objective-C
- (void) getEventAndChannelsByEventId:( nonnull NSString *)eventId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```eventId``` - 直播eventId
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例

```Objective-C
- (IBAction)clickLiveingData:(id)sender {

if (self.events.count <= 0) {

[SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];

return;
}

CDAEvent *event = self.events.firstObject;
[[CDAAPIManager sharedManager] getEventAndChannelsByEventId:event.id success:^(id result) {

[SVProgressHUD showSuccessWithStatus:@"获取直播详情数据成功"];

NSLog(@"--直播详情数据:%@",result);
} failure:^(NSError *error) {

if ([error.userInfo[@"code"] longValue] == 403) {

[SVProgressHUD showErrorWithStatus:@"您没有登录,请登录"];

return;
}

[SVProgressHUD showErrorWithStatus:@"获取失败"];
}];

}

```
---

#### 获取直播在线人数及直播状态
##### 函数定义

```Objective-C
- (void) getUserCountByChannelIdAndLiveStatus:(NSString *)channelID 
success:(APISuccessBlock)success 
failure:(APIFailureBlock)failure;
```
##### 参数说明
- ```channelId``` - 直播chennelId
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例

```Objective-C
- (IBAction)getOnLineAndLiveStatus:(id)sender {
if (self.events.count <= 0) {
[SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];
return;
}
CDAEvent *event = self.events.firstObject;
CDAChannel *channel = event.channels.lastObject;
[[CDAAPIManager sharedManager]getUserCountByChannelIdAndLiveStatus:channel.id success:^(id result) {
[SVProgressHUD showSuccessWithStatus:@"获取成功"];
[self.liveStatus setText:[NSString stringWithFormat:@":在线人数%@   直播状态:%@", [result objectForKey:@"popularity"] == nil ? @"0" : [result objectForKey:@"popularity"],[result objectForKey:@"isLive"]]];
} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"获取失败"];
}];
}
```
#### 获取观看直播权限
##### 函数定义

```Objective-C
- (void)getEventPermission:(nonnull NSString *)eventId success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;
```
##### 参数说明
- ```eventId``` - eventId
- ```success``` - 成功回调
- ```failure``` - 失败回调
##### 示例

```
- (IBAction)GetPermissionToWatchLive:(id)sender {
if (self.events.count <= 0) {

[SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];

return;
}
CDAEvent *event = self.events.firstObject;
[[CDAAPIManager sharedManager]getEventPermission:event.id success:^(id result) {
BOOL hasPermission = [[result objectForKey:@"hasPermission"] boolValue];//余额不足,为NO
BOOL isKick = [[result objectForKey:@"isKicked"] boolValue];//默认YES,被踢出为NO


} failure:^(NSError *error) {
[SVProgressHUD showErrorWithStatus:@"获取失败"];
}];


}
```

---
