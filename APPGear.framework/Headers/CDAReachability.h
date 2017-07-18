//
//  CDA Reachability.h
//  native
//
//  Created by Edwin Cen on 9/10/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLNetworking.h"
#import "CDAStringDef.h"

typedef void (^wifiReachabilityChangedBlock)(BOOL isConnectDeviceWifi);
typedef enum : NSInteger {
    NotReachable = 0,
    ReachableViaWiFi,
    ReachableViaWWAN
} NetworkStatus;

@interface CDAReachabilityManager : NSObject

@property (nonatomic, assign) BOOL wifiReachability;

+ (instancetype)sharedManager;

- (void) setReachabilityStatusChangedBlock: (wifiReachabilityChangedBlock)block;
- (void) setConnectWifiBlock: (wifiReachabilityChangedBlock)block;
- (NetworkStatus)currentReachabilityStatus;
- (NSInteger)checkNetworkStatus;
- (void) resumeNetworkDetector;
- (void) suspendNetworkDetector;
- (NSString *) getCurrentNetworkSSID;

@end
