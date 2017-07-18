//
//  CLModel.h
//  CLModel <https://github.com/ibireme/CLModel>
//
//  Created by ibireme on 15/5/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#if __has_include(<CLModel/CLModel.h>)
FOUNDATION_EXPORT double CLModelVersionNumber;
FOUNDATION_EXPORT const unsigned char CLModelVersionString[];
#import <CLModel/NSObject+CLModel.h>
#import <CLModel/CLClassInfo.h>
#else
#import "NSObject+CLModel.h"
#import "CLClassInfo.h"
#endif
