//
//  DeviceModel.h
//  native
//
//  Created by Edwin Cen on 9/9/16.
//  Copyright © 2016 camdora. All rights reserved.
//

#import "CLModel.h"
#import "CDABaseModel.h"

@interface CDADeviceModel : NSObject

@property NSString *serialNumber;
@property float temperature;
@property NSString *deviceType;
@property float batteryPercentage;
@property int usbMode;
@property float batteryRemaining;
@property BOOL isSDCardInserted;
@property BOOL isSDCardMounted;
@property int sdcardUsed;
@property int sdcardTotal;
@property NSString *firmwareReleaseName;
@property NSString *firmwareReleaseVersion;
@property NSString *firmwareReleaseDate;
@property NSString *firmwareBuildTime;
@property NSString *firmwareBuildId;
@property BOOL isRecording;
@property int recordDuration;
@property int volume;
@property BOOL isMuted;

@end

@interface CDADeviceFirmware : CDABaseModel

@property NSString *version;
@property NSString *changelog;
@property int size;
@property NSString *filename;
@property NSString *url;

@end

