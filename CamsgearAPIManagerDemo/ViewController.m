//
//  ViewController.m
//  APIManagerDemo
//
//  Created by tusm on 2017/4/25.
//  Copyright © 2017年 cleven. All rights reserved.
//

#import "ViewController.h"
#import <APPGear/APPGear.h>
#import "SVProgressHUD.h"

@interface ViewController ()
///  手机号
@property (weak, nonatomic) IBOutlet UITextField *phoneNumber;
///  验证码
@property (weak, nonatomic) IBOutlet UITextField *verificationCode;

///  直播状态
@property (weak, nonatomic) IBOutlet UILabel *liveStatus;

///  直播数据
@property (nonatomic,strong)NSMutableArray *events;

///  视频数据
@property (nonatomic,strong)NSMutableArray *videos;

@end

@implementation ViewController

-(NSMutableArray *)events
{
    if (!_events) {
        _events = [NSMutableArray array];
    }
    return _events;
}

-(NSMutableArray *)videos
{
    if (!_videos) {
        _videos = [NSMutableArray array];
    }
    return _videos;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    // Do any additional setup after loading the view, typically from a nib.
}

#pragma mark - 获取验证码
- (IBAction)clickGetCode:(id)sender {
    
    [[CDAUserManager sharedManager]getVerifyCodeWithPhone:self.phoneNumber.text type:CDASignType_signin_signup success:^(id result) {
        
        [SVProgressHUD showSuccessWithStatus:@"获取验证码成功,请注意查看短信"];
        
    } failure:^(NSError *error) {
        NSLog(@"%@",error);
        [SVProgressHUD showErrorWithStatus:@"获取验证失败,请确认手机号是否输入正确"];
    }];
    
}
#pragma mark - 登录
- (IBAction)clickTheLoginButton:(id)sender {
    
    [[CDAUserManager sharedManager]signinOrSignup:self.phoneNumber.text verificationCode:self.verificationCode.text success:^(id result) {
      
        [SVProgressHUD showSuccessWithStatus:@"登录成功"];
        
        
    } failure:^(NSError *error) {
        
        [SVProgressHUD showErrorWithStatus:@"登录失败,请确认手机号和验证码是否输入正确"];
        
    }];
    
}
#pragma mark - 退出登录
- (IBAction)clickOnTheExitTheLogInButton:(id)sender {
    
    [[CDAUserManager sharedManager]signOut:^(id result) {
      
        [SVProgressHUD showSuccessWithStatus:@"注销成功"];
    } failure:^(NSError *error) {
        
        [SVProgressHUD showErrorWithStatus:@"注销失败"];
    }];
    
}
#pragma mark - 获取账户余额
- (IBAction)GetAccountBalance:(id)sender {
    
    [[CDAAPIManager sharedManager]getWalletSuccess:^(id result) {
      
        [SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"%@",result]];
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"获取失败"];
    }];
    
}

#pragma mark - 获取观看直播权限
- (IBAction)GetPermissionToWatchLive:(id)sender {
    if (self.events.count <= 0) {
        
        [SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];
        
        return;
    }
    CDAEvent *event = self.events.firstObject;
    [[CDAAPIManager sharedManager]getEventPermission:event.id success:^(id result) {
        BOOL hasPermission = [[result objectForKey:@"hasPermission"] boolValue];//余额不足,为NO
        BOOL isKick = [[result objectForKey:@"isKicked"] boolValue];//默认YES,被踢出为NO
        
        
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"获取失败"];
    }];
    
    
}

#pragma mark - 获取直播数据
- (IBAction)getLiveData:(id)sender {
    
    //block返回的result已经是转过模型的CDAEvent对象,可直接使用
    [[CDAAPIManager sharedManager] getLatestEventsByUserId:nil withLiveType:CDALiveType_Home_Live success:^(NSArray *result) {
        [self.events addObjectsFromArray:result];
        
        [SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"加载了%ld条数据",(unsigned long)result.count]];
        
        
        NSLog(@"--直播数据:%@",result);
        
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"加载失败"];
    }];
    
    /*
    //------下拉加载-----
    CDAEvent *firstEvent = self.events.firstObject;//取event的第一条数据
    //tips: userid区分 获取广场数据,还是个人数据
    [[CDAAPIManager sharedManager]getEventsBefore:firstEvent.id UserId:nil withLiveType:CDALiveType_Home_Live success:^(id result) {
        NSLog(@"--下拉直播数据:%@",result);
    } failure:^(NSError *error) {
        
    }];
    
    //-----上拉加载-----------
    CDAEvent *lastEvent = self.events.lastObject;
     //tips: userid区分 获取广场数据,还是个人数据
    [[CDAAPIManager sharedManager] getEventsAfter:lastEvent.id UserId:nil withLiveType:CDALiveType_Home_Live success:^(id result) {
        NSLog(@"--上拉直播数据:%@",result);
        
    } failure:^(NSError *error) {
        
    }];
    */
    
}

