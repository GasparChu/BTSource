//
//  BaiduRtcRoomApi.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/12/5.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduRtcRoomApi_h
#define BaiduRtcRoomApi_h

#import "BaiduRtcRoomApiDefines.h"
#import "BaiduRtcRoomApiVideoExternalCapture.h"
#import "BaiduRtcRoomApiAudioRecord.h"
#import "BaiduRtcRoomApiAudioSession.h"
#import "BaiduRtcRoomApiVideoExternalRender.h"
#import "BaiduRtcRoomApiAudioExternalDevice.h"
#import "RTCLocalVideoView.h"
#import "RTCRemoteVideoView.h"
#import "RTCSettingsModel.h"

/**
 流信息结构
 */
@interface RtcStreamInfo : NSObject
/**
 userId, streaming 的归属者
 */
@property (nonatomic, assign) NSInteger userId;

/**
 streamState, 表述流的状态，到达 or 移除
 */
@property (nonatomic, assign) RtcStreamingStates streamState;

/**
 媒体流ID，表时属于某一用户的流
 */
@property (nonatomic, copy) NSString *streamId;

/**
 媒体流, attribute属性
 */
@property (nonatomic, copy) NSString *attribute;

/**
 具体的video流将渲染到remoteView
 */
@property (nonatomic, strong) RTCRemoteVideoView *remoteView;
@end

@protocol BaiduRtcRoomDelegate;

@interface BaiduRtcRoomApi : NSObject
/**
 BaiduRtcRoom SDK 版本号
 
 @return 版本号
 @discussion 开发者使用本 API 获取 SDK 版本号
 */
+ (NSString *)version;


/**
 是否启用测试环境
 
 @param isUseTestEnv 是否启用测试环境，true 启用，false 不启用。默认为 false
 @discussion 建议在初始化 SDK 前调用。建议开发者在开发阶段设置为测试环境，使用由百度提供的测试环境。上线前需切换为正式环境运营
 */
+ (void)setUseTestEnv:(BOOL)isUseTestEnv;


/**
 是否打开调试信息
 
 @param bOnVerbose 是否打开调试信息，true 打开，false 不打开。默认为 false
 @discussion 建议在初始化 SDK 前调用。建议在调试阶段打开此开关，方便调试
 */
+ (void)setVerbose:(BOOL)bOnVerbose;


/**
 上报日志
 
 @discussion 上传日志到后台便于分析问题
 */
+ (void)upLoadLog;


/**
  共享日志

  @discussion 把log通过微信等工具共享给技术开发，便于分析解决问题
*/
+ (void)shareLog;


/**
 设置AppID,Token

 @param appId 百度派发的数字ID， 开发者的唯一标识
 @param tokenStr RTC server端鉴权使用的字符串
 @discussion 动态设置appId 和 tokenStr，在初始化sdk前后都可以调用
*/
+ (void)setBaiduRtcAppID:(NSString *)appId andToken:(NSString *)tokenStr;


/**
 初始化 SDK
 
 @param appId  百度 派发的数字 ID, 开发者的唯一标识
 @param tokenStr  app server 派发的token字符串, 用来校验对应signal 通信的合法性
 @return SDK 实例，nil 表示初始化失败
 @discussion 初始化 SDK 时调用。初始化 SDK 失败可能导致 SDK 功能异常
 */
- (instancetype)initSDKWithAppID:(NSString *)appId
                        tokenStr:(NSString *)tokenStr
                        delegate:(id<BaiduRtcRoomDelegate>)delegate;



#pragma mark -- app delegate setting
/**
 设置 rtc room 代理对象
 
 @param baiduRtcRoomDelegate 遵循 BaiduRtcRoomDelegate 协议的代理对象
 @return true 成功，false 失败
 @discussion 使用 rtc room 功能，初始化相关视图控制器时需要设置代理对象。未设置代理对象，或对象设置错误，可能导致无法正常收到相关回调
 */
- (bool)setBaiduRtcRoomDelegate:(id<BaiduRtcRoomDelegate>)baiduRtcRoomDelegate;



