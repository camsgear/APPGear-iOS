//
//  CDALocalDevice.h
//  native
//
//  Created by Edwin Cen on 28/09/2016.
//  Copyright © 2016 camdora. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CDALocalDevice : NSObject

@property NSString *deviceType;
@property NSString *deviceTypeString;
@property NSString *serialNumber;
@property NSString *firmwareName;
@property NSString *firmwareVersion;
@property NSDate *lastConnectedDate;


@end
