//
//  CDARechargeDetailModel.h
//  Camdora
//
//  Created by tusm on 2017/5/22.
//  Copyright © 2017年 camdora. All rights reserved.
//

#import "CDABaseModel.h"

@interface CDARechargeDetailModel : CDABaseModel

///  订单编号
@property (nonatomic,copy)NSString *OrderSn;

///  订单总金额
@property (nonatomic,copy)NSString *totalFee;

///  订单实际支付金额
@property (nonatomic,assign)double amount;

///  订单支付时间
@property (nonatomic,strong)NSDate *payTime;

///  订单类型[recharge, consume]
@property (nonatomic,copy)NSString *orderType;

///  预支付
@property (nonatomic,assign)BOOL isPrePay;

@end
