//
//  CDAProductModel.h
//  Camdora
//
//  Created by tusm on 2017/5/22.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import "CDABaseModel.h"

@interface CDAProductModel : CDABaseModel

///  商品id
@property (nonatomic,copy)NSString *productId;

///  商品名
@property (nonatomic,copy)NSString *productName;

///  商品价格
@property (nonatomic,assign)NSInteger price;

///  商品描述
@property (nonatomic,copy)NSString *product_description;
@end
