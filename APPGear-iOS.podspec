Pod::Spec.new do |s|
  s.name         = "APPGear-iOS"
  s.version      = "1.0.2"
  s.license  = { :type => 'MIT' }
  s.summary      = "直播API,视频API,登录API,创建直播API,发布视频API"
  s.description      = <<-DESC
                       An optional longer description of APPGear

                       * Markdown format.
                       * Don't worry about the indent, we strip it!
                       DESC
  s.homepage     = "https://github.com/camsgear/APPGear-iOS"
  s.social_media_url   = "https://github.com/camsgear/APPGear-iOS.git"
  s.license= { :type => "MIT", :file => "LICENSE" }
  s.author       = { "Camsgear" => "yongqiang.zhao@camdora.me" }
  s.source       = { :git => "https://github.com/camsgear/APPGear-iOS.git", :tag => s.version }
  s.source_files = "APPGear.framework"
  s.ios.deployment_target = '8.0'
  #s.resources = 'SVProgressHUD/SVProgressHUD.bundle'
  s.vendored_framework = 'APPGear.framework'
  s.frameworks   = "UIKit","APPGear"
  s.requires_arc = true

end