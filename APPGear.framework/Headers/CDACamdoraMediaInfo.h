//
//  CDACamdoraMediaInfo.h
//  Camdora
//
//  Created by Edwin Cen on 28/02/2017.
//  Copyright © 2017 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLModel.h"
#import "CDAStringDef.h"

typedef enum CDACamdoraMediaInfoOrder{
    CDACamdoraMediaInfoOrderLeft2Right = 0,
    CDACamdoraMediaInfoOrderRight2Left = 1,
    CDACamdoraMediaInfoOrderTop2Bottom = 2,
    CDACamdoraMediaInfoOrderBottom2Top = 3
} CDACamdoraMediaInfoOrder;

typedef enum CDACamdoraMediaInfoMount {
    CDACamdoraMediaInfoMountDesktop = 0,
    CDACamdoraMediaInfoMountWall = 1,
    CDACamdoraMediaInfoMountCeiling = 2
}CDACamdoraMediaInfoMount;

typedef enum CDACamdoraMediaInfoProjection {
    CDACamdoraMediaInfoProjectionFisheye = 0,
    CDACamdoraMediaInfoProjectionEquirectangular = 1,
    CDACamdoraMediaInfoProjectionNormal = 2,
    CDACamdoraMediaInfoProjectionWideAngle = 3
} CDACamdoraMediaInfoProjection;

@interface CDACamdoraMediaInfo : NSObject

@property int picNum;
@property int height;
@property int width;
@property int fov;
@property CDACamdoraMediaInfoOrder order;
@property int orientation;
@property CDACamdoraMediaInfoMount mount;
@property CDACamdoraMediaInfoProjection projection;
@property BOOL needStitch;
@property int fps;

//如果没有MediaInfo 需要使用这个方法创建MediaInfo,发布视频需要这些参数
+ (instancetype) creatMediaInfoWithPicNum:(CDAPicNum)picNum width:(int)width height:(int)height fov:(CDAFov)fov order:(CDACamdoraMediaInfoOrder)order orientation:(CDAOrientation)orientation mount:(CDACamdoraMediaInfoMount)mount projection:(CDACamdoraMediaInfoProjection)projection needStitch:(BOOL)needStitch fps:(int)fps;

//如果设备返回这些参数,可直接使用此方法初始化
+ (instancetype) camdoraMediaInfoWithString: (NSString *)mediaInfoString;

//全景
- (BOOL) isPanorama;
//3D需要拼接参数,暂时没用到
- (BOOL) isStereo;
//运动模式
- (BOOL) isSportWideAngle;
//3D
- (BOOL) isStereoNormal;

- (BOOL) isStereo4b3;

- (BOOL) isNormal;


- (NSString *) mediaTypeName;
- (NSString *) mediaModeString;

@end