#pragma mark -- av parameter setting
/**
 设置音视频相关的参数

 @param paramSettings 该参数封装了音视频的一些参数,如video分辨率，fps, bitrate，音频采样率等
 @param paramType 参数类型，可指定设置某一项，还是所有参数都设置
 @discussion 该函数在loginRoom 前调用，主要用于设置音视频采集，编解码相关的参数
 */
- (void)setParamSettings:(RtcParameterSettings *)paramSettings paramType:(RtcParamSettingType)paramType;

/**
 获取音视频相关的参数
qq
 @discussion 获取当前音视频采集，编解码等相关的参数
 */
- (RtcParameterSettings *)getParamSettings;


/**
 RTC引擎统计信息
 
 @param bOnStatistics 是否打开rtc引擎统计信息， bOnStatistics = YES,打开开关，bOnStatistics = NO, 关闭引擎统计信息
 @discussion 引擎统计信息开关,当打开开关时 onEngineStatisticsInfo 函数会每隔2秒返回引擎的统计信息，并且可通过queryEngineStatisticsInfo主动函数查询到引擎统计信息
 */
- (void)setEngineStateStatistics:(BOOL)bOnStatistics;

/**
 RTC质量监控数据上报
 
 @param isEnable 是否打开rtc质量监控数据上报   isEnable = YES, 开启上报，isEnable = NO, 关闭上报
 @param qualityMonitorEnv   线上环境："online"   沙盒："qa"，用于测试
 @discussion 预置接口 监控信息上报开关   当打开开关时，上报帧率、码率、分辨率、丢包率等监控信息到服务端，console可查
 */
- (void)enableStatsToServer:(BOOL)isEnable qualityMonitorEnv:(NSString *)qualityMonitorEnv;

#pragma mark -- 登录／退出房间
/**
 登录房间
 
 @param roomName 房间名，长度不可超过 255 byte
 @param userId 用户id,每个房间的用户ID必须唯一
 @param displayName 用户昵称
 @return true 成功，false 失败
 @discussion 登录房间成功，在同一个房间的人能进行相互音视频聊天，如果失败，会通过onErrorInfoUpdate call back 返回错误信息
 */
- (BOOL)loginRtcRoomWithRoomName:(NSString *)roomName
                          userID:(NSInteger)userId
                     displayName:(NSString *)displayName;

/**
 登录房间
 
 @param roomName 房间名，长度不可超过 255 byte
 @param userId 用户id,每个房间的用户ID必须唯一
 @param displayName 用户昵称
 @param isCompulsive 是否强制登录
 @return true 成功，false 失败
 @discussion 登录房间成功，在同一个房间的人能进行相互音视频聊天，如果失败，会通过onErrorInfoUpdate call back 返回错误信息。建议在断网重连或者初次登录失败时调用
 */
- (BOOL)loginRtcRoomWithRoomName:(NSString *)roomName
                          userID:(NSInteger)userId
                     displayName:(NSString *)displayName
                    isCompulsive:(BOOL)isCompulsive;

/**
 退出房间
 
 @return true 成功，false 失败
 @discussion 执行logoutRtcRoom后，会停止音视频采集，断开与房间服务器的连接，取消音视频的传输，销毁音视频传输通道以及释放其他资源。
 */
- (bool)logoutRtcRoom;



#pragma mark -- 发布／订阅流接口
/*
 * 发布流
 *
 * @discuss 流发布在roomId指定的房间，在同一房间joined 的用户可以相互订阅流，默认在发布流的同时，
 *         listening/subscriber 在该房间其他用户的流；
 *
 **/
- (void)publishStreaming;


/*
 * 停止发布流
 *
 * @discuss  stop 通过 publishStreaming 发布的流
 *
 **/
- (void)stopPublishStreaming;


/*
 * 订阅流
 *
 * @param streamingIds, 用户要订阅的其他用户的流id列表(即其他用户id列表)
 *
 * @discuss 用于订阅同一房间的其他用户的流
 *
 **/
- (void)subsribeStreaming:(NSArray<NSNumber *> *)streamingIds;


/*
 * 停止订阅流
 *
 * @param streamingIds, 用户要停止订阅的流id列表(即其他用户id列表)
 *
 * @discuss  该接口停止已经已经订阅的流
 *
 **/
