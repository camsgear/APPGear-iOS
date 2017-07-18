//
//  CDALaunchAdModel.h
//  Camdora
//
//  Created by wuping on 07/07/2017.
//  Copyright © 2017 camdora. All rights reserved.
//

#import "CDABaseModel.h"

@interface CDALaunchAdModel : CDABaseModel

@property (nonatomic, copy) NSString *splash;

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *linkUrl;

@property (nonatomic, assign) NSInteger skipTime;

@property (nonatomic, assign) BOOL linkToken;

@end
