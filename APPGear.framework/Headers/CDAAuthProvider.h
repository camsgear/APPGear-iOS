//
//  CDAAuthProvider.h
//  Camdora
//
//  Created by user on 24/2/17.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import "CDABaseModel.h"

@interface CDAAuthProvider : CDABaseModel
@property (nonatomic, copy) NSString *provider;
@property (nonatomic, copy) NSString *nickname;

@end