- (void)stopSubscribeStreaming:(NSArray<NSNumber *> *)streamingIds;



#pragma mark -- custom commands
/**
 踢出某人
 
 @param userId 在房间中的用户的 用户ID
 @discussion 房管／主播／会议主持 把某人踢出聊天室
 */
- (void)kickOffUserWithId:(NSInteger)userId; //add roomID


/**
 禁言某人
 
 @param userId 在房间中的用户的 用户ID
 @param isDisable 是否禁言某人
 @discussion  房管/主播／会议主持 禁止某人发言
 */
- (void)shutUpUserWithId:(NSInteger)userId isDisable:(BOOL)isDisable;

/**
  解散房间
 
  @discussion 解散房间，房间管理员有权利解散整个房间，解散后，房间中的每个人都退出房间
 */
- (void)disbandRoom;


#pragma mark -- video devices setting
/**
 设置外部采集模块
 
 @param factory 工厂对象，遵循 BaiduVideoCaptureFactory 协议的对象
 @discussion 必须在登录房间前调用，并且不能置空
 */
- (void)setVideoCaptureFactory:(id<BaiduVideoCaptureFactory>)factory;


/**
 设置外部渲染回调对象
  
 @param renderDelegate 遵循 BaiduRtcApiRenderDelegate 协议的代理对象
 @discussion 使用外部渲染功能，需要设置代理对象。未设置代理对象，或对象设置错误，可能导致无法正常收到相关回调
 */
- (void)setRenderDelegate:(id<BaiduRtcApiRenderDelegate>)renderDelegate;


/**
 本地预览
 
 @discussion 打开camera，开始预览
 */
- (void)startPreview;


/**
 停止预览
 
 @discussion 关闭camera, 停止本地预览
 */
- (void)stopPreview;



/**
 切换摄像头
 
 @discussion 前后摄像头切换
 */
- (void)switchCamera;


/**
 关闭/打开摄像头
 
 @discussion 在关闭摄像头后，本地无法预览，且不传输本地视频数据给对方
 */
- (void)muteCamera;


/**
 关闭/打开摄像头
 
 @param isMute true:关闭 false:打开
 @discussion 设置是否开启摄像头，支持打开/关闭,默认打开
 */
-(void)muteCamera:(BOOL)isMute;

/**
 设置前后摄像头
 
 @param front true:前置 false:后置
 @discussion 设置前后摄像头
 */
-(void)setCameraFace:(BOOL)front;

/**
 摄像头对焦
 
 @param point 对焦点坐标
 @param size camera预览view尺寸
 @discussion 摄像头对焦功能，支持手动和自动对焦
 */
- (void)cameraFocusWithPoint:(CGPoint)point andPlaneSize:(CGSize)size;



#pragma mark -- audio devices setting
/**
 设置音频录制回调代理对象
 
 @param audioRecordDelegate 遵循 BaiduRtcApiAudioRecordDelegate 协议的代理对象
 @discussion 开启音频录制功能，需要设置代理对象。未设置代理对象，或对象设置错误，可能导致无法正常收到相关回调
 */
- (void)setAudioRecordDelegate:(id<BaiduRtcApiAudioRecordDelegate>)audioRecordDelegate;

/**
 设置音频会话代理对象

 @param audioSessionDelegate 遵循 BaiduRtcRoomApiAudioSessionDelegate 协议的代理对象
 @discussion 接收音频设备状态变化的通知，详情请看BaiduRtcRoomApiAuidoSession.h
 */
- (void)setAudioSessionDelegate:(id<BaiduRtcRoomApiAudioSessionDelegate>)audioSessionDelegate;

#pragma mark -- audio external device

- (void)setAudioExternalDeviceDelegate:(id<BaiduRtcRoomApiAudioExternalDeviceDelegate>)audioExternalDelegate;

/**
 关闭麦克风
 
 @discussion 关闭麦克风，停止音频的采集
 */
- (void)muteMicphone;


/**
 关闭扬声器
 
 @discussion 关闭扬声器，停止音频播放
 */
