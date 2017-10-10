//
//  CDALocalVideo.h
//  native
//
//  Created by Edwin Cen on 9/18/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import "CDAVideoModelProtocal.h"
#import "CDACamdoraMediaInfo.h"

@interface CDALocalMedia : NSObject<CDAVideoModelProtocal>
///  图片/视频的完整路径
@property (nonatomic,copy) NSString *mediaUrl;
///  图片地址
@property (nonatomic,copy) NSString *thumbnailUrl;
@property (nonatomic, copy)NSString *name;
@property (nonatomic, copy)NSString *id;
@property (nonatomic, strong)NSDate *createdAt;
@property (nonatomic, assign)long long size;
@property (nonatomic, assign)int duration;
@property (nonatomic, copy)NSString *mediaType;//列:Norma,Panorama,StereoHemisphere,StereoFlat,StereoPanorama
@property (nonatomic, assign)int width;
@property (nonatomic, assign)int height;
@property (nonatomic, assign)BOOL isDrafted;
@property (nonatomic, copy)NSString *title;
@property (nonatomic, copy)NSString *videoDescription;
///  区分图片和视频 YES ==图片  NO == 视频
@property (nonatomic, assign)BOOL isPicture;
// Camdora Media Info
@property (nonatomic, assign)int camdoraMediaInfoCount;
@property (nonatomic, assign)int camdoraMediaInfoHeight;
@property (nonatomic, assign)int camdoraMediaInfoWidth;
@property (nonatomic, assign)int camdoraMediaInfoFov;
@property (nonatomic, assign)int camdoraMediaInfoOrder;
@property (nonatomic, assign)int camdoraMediaInfoOrientation;
@property (nonatomic, assign)int camdoraMediaInfoMount;
@property (nonatomic, assign)int camdoraMediaInfoProjection;
@property (nonatomic, assign)BOOL camdoraMediaInfoNeedStitch;
@property (nonatomic, assign)int filterID;

@property (nonatomic, copy)NSString *calibrationData;

- (void) setCamdoraMediaInfo: (CDACamdoraMediaInfo *) camdoraMediaInfo;
///  Camdora 私有Media Info
@property (readonly) CDACamdoraMediaInfo *camdoraMediaInfo;
- (BOOL) isVideo;

@end
