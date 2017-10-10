//
//  CDAAPIManager.h
//  native
//
//  Created by Edwin Cen on 9/11/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLNetworking.h"
#import "CDAStringDef.h"
#import "CDAModels.h"

typedef NSURLSessionTask CDAURLSessionTask;
typedef void (^APISuccessBlock)(id _Nonnull result);
typedef void (^APIFailureBlock)(id _Nonnull error);
typedef void (^APIProgressBlock)(NSProgress * _Nonnull progress);
typedef void (^APIUploadProgressBlock)(int64_t bytesSent, int64_t totalByteSent, int64_t totalBytesExpectedToSend);

@interface CDAAPIManager : CLHTTPSessionManager

///  API配置信息
/// 需要在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions中添加
+ (void)setUpConfigurationWithAppKey:(nonnull NSString *)appkey appName:(nonnull NSString *)appName;

// 返回分享视频地址
- (nonnull NSString *)getSharedVideoWithVideoId:(nonnull NSString *)videoId;

// 返回分享图片地址
- (nonnull NSString *)getSharedImageWithImageId:(nonnull NSString *)imageId;

///  CDAAPIManager单列
///
///  @return self
+ (instancetype _Nonnull ) sharedManager;

///  取消所有网络请求
+ (void)cancelAllRequest;

///  取消单个网络请求
///
///  @param url URL
+ (void)cancelRequestWithURL:(nonnull NSString *)url;

///  添加header头部信息
///
///  @param value  value
///  @param header header
- (void) addHeaderToManager: (nonnull NSString *)value forHeaderField: (nonnull NSString *)header;

///  通过userID 获取视频
///
///  @param uid     userID
///  @param success 成功回调
///  @param failure 失败回调
- (void) getVideosByUserID:(nonnull NSString *)uid success: ( nonnull APISuccessBlock)success failure: ( nonnull APIFailureBlock)failure;

///  通过videoID获取视频
///
///  @param videoId videoID
///  @param success 成功回调
///  @param failure 失败回调
- (void) getVideoByVideoID:(nonnull NSString *)videoId success: ( nonnull APISuccessBlock)success failure: ( nonnull APIFailureBlock)failure;