- (void)muteSpeaker:(BOOL) isMute;

/**
 打开/关闭麦克风
 
 @param isMute true:关闭 false:开启 默认开启
 @discussion 关闭麦克风，停止音频的采集
 */
-(void)muteMicphone:(BOOL)isMute;

/**
 开关扬声器
 
 @discussion 听筒与扬声器切换(免提功能)
 */
- (void)switchLoundSpeaker;


/**
 预置听筒/扬声器
 
 @param isPresetLoudSpeaker   true:扬声器   false:听筒    默认听筒
 @discussion 在initSDKWithAppID之后，loginRoom之前调用，预置听筒/扬声器播放语音
 */
-(void)presetLoudSpeaker:(BOOL)isPresetLoudSpeaker;

/**
 语音激励接口
 
 @return NSDictionary* 用户音量大小
 @discussion 获取语音激励
 */
-(NSArray*)getRemoteAudioLevels;

/**
 设置音频 session mode
 
 @param audioSessionMode 音频mode
 @discussion 设置音频 session mode
 */
- (void)setAudioSessionMode:(AVAudioSessionMode)audioSessionMode;

/**
 是否开启音频自动增益
 
 @param enable true:开启 false:关闭  默认false
 @discussion  是否开启音频自动增益
 */
- (void)enableAgc:(BOOL)enable;

/**
 是否开启音频噪声抑制
 
 @param enable true:开启 false:关闭  默认false
 @discussion   是否开启音频噪声抑制
 */
- (void)enableAns:(BOOL)enable;

/**
 设置声音输出方式
 
 @param mode 可选值：speaker（扬声器）或 ear（听筒)
 @discussion  设置声音输出方式
 */
- (void)setSoundMode:(RtcSoundMode)mode;
/**
 指定远端画面暂停/恢复播放
 
 @param stats true播放  false暂停
 @param userId 用户userID
 @discussion  控制指定远端用户画面暂停/恢复播放
 */
-(void)setRemoteAudioPlayState:(BOOL)stats userId:(NSInteger)userId;

#pragma mark -- video display
/**
 设置本地显示view
 
 @param localVideoView 本地显示view,用于显示camera采集的视频数据
 @discussion 在loginRoom之前调用，loginRoom之后，本地视频数据会显示到 localVideoView,
             localVideoView的位置大小要与采集的视频大小成比例。
 */
- (void)setLocalDisplay:(RTCLocalVideoView *)localVideoView;



/**
 设置远端显示view
 
 @param remoteVideoView 远端画面显示view, 用于显示远端用户传输过来的视频数据
 @discussion 在loginRoom之前调用，loginRoom之后，远端视频数据会显示到 remoteVideoView，
             remoteVideoView的大小要与采集的视频大小成比例
 */
- (void)setRemoteDisplay:(RTCRemoteVideoView *)remoteVideoView;

/**
 设置指定用户的远端显示view
 
 @param remoteVideoView 远端画面显示view, 用于显示远端用户传输过来的视频数据
 @param userId 用户userID
 @discussion 在远端用户流到达后调用，指定用户视频数据会显示到 remoteVideoView，
 remoteVideoView 的大小要与采集的视频大小成比例
 */
- (void)setRemoteDisplay:(RTCRemoteVideoView *)remoteVideoView userId:(NSInteger)userId;

/**
 更新指定用户的远端显示view
 
 @param remoteVideoView 远端画面显示view, 用于显示远端用户传输过来的视频数据
 @param userId 用户userID
 @discussion 更新指定用户视频数据显示view
 remoteVideoView 的大小要与采集的视频大小成比例
 */
- (void)updateDisplay:(RTCRemoteVideoView *)remoteVideoView userId:(NSInteger)userId;

/**
 设置远端显示viewGroup
 @deprecated 多人模式下使用setRemoteDisplay: userId: 设置远端用户view
 @param remoteVideoViewGroup 远端画面显示view列表, 用于显示远端用户传输过来的视频数据
 @discussion 在loginRoom之前调用，loginRoom之后，远端视频数据会显示到 remoteVideoViewGroup列表中，
             remoteVideoView的大小要与采集的视频大小成比例
 */