#pragma mark - 获取视频数据
- (IBAction)getVideoData:(id)sender {
    
    //block返回的result已经是转过模型的CDAVideo对象,可直接使用
      [[CDAAPIManager sharedManager] getLatestVideosSuccess:^(NSArray *result) {
        [self.videos addObjectsFromArray:result];
        [SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"加载了%ld条数据",(unsigned long)result.count]];
        NSLog(@"--视频数据:%@",result);
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"加载失败"];
    }];
    
    /*
    //------下拉加载-----------
    CDAVideo *firstVideo = [self.videos firstObject];
    //tips: userid区分 获取广场数据,还是个人数据
    [[CDAAPIManager sharedManager] getVideosBefore:firstVideo.id UserId:nil success:^(id result) {
        NSLog(@"--下拉视频数据:%@",result);
        
    } failure:^(NSError *error) {
        
        
    }];

    //------上拉加载-------
    CDAVideo *lastVideo = self.videos.lastObject;
    //tips: userid区分 获取广场数据,还是个人数据
    [[CDAAPIManager sharedManager]getVideosAfter:lastVideo.id UserId:nil success:^(id result) {
        NSLog(@"--上拉视频数据:%@",result);
    } failure:^(NSError *error) {
        
    }];
    */
    
}
#pragma mark - 获取直播详情-观看直播界面数据
- (IBAction)clickLiveingData:(id)sender {
    
    if (self.events.count <= 0) {
        
        [SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];
        
        return;
    }
    
    CDAEvent *event = self.events.firstObject;
    [[CDAAPIManager sharedManager] getEventAndChannelsByEventId:event.id success:^(id result) {
      
        [SVProgressHUD showSuccessWithStatus:@"获取直播详情数据成功"];
        
        NSLog(@"--直播详情数据:%@",result);
    } failure:^(NSError *error) {
        
        if ([error.userInfo[@"code"] longValue] == 403) {
            
            [SVProgressHUD showErrorWithStatus:@"您没有登录,请登录"];
            
            return;
        }
        
        [SVProgressHUD showErrorWithStatus:@"获取失败"];
    }];
    
}
#pragma mark - 获取房间在线人数和直播状态
- (IBAction)getOnLineAndLiveStatus:(id)sender {
    if (self.events.count <= 0) {
        
        [SVProgressHUD showErrorWithStatus:@"请先获取直播数据"];
        
        return;
    }

    CDAEvent *event = self.events.firstObject;
    CDAChannel *channel = event.channels.lastObject;
    [[CDAAPIManager sharedManager]getUserCountByChannelIdAndLiveStatus:channel.id success:^(id result) {
        [SVProgressHUD showSuccessWithStatus:@"获取成功"];
         [self.liveStatus setText:[NSString stringWithFormat:@":在线人数%@   直播状态:%@", [result objectForKey:@"popularity"] == nil ? @"0" : [result objectForKey:@"popularity"],[result objectForKey:@"isLive"]]];
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"获取失败"];
    }];
    
}



#pragma mark - 发布视频
- (IBAction)clickPostVideo:(id)sender {

    CDALocalMedia *localMedia = [[CDALocalMedia alloc] init];
    localMedia.title = @"test";
    localMedia.name = @"test";
    NSString *mp4Path = [[NSBundle mainBundle]pathForResource:@"test" ofType:@"mp4"];
    NSString *imagePath = [[NSBundle mainBundle]pathForResource:@"226.jpg" ofType:nil];
    localMedia.mediaUrl = imagePath;
    localMedia.thumbnailUrl = imagePath;
    localMedia.videoDescription = @"shahjahjkasjkg";
    localMedia.id = [[NSUUID UUID]UUIDString];
    localMedia.createdAt = [NSDate date];
    localMedia.size = 36841966;
    localMedia.duration = 130;
    localMedia.width = [UIScreen mainScreen].bounds.size.width;
    localMedia.height = [UIScreen mainScreen].bounds.size.width;
    localMedia.mediaType = @"Norma";
    
    //如果是需要标定参数的视频,需要按如下要求传
//    localMedia.calibrationData = @"version=v1&type=1&data=0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.,0.0,0.0,0.0,0.0;0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0"; //第二组;
    
    //如果MediaInfo没有 ,需要创建MediaInfo
    CDACamdoraMediaInfo *mediaInfo = [CDACamdoraMediaInfo creatMediaInfoWithPicNum:CDAPicNum_2D width:1080 height:1080 fov:CDAFov_185 order:CDACamdoraMediaInfoOrderLeft2Right orientation:CDAOrientation_90 mount:CDACamdoraMediaInfoMountDesktop projection:CDACamdoraMediaInfoProjectionFisheye needStitch:YES fps:30];
    localMedia.camdoraMediaInfo = mediaInfo;
    
    
    [[CDAAPIManager sharedManager]releaseMediaByLocalMedia:localMedia MediaType:CDABeLongToMe_image image:[UIImage imageNamed:@"cover"] success:^(id result) {
        
        [SVProgressHUD showSuccessWithStatus:@"发布成功"];
    } uploadProgress:^(int64_t bytesSent, int64_t totalByteSent, int64_t totalBytesExpectedToSend) {
        float percent = 0.8 + 0.2 * totalByteSent / totalBytesExpectedToSend;
        
        [SVProgressHUD showProgress:percent];
        
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:@"发布失败"];
        
    }];

    
}


- (void)showStatusWithTitle:(NSString *)title Message:(NSString *)message
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        
    }];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    [alert addAction:ok];
    [alert addAction:cancel];
    
    [self presentViewController:alert animated:YES completion:nil];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self.phoneNumber resignFirstResponder];
    [self.verificationCode resignFirstResponder];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