///  获取videoId 之后的视频
///
///  @param videoId videoID
///  @param userId  userID 可选
///  @param success 成功回调
///  @param failure 失败回调
- (void) getVideosAfter:(nonnull NSString *)videoId UserId:(nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取videoID 之前的视频
///
///  @param videoId videoID
///  @param userId  userID 只能获取用户个人的数据,广场数据下拉请调用
///  - (void) getLatestVideos: (APISuccessBlock)success failure:(APIFailureBlock)failure;
///  @param success 成功回调
///  @param failure 失败回调
- (void) getVideosBefore: (nonnull NSString *)videoId UserId:( nonnull NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取我的最新视频
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) getMyLatestVideos: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过videoid 获取之后的视频
///
///  @param currentId videoID
///  @param success   成功回调
///  @param failure   失败回调
- (void) getMyVideosAfter: ( nonnull NSString *)currentId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取用户,发布,收藏,直播,私密直播数量
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getUserReleasedAndCollectionAndLiveNumber:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取我收藏的最新视频
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) getMyLatestFavouriteVideos: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过videoID 获取之后的收藏视频
///
///  @param voteId  videoID
///  @param success 成功回调
///  @param failure 失败回调
- (void) getMyFavouriteVideosAfter: ( nonnull NSString *)voteId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  给视频点赞
///
///  @param videoId videoID
///  @param success 成功回调
///  @param failure 失败回调
- (void) voteVideo:( nonnull NSString *)videoId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  取消视频点赞
///
///  @param videoId videoID
///  @param success 成功回调
///  @param failure 失败回调
- (void) unvoteVideo:( nonnull NSString *)videoId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  刷新聊天token
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) refreshChatToken: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取聊天token
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) getChatToken: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventID 获取直播
///
///  @param eventId   eventID
///  @param success   成功回调
///  @param failure   失败回调
- (void) getEventAndChannelsByEventId:( nonnull NSString *)eventId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过userID 获取event
///
///  @param userId  userID
///  @param type    直播type
///  @param success 成功回调
///  @param failure 失败回调
- (void)getEventByUserId:( nonnull NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///    获取最新的直播
///
///  @param userId  userId
///  @param type    直播type
///  @param success 成功回调
///  @param failure 失败回调
- (void)getLatestEventsByUserId:(nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventID 和 userID 获取之后的直播
///
///  @param eventId eventID
///  @param userId  userID 可选
///  @param type    直播type
///  @param success 成功回调
///  @param failure 失败回调
- (void) getEventsAfter: ( nonnull NSString *)eventId UserId:( nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventID 和 userID 获取之前的直播
///
///  @param eventId eventID
///  @param userId  userID 可选
///  @param type    直播type
///  @param success 成功回调
///  @param failure 失败回调
- (void) getEventsBefore: ( nonnull NSString *)eventId UserId:( nullable NSString *)userId withLiveType:(CDALiveType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventID 和 userID 获取之前的直播
///
///  @param eventId eventID
///  @param userId  userID 可选
///  @param type    直播type
///  @param limit   一次获取的数量
///  @param success 成功回调
///  @param failure 失败回调
-(void)getEventsBefore:( nonnull NSString *)eventId UserId:( nullable NSString *)userId withLiveType:(CDALiveType)type withLimit:(int)limit success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取房间在线人数和直播状态
///
///  @param channelID channelID
///  @param success   success
///  @param failure   failure
- (void) getUserCountByChannelIdAndLiveStatus: ( nonnull NSString *)channelID success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取最新的直播数据
///
///  @param success 成功回调
///  @param failure 失败回调
- (void) getMyLatestEvents: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventID 获取之后的直播数据
///
///  @param eventId eventID
///  @param success 成功回调
///  @param failure 失败回调
- (void) getMyEventsAfter: ( nonnull NSString *)eventId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过eventIDs 获取直播的状态
///
///  @param eventIDs eventIDs
///  @param success  成功回调
///  @param failure  失败回调
- (void) getEventsStatusByIds:( nonnull NSArray *)eventIDs success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  加入聊天室
///
///  @param chatroomId channelID
///  @param success    成功回调
///  @param failure    失败回调
- (void) joinChatRoom: ( nonnull NSString *)chatroomId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  退出聊天室
///
///  @param chatroomId channelID
///  @param success    成功回调
///  @param failure    失败回调
- (void) quitChatRoom: ( nonnull NSString *)chatroomId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过userIDs 获取用户信息
///
///  @param ids     ids
///  @param success 成功回调
///  @param failure 失败回调
- (void) getUsersByIds: ( nonnull NSArray *)ids success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取在线观看的人
///
///  @param channelId channelID
///  @param success   success
///  @param failure   failure
- (void) getChannelOnLinesById:( nonnull NSString *)channelId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取在线人数上拉、下拉
///
///  @param channelId channelID
///  @param isPull    YES下拉
///  @param success   success
///  @param failure   failure
- (void) getChannelOnLinesById:( nonnull NSString *)channelId isPull:(BOOL)isPull userId:( nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  是否启用日志
///
///  @param sid     sid
///  @param success 成功回调
///  @param failure 失败回调
- (void) getIsLogEnabled: ( nonnull NSString *)sid success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  发送设备日志
///
///  @param sid          sid
///  @param relativePath 相对路径
///  @param fileSize     文件大小
///  @param success      成功回调
///  @param failure      失败回调
- (void) postDeviceLogs: ( nonnull NSString *)sid relativePath: ( nonnull NSString *)relativePath fileSize: (long)fileSize success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过userID 关注用户
///
///  @param userId  userID
///  @param follow  0 取消关注 / 1 关注
///  @param success 成功回调
///  @param failure 失败回调
- (void) getIsFollowedUserId:( nonnull NSString *)userId Follow:(NSInteger)follow success:( nonnull APISuccessBlock)success Failure:( nonnull APIFailureBlock)failure;

///  通过userID获取关注的用户
///
///  @param userId  userID
///  @param type    fans / follow
///  @param success 成功回调
///  @param failure 失败回调
- (void) getUsersFollow:( nonnull NSString *)userId Type:(CDAFollowOrFans)type Success:( nonnull APISuccessBlock)success Faulure:( nonnull APIFailureBlock)failure;

///  通过userID 获取之后的关注/粉丝用户
///
///  @param userId   userID
///  @param type     fans / follow
///  @param targetId targetID
///  @param success  成功回调
///  @param failure  失败回调
-(void)getFollowsAfterUserId:( nonnull NSString *)userId Type:(CDAFollowOrFans)type TargetId:( nonnull NSString *)targetId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  通过userID 获取之前的关注 / 粉丝 用户
///
///  @param userId   userID
///  @param type     fans / follow
///  @param targetId targetID
///  @param success  成功回调
///  @param failure  失败回调
- (void)getFollowsBeforeUserId:( nonnull NSString *)userId Type:(CDAFollowOrFans)type TargetId:( nonnull NSString *)targetId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取好友
///
///  @param friendId 好友ID 用来下拉或上拉,第一次获取可不传
///  @param pullDown 是否是下拉
///  @param success  成功回调
///  @param failure  失败回调
-(void)getUserFriendsWithUserFriendId:( nonnull NSString *)friendId IsPullDown:(BOOL)pullDown success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;


///  获取视频评论列表
///
///  @param videoId videoID
///  @param commentId commentId 可选
///  @param isUp  上拉:NO 下拉:YES  第一次获取数据:NO
///  @param success 成功回调
///  @param failure 失败回调
- (void)getVideoCommentByVideoId:( nonnull NSString *)videoId CommentId:( nullable NSString *)commentId isUp:(BOOL)isUp success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  添加视频评论
///
///  @param videoId videoId
///  @param content 评论的内容
///  @param success 成功回调
///  @param failure 失败回调
- (void)postVideoCommentByVideoId:( nonnull NSString *)videoId Content:( nonnull NSString *)content success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  视频评论点赞
///
///  @param commentId commentID
///  @param success   success
///  @param failure   failure
-(void)getVideoCommentByCommentId:( nonnull NSString *)commentId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  回复评论
///
///  @param commentId commentID
///  @param content   评论内容
///  @param success   success
///  @param failure   failure
-(void)postVideoCommentByCommentId:( nonnull NSString *)commentId Content:( nonnull NSString *)content success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
///  删除 评论
///
///  @param commentId commentId
///  @param success   success
///  @param failure   failure
-(void)deleteVideoCommentByCommentsId:( nonnull NSString *)commentId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  下载文件
///
///  @param url      url
///  @param filePath FilePath
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) downloadFileFromURL: ( nonnull NSString *)url toDestination: ( nonnull NSString *)filePath progress:( nonnull APIProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  上传文件
///
///  @param url      url
///  @param filePath FilePath
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) uploadFileToURL: ( nonnull NSString *)url fromFilePath: ( nonnull NSString *)filePath progress:( nonnull APIProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  上传文件
///
///  @param filePath filePath
///  @param fileKey  fileKey
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) uploadFile: ( nonnull NSString *)filePath fileKey: ( nonnull NSString *)fileKey withProgress:( nonnull APIUploadProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  检查图片或视频有没有发布过
///
///  @param mediaType 视频 或者 图片
///  @param mediaId   videoId or imageId
///  @param success   成功回调
///  @param failure   失败回调
- (void) isMediaBelongToMeWithMediaType:(CDAMediaIsBelongToMe)mediaType MediaId:( nonnull NSString *)mediaId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  上传视频,图片
///
///  @param oid      mediaId
///  @param mediaType 视频,图片
///  @param path     上传地址
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) uploadMeidaById: ( nonnull NSString *)oid mediaType:(CDAMediaIsBelongToMe)mediaType andFilePath: ( nonnull NSString *)path withProgress:( nonnull APIUploadProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

////  上传缩略图
///
///  @param oid      图片id
///  @param mediaType 视频,图片
///  @param path      上传地址
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) uploadThumbnailById: ( nonnull NSString *)oid mediaType:(CDAMediaIsBelongToMe)mediaType  andFilePath: ( nonnull NSString *)path withProgress:( nonnull APIUploadProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  上传数据
///
///  @param Data     data
///  @param uuid     uuid [NSUUID UUID];
///  @param type     type
///  @param progress 进度
///  @param success  成功回调
///  @param failure  失败回调
- (void) uploadData: ( nonnull NSData *)Data UUID:( nonnull NSString *)uuid withType:(CDAUpLoadDataType)type withProgress:( nonnull APIUploadProgressBlock)progress success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  发布视频或者图片
///
///  @param localMedia localMedia 模型
///  @param mediaType  mediaType
///  @param image      封面 可选
///  @param success    成功回调
///  @param progress   进度回调
///  @param failure    失败回调
- (void)releaseMediaByLocalMedia:(nonnull CDALocalMedia *)localMedia MediaType:(CDAMediaIsBelongToMe)mediaType image:(nullable UIImage *)image success:(nonnull APISuccessBlock)success uploadProgress:(nonnull APIUploadProgressBlock)progress failure:(nonnull APIFailureBlock)failure;

///  更新后台视频封面
///
///  @param mediaType 区分视频,图片
///  @param mediaId   mediaId
///  @param coverPath 阿里云新地址
///  @param success    成功回调
///  @param failure    失败回调
- (void)postMediaCoverCommandWithMediaType:(CDAMediaIsBelongToMe)mediaType MediaId:( nonnull NSString *)mediaId CoverPath:( nonnull NSString *)coverPath success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;


///  验证支付
///
///  @param receipt 收据
///  @param success 成功回调
///  @param failure 失败回调
- (void)verifyThePaymentWithReceipt:(nonnull NSString *)receipt success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

///  获取商品列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getIAPProducesListSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

///  获取充值明细或者消费明细和收入明细
///
///  @param pullDown 判断下拉还是上拉
///  @param Id       id
///  @param success  成功回调
///  @param failure  失败回调
- (void)getRechargeOrConsume:(CDARechargeOrConsume)type IsPullDown:(BOOL)pullDown rechargeOrConsumeId:(nonnull NSString *)Id success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;


///  获取账户余额
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getWalletSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;


#pragma mark - 首页
///  获取首页数据
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getDataHomeSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

///  获取首页分类数据

#pragma mark - 查看用户Event权限
///  查看用户Event权限
///
///  @param eventId 直播ID
///  @param success 成功回调
///  @param failure 失败回调
- (void)getEventPermission:(nonnull NSString *)eventId success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

#pragma mark - 搜索
///  首页搜索
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getDataCategoriesSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

#pragma mark - 搜索
///  首页搜索
///
///  @param keyword 搜索关键字
///  @param success 成功回调
///  @param failure 失败回调
- (void)getAllResultWithKeyword:(nonnull NSString *)keyword Success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

#pragma mark - 首页 Image API
///  获取最新图片列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewImagesSuccess:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

///  获取imageId之前图片列表
///
///  @param imageId 获取imageId之前的图片
///  @param success 成功回调
///  @param failure 失败回调
- (void) getImagesBeforeWithImageId:(nullable NSString *)imageId UserId:(nullable NSString *)userId success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

/// 获取更多图片图片
///
///  @param imageId 获取imageId后面的图片
///  @param userId  userId
///  @param success 成功回调
///  @param failure 失败回调
- (void)getImagesAfterWithImageId:(nonnull NSString *)imageId userId:(nullable NSString *)userId success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

#pragma mark - 获取用户图片

/**
 通过userID获取用户图片

 @param uid userID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getUserImagesByUserId:(nonnull NSString *)uid success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

/**
 通过imageID获取之前的图片(最新的)

 @param imageId imageID
 @param uid userID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getUserImagesBeforeImageId:(nonnull NSString *)imageId userId:(nonnull NSString *)uid success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;

/**
 通过imageID获取之后的图片

 @param imageId imageID
 @param uid userID
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getUserImagesAfterImageId:(nonnull NSString *)imageId userId:(nonnull NSString *)uid success:(nonnull APISuccessBlock)success failure:(nonnull APIFailureBlock)failure;


#pragma mark - 首页 video API
///  获取最新视频列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getLatestVideosSuccess:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取videoId之前视频列表
///
///  @param videoId 获取videoId之前的图片
///  @param success 成功回调
///  @param failure 失败回调
- (void)getVideosBeforeWithVideoId:( nonnull NSString *)videoId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

/// 获取更多视频
///
///  @param videoId 获取videoId后面的视频
///  @param success 成功回调
///  @param failure 失败回调
- (void)getVideosAfterWithVideoId:( nonnull NSString *)videoId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

/// 视频增加观看次数
///
///  @param videoId videoId
///  @param success 成功回调
///  @param failure 失败回调
- (void)setVideosIncreaseViewsCountByVideoId:( nonnull NSString *)videoId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

#pragma mark - 首页 media API
///  获取最新"new"视频或图片列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewNewerMediasSuccess:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取mediaId之前更多"new"视频或图片
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewerMediasBefore:( nonnull NSString *)mediaId userId:( nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

/// 获取更多"new"视频或图片
///
///  @param mediaId 获取mediaId后面的图片
///  @param userId  userId
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewerMediasAfter:( nonnull NSString *)mediaId userId:( nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取最新"top"视频或图片列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewTopMediasSuccess:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

/// 获取更多"top"视频或图片
///
///  @param skipCount 获取第skipCount张后面的图片
///  @param userId  userId
///  @param success 成功回调
///  @param failure 失败回调
- (void)getTopMediasAfter:( nonnull NSString *)skipCount userId:( nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取最新"promote"视频或图片列表
///
///  @param success 成功回调
///  @param failure 失败回调
- (void)getNewPromoteMediasSuccess:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

/// 获取更多"promote"视频或图片
///
///  @param skipCount 获取第skipCount张后面的图片
///  @param userId  userId
///  @param success 成功回调
///  @param failure 失败回调
- (void)getPromoteMediasAfter:( nonnull NSString *)skipCount userId:( nullable NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;


///  踢出用户
///
///  @param eventId eventID
///  @param userIds  userIds
///  @param success 成功回调
///  @param failure 失败回调
- (void)kickUserByEventId:( nonnull NSString *)eventId withUsersId:( nonnull NSArray *)userIds success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  添加禁言用户
///
///  @param channelId channelID
///  @param userId    userid
///  @param minute    时间
///  @param success   成功回调
///  @param failure   失败回调
- (void)addGagUserByChannelId:( nonnull NSString *)channelId userId:( nonnull NSString *)userId minute:(NSInteger)minute success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  移除禁言用户
///
///  @param channelId channelId
///  @param userId    userID
///  @param success   成功回调
///  @param failure   失败回调
- (void)rollbackGagUserByChannelId:( nonnull NSString *)channelId userId:( nonnull NSString *)userId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

///  获取禁言用户列表
///
///  @param channelId channelId
///  @param success   成功回调
///  @param failure   失败回调
- (void)getGagListByChannelId:( nonnull NSString *)channelId success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;


//---------------以下接口需要在UserManager中调用-----------
//修改登录接口  2017-2-21
#pragma mark - 登录接口
- (void) signinOrSignup:( nonnull NSString *)phone code:( nonnull NSString *)code success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) getVerifyCode:( nonnull NSString *)phone type:(CDASignType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) postAvatarOrCoverAvatarPath:( nonnull NSString *)avatarPath success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) patchInfoWithUserId:( nonnull NSString *)uid UserName:( nullable NSString *)name ImagePath:( nonnull NSString *)avatarPath success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) patchInfoWithUserId:( nonnull NSString *)uid nickName:(nullable NSString *)nickName signature:(nonnull NSString *)signature success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) postAvatarWithImagePath:( nonnull NSString *)avatarPath success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) postBindWithUserId:( nonnull NSString *)uid authType:(CDAThirdType)type authInfo:( nonnull NSDictionary *)authInfo success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) getUnBindAuthType:(CDAThirdType)type success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void)getUserInfoWithUserID:( nonnull NSString *)uid Success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) CamdoraSignIn: ( nonnull NSDictionary *)userInfo success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure Platform:(CDAThirdType)platform;

- (void) signIn:( nonnull NSString *)phone code:( nonnull NSString *)code success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
- (void) signUp:( nonnull NSString *)phone code:( nonnull NSString *)code nickname:( nonnull NSString *)nickname success:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
- (void) signOut: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;
- (void) getCurrentUserInfo: ( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void) anonSignIn:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

- (void)getLaunchAdDataWithSuccess:( nonnull APISuccessBlock)success failure:( nonnull APIFailureBlock)failure;

@end