- (void)setRemoteDisplayGroup:(NSArray<RTCRemoteVideoView *> *)remoteVideoViewGroup __deprecated;

/**
 指定远端画面暂停/恢复播放
 
 @param stats true播放 false暂停
 @param userId 用户userID
 @discussion  控制指定远端用户画面暂停/恢复播放
 */
-(void)setRemoteVideoPlayState:(BOOL)stats userId:(NSInteger)userId;

#pragma mark -- beauty interface
/**
 设置美白度
 
 @param factor 在美颜中的美白因子
 @discussion 美白系数调节
 */
- (void)setWhitenFactor:(float)factor;



/**
 设置红润度
 
 @param factor 在美颜中的红润因子
 @discussion 红润系数调节
 */
- (void)setRedenFactor:(float)factor;



/**
 设置磨皮度
 
 @param factor 在美颜中的磨皮因子
 @discussion 磨皮系数调节
 */
- (void)setBuffingFactor:(float)factor;


/**
 查询房间用户信息
 
 @return NSArray* 用户信息列表
 @discussion 获取房间中所有媒体用户列表
 */
- (NSArray *)queryUserListOfRoom;


/**
 查询房间用户信息
 
 @return NSArray* Message用户信息列表
 @discussion 获取房间中Message用户的列表
 */
- (NSArray *)queryMessageUserListOfRoom;


/**
 查询RTC引擎统计信息
 
 @return NSArray* rtc engine状态统计信息
 @discussion 用于获取rtc engine 的一些运行状态信息，如cpu, video codec, fps等信息
 */
- (NSArray *)queryEngineStatisticsInfo;


#pragma mark -- sending text message in the data channel
/**
 发送文本消息

 @param message 需要发送的文本消息
 @return int, -1 发送失败，0 发送成功
 @discussion 当enable数据通道后，可通过该接口发送文本消息给在同一房间的其他用户
 */
- (int)sendMessage:(NSString *)message;


/**
 发送文本消息
 
 @param message 需要发送的文本消息
 @return int, -1 发送失败，0 发送成功
 @discussion 通过信令信道 该接口发送文本消息给在同一房间的其他用户
 */
- (int)sendMessage2:(NSString *)message;

/**
 发送文本消息
 
 @param message 需要发送的文本消息
 @param userId 接收信息的用户ID
 @return int, -1 发送失败，0 发送成功
 @discussion 通过信令信道 该接口发送文本消息给在同一房间的指定用户
 */
- (int)sendMessage2WithUserId:(NSString *)message
                  userId:(NSNumber *)userId;

/**
 设置用户attribute属性
 
 @param attribute attribute值
 @return int, -1 发送失败，0 发送成功
 @discussion  设置本用户attribute属性
 */
- (int)setUserAttribute:(NSString *)attribute;

/**
 获取用户attribute属性
 
 @param userID 用户UID
 @return int, -1 发送失败，0 发送成功
 @discussion  获取指定用户attribute属性，属性值由onTextMessageAttribute回调返回
 */
- (int)getUserAttribute:(NSNumber *)userID;


#pragma mark -- configure live server
/**
 配置server端推流参数

 @param url rtmp推流地址
 @param isMix 是否做混流处理
 @param isRecording 是否录制
 @param mixTmplt 混流模版
 @param mode 转推模式，有两种： 聊天室模式， 主播转推模式
 @param avParam 转推音视频参数
 @discussion 该接口用于配置server推流的参数，聊天室模式：在同一个rtc房间的所有参与者在混流后，直接转推到一个指定的直播房间；
             主播转推模式：主播推向不同的直播房间。
 */
- (void)configLiveServerWithUrl:(NSString *)url
                          isMix:(BOOL)isMix
                        isRecording:(BOOL)isRecording
                    mixTemplate:(NSString *)mixTmplt
                   transferMode:(RtcLiveTransferMode)mode
                        avParam:(RtcLiveAuidoVideoParameters*)avParam;

