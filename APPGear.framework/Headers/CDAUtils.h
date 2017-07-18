//
//  CDAUtils.h
//  native
//
//  Created by Edwin Cen on 9/18/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CDAReachability.h"


@interface CDAUtils : NSObject

+ (NSString *)timeFormatted:(int)totalSeconds format: (NSString *)format;
+ (CGSize) labelSizeWithString:(NSString *)str size:(CGSize)size attributes:(NSDictionary *)attributes;
+ (UIImage *)imageWithImage:(UIImage *)image convertToSize:(CGSize)size;
+ (UIImage *)imageWithImage:(UIImage *)image croptToRect:(CGRect)rect;
+ (UIImage *)imageWithImage:(UIImage *)image convertToSize:(CGSize)size andCroptToRect:(CGRect)rect;
+ (UIImage *)generateThumbnailWith:(UIImage *)image;
+ (UIImage *)blurredImageWithImage:(UIImage *)sourceImage;

/*
 [CDAUtils connectNetWork:@{
 @"message":@"建议连接蜂窝网络",
 @"sureTitle":@"连接蜂窝网络",
 @"type":@"General&path=ACCESSIBILITY"
 } VC:self];
 */
+(void)connectNetWork:(NSDictionary *)dict VC:(UIViewController *)vc;

///  设置statusBar隐藏与显示
///
///  @param hidden BOOL
+ (void)setStatusBarHidden:(BOOL)hidden;

+ (NSString *) formatByteToUnit:(long long)bytes;


///  确认网络状态
///
///  @param vc 当前控制器
+ (void)checkNetworkStatusWithVC:(UIViewController *)vc finish:(void(^)(NetworkStatus))finish cancel:(void (^)(BOOL isCancel))isCancel;

///  获取连接WIFI IP
///
///  @return ip
+ (NSString *)getIPAddress;


@end
