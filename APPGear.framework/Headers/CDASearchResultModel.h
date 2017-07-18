//
//  CDASearchResultModel.h
//  Camdora
//
//  Created by wuping on 2017/6/7.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDAVideo.h"
#import "CDAUser.h"
#import "CDAEvent.h"
#import "CDAImage.h"

@interface CDASearchResultModel : NSObject

@property  NSArray *videos;

@property  NSArray *users;

@property  NSArray *events;

@property  NSArray *images;

@end