/**
 动态配置server端推流参数
 
 @param url rtmp推流地址
 @param isMix 是否做混流处理
 @param isRecording 是否录制
 @param mixTmplt 混流模版
 @param mode 转推模式，有两种： 聊天室模式， 主播转推模式
 @discussion 该接口用于动态配置server推流的参数。configLiveServerWithUrl在执行loginRtcRoom之前调用。本接口在loginRtcRoom成功后调用。两个接口不要混用
 */
- (void)startLiveServerStreaming:(NSString *)url
                          isMix:(BOOL)isMix
                    isRecording:(BOOL)isRecording
                    mixTemplate:(NSString *)mixTmplt
                    transferMode:(RtcLiveTransferMode)mode;

/**
 停止server转推
 
 @param transferMode 转推模式，有两种： 聊天室模式， 主播转推模式
 @discussion 若需要通话过程中，停止转推，调用该接口
 */
- (void)stopLiveServerStreaming:(RtcLiveTransferMode)transferMode;

/**
 设置本流在混流模版布局中的位置信息
 
 @param idx   混流模版中的位置索引名
 @discussion  设置本流在混流模版布局中的位置信息
 */
- (BOOL)setMixLayoutPositionIndex:(NSString *)idx;

#pragma mark -- setting signal server url
/**
 设置信令server url
 @param serverUrl 信令server url
 @discussion 在loginRoom之前调用，用于配置信令server
 */
- (void)setSignalServerWithUrl:(NSString *)serverUrl port:(NSString *)port;

@end


#pragma mark -- 提供app的callback
@protocol BaiduRtcRoomDelegate <NSObject>
/**
 房间用户状态信息通知
 
 @param roomEvents 房间事件信息，具体信息参考 BaiduRtcRoomApiDefines.h
 @discussion 房间中用户加入或离开时，通知房间中其他用户，其他用户可接收到房间中他人离开的信息。
 */
- (void)onRoomEventUpdate:(RtcRoomEvents *)roomEvents;



/**
 与server连接状态通知
 
 @param type 连接类型，有数据／媒体／信令三种类型
 @param connecStats 连接状态码，具体可分别看RtcSignalChannelStates／RtcMediaChannelStates／RtcDataChannelStates
 @discussion 与server端的连接状态信息更新，包括信令/媒体／数据通道，如开始建连，连接成功，连接失败等
 */
- (void)onPeerConnectStateUpdateWithType:(RtcPeerConnectionType)type stats:(int)connecStats;



/**
 媒体流信息通知
 
 @param rtcStreamInfo 具体流相关的信息
 @discussion 当有远端或本地流信息到来时，通知app层做后续处理
 */
- (void)onStreamInfoUpdate:(RtcStreamInfo *)rtcStreamInfo;



/**
 错误信息通知
 
 @param errorInfo 错误信息字符串
 @discussion RTC通信过程中，错误信息的反馈
 */
- (void)onErrorInfoUpdate:(RtcErrorCodes)errorInfo;



/**
 RTC引擎状态信息统计
 
 @param statistics rtc引擎状态信息统计数组
 @discussion 该callback返回当前rtc engine的一些参数和性能信息，如传输fps,码率，网络状况,cpu等信息给app
 */
- (void)onEngineStatisticsInfo:(NSArray *)statistics;

@optional
/**
 文本消息到达通知

 @param msg 消息结构体，具体消息在该结构体中
 @discussion 当房间的其他用户发消息时，该接口会被调用，并携带所发送的消息
 */
- (void)onTextMessageArrival:(RtcMessageInfo *)msg;

/**
 文本消息到达通知 与onTextMessageArrival区别为
 
 @param msg 消息结构体，具体消息在该结构体中
 @discussion 当房间的其他用户发消息时，该接口会被调用，并携带所发送的消息
 */
- (void)onTextMessageArrival2:(RtcMessageInfo *)msg;

/**
 用户attribute值获取通知
 
 @param attribute 用户attribute值
 @discussion 当调用getUserAttribute获取用户Attribute属性时，该接口会被调用，返回用户attribute属性
 */
- (void)onTextMessageAttribute:(NSNumber *)userID attribute:(NSString *)attribute;

@end

#endif /* BaiduRtcRoomApi_h */
