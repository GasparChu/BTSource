//
//  BaiduRtcRoomApiDefines.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/12/5.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduRtcRoomApiDefines_h
#define BaiduRtcRoomApiDefines_h
#import <Foundation/Foundation.h>

/** 用户状态 */
@interface RtcRoomUserInfo : NSObject
/** 用户 ID */
@property (nonatomic, copy) NSNumber *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 属性 */
@property (nonatomic, copy) NSString *attribute;
/** 角色 */
@property (nonatomic, assign) int role;
@end

/**
 文本消息结构
 */
@interface RtcMessageInfo : NSObject
/**
 userId, 文本消息的归属者
 */
@property (nonatomic, copy) NSNumber *userId;

/**
 消息类型
 */
@property (nonatomic, assign) int type;

/**
 具体的文本消息
 */
@property (nonatomic, copy) NSString *message;
@end

/** 用户语音激励 */
@interface RtcRoomAudioLevel : NSObject
/** 用户 ID */
@property (nonatomic, copy) NSNumber *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 音量 */
@property (nonatomic, assign) NSInteger volumeLevel;
@end

typedef NS_ENUM(NSInteger, RtcRoomEventType) {
    RTC_ROOM_EVENTS_ROOM_CREATED = 100,   //创建房间成功
    RTC_ROOM_EVENTS_ROOM_JOINED,          //加入房间成功
    RTC_ROOM_EVENTS_USER_JOINED,          //有用户加入房间
    RTC_ROOM_EVENTS_USER_LEAVING,         //有用户离开房间
    RTC_ROOM_EVENTS_RECEIVED_HANGUP,      //收到server端挂断通知
    RTC_ROOM_EVENTS_RECEIVED_TIMEOUT,     //server端接收信令超时通知, 没有收到client发送到信令
    RTC_ROOM_EVENTS_SENT_TIMEOUT,         //client端发送信令超时，没有server responce
    RTC_ROOM_EVENTS_SENDING_MEDIA_OK,
    RTC_ROOM_EVENTS_SENDING_MEDIA_FAILED,
    RTC_ROOM_EVENTS_PUBLISHE_STREAMING_ERROR, //server端规定时间内未能收到client端推送上去的流
    RTC_ROOM_EVENTS_USEREVENTS_USER_JOINED = 110, //userevent事件 用户加入房间
    RTC_ROOM_EVENTS_USEREVENTS_USER_LEAVING,   //userevent事件 用户退出房间
    RTC_ROOM_EVENTS_DISBAND_ROOM = 112,
    RTC_ROOM_EVENTS_SOMEBODY_SHUTUPED = 113,
    RTC_ROOM_EVENTS_SOMEBODY_DISSHUTUPED = 114,
    RTC_ROOM_EVENTS_SOMEBODY_KICKOFFED = 115,
    RTC_ROOM_EVENTS_LIVE_PUBLISH_SUCCESS = 116,
    RTC_ROOM_EVENTS_LIVE_PUBLISH_FAIL = 117,
    RTC_ROOM_EVENTS_LIVE_INTRERRUPT = 118,
    RTC_ROOM_EVENTS_OTHERS                //未知事件
};

typedef NS_ENUM(NSInteger, RtcSignalChannelStats) {
    RTC_SIGNAL_CHANNEL_STATS_ESTABLISHING = 150,
    RTC_SIGNAL_CHANNEL_STATS_ESTABLISHED,
    RTC_SIGNAL_CHANNEL_STATS_CLOSED,
    RTC_SIGNAL_CHANNEL_STATS_FAILED,
    RTC_SIGNAL_CHANNEL_STATS_DISCONNECT,
    RTC_SIGNAL_CHANNEL_STATS_OTHERS
};

typedef NS_ENUM(NSInteger, RtcMediaChannelStats) {
    RTC_MEDIA_CHANNEL_STATS_CONNECTING = 200,
    RTC_MEDIA_CHANNEL_STATS_CONNECTED,
    RTC_MEDIA_CHANNEL_STATS_DISCONNECTED,
    RTC_MEDIA_CHANNEL_STATS_FAILED,
    RTC_MEDIA_CHANNEL_STATS_OTHERS
};

typedef NS_ENUM(NSInteger, RtcDataChannelStats) {
    RTC_DATA_CHANNEL_STATS_CONNECTING = 300,
    RTC_DATA_CHANNEL_STATS_CONNECTED,
    RTC_DATA_CHANNEL_STATS_DISCONNECTED,
    RTC_DATA_CHANNEL_STATS_FAILED,
    RTC_DATA_CHANNEL_STATS_OTHERS
};

typedef NS_ENUM(NSInteger, RtcPeerConnectionType) {
    RTC_PEER_CONNECTION_TYPE_DATA_CHANNEL = 0,
    RTC_PEER_CONNECTION_TYPE_SIGNAL_CHANNEL,
    RTC_PEER_CONNECTION_TYPE_MEDIA_CHANNEL
};

typedef NS_ENUM(NSInteger, RtcErrorCodes) {
    RTC_VIDEO_CAPTURE_ERROR = 400,
    RTC_AUDIO_CAPTUER_ERROR,

    RTC_VIDEO_ENCODE_ERROR,
    RTC_VIDEO_DECODE_ERROR,
    RTC_VIDEO_RENDER_ERROR,

    RTC_AUDIO_ENCODE_ERROR,
    RTC_AUDIO_DECODE_ERROR,
    RTC_AUDIO_RENDER_ERROR,

    RTC_VIDEO_SENDING_ERROR,
    RTC_VIDEO_RECEIVING_ERROR,

    RTC_AUDIO_SENDING_ERROR,
    RTC_AUDIO_RECEIVING_ERROR,

    RTC_ROOM_SERVER_NET_ERROR,
    RTC_MEDIA_SERVER_NET_ERROR,
    RTC_DATA_SERVER_NET_ERROR,

    RTC_SIGNALLING_FORMAT_ERROR,
    RTC_SIGNALLING_CREATE_SESSION_ERROR,
    RTC_SIGNALLING_ATTACH_PLUGIN_ERROR,
    RTC_SIGNALLING_CREATE_ROOM_ERROR,
    RTC_SIGNALLING_JOIN_ROOM_ERROR,
    RTC_SIGNALLING_MISSING_HANDLE_ERROR,

    RTC_NO_SUCH_ROOM_ERROR = 426,
    RTC_ROOM_ALREADY_EXIST_ERROR,
    RTC_USERID_ALREADY_EXIST_ERROR = 436,

    RTC_ERROR_OTHERS
};

typedef NS_ENUM(NSInteger, RtcParamSettingType) {
    RTC_AUDIO_PARAM_SETTINGS_HAS_AUDIO,
    RTC_AUDIO_PARAM_SETTINGS_AEC_DUMP,
    RTC_AUDIO_PARAM_SETTINGS_LEVEL_CONTROL,
    RTC_AUDIO_PARAM_SETTINGS_MANUAL_CONFIG,
    RTC_AUDIO_PARAM_SETTINGS_EXPORT_RECORD,
    RTC_AUDIO_PARAM_SETTINGS_EXPORT_PLAYOUT,
    RTC_AUDIO_PARAM_SETTINGS_EXPORT_RECORD_PLAYOUT_MIX,
    RTC_AUDIO_PARAM_SETTINGS_DEVICE_MODE,
    RTC_VIDEO_PARAM_SETTINGS_HAS_VIDEO,
    RTC_VIDEO_PARAM_SETTINGS_FPS,
    RTC_VIDEO_PARAM_SETTINGS_RESOLUTION,
    RTC_VIDEO_PARAM_SETTINGS_BITRATE,
    RTC_VIDEO_PARAM_SETTINGS_CODECTYPE,
    RTC_VIDEO_PARAM_SETTINGS_SESSION_MODE,
    RTC_VIDEO_PARAM_SETTINGS_CAPTURE_MODE,
    RTC_VIDEO_PARAM_SETTINGS_RENDER_MODE,
    RTC_PARAM_SETTINGS_AUTO_PUBLISH,
    RTC_PARAM_SETTINGS_AUTO_SUBSCRIBE,
    RTC_PARAM_SETTINGS_DATA_CHANNEL,
    RTC_PARAM_SETTINGS_RTMP_ANCHOR_TRANSFER_PARAM,
    RTC_PARAM_SETTINGS_RTMP_ROOM_TRANSFER_PARAM,
    RTC_PARAM_SETTINGS_ALL,
    RTC_PARAM_SETTINGS_OTHERS,
    RTC_VIDEO_PARAM_SETTINGS_MIN_BITRATE,
    RTC_VIDEO_PARAM_SETTINGS_MAX_BITRATE,
    RTC_VIDEO_PARAM_SETTINGS_ENABLE_HIGHPROFILE,
    RTC_VIDEO_PARAM_SETTINGS_ENABLE_FIXEDRESOLUTION,
    RTC_AUDIO_PARAM_SETTINGS_DISABLE_AUDIOMIX,
    RTC_VIDEO_PARAM_SETTINGS_ENABLE_DUMP,
    RTC_AUDIO_PARAM_SETTINGS_SAMPLE_RATE,
    RTC_VIDEO_PARAM_SETTINGS_FRAMING_ENHANCE,
};

typedef NS_ENUM(NSInteger, RtcStreamingStates) {
    RTC_VIDEO_STREAMING_STATES_ARRIVAL = 0,
    RTC_VIDEO_STREAMING_STATES_REMOVE,
    RTC_AUDIO_ONLY_STREAMING_STATES_ARRIVAL,
    RTC_AUDIO_ONLY_STREAMING_STATES_REMOVE,
    RTC_VIDEO_STREAMING_STATES_OTHERS
};

typedef NS_ENUM(NSInteger, RtcVideoEncodeType) {
    RTC_VIDEO_ENCODE_TYPE_H264 = 0,
    RTC_VIDEO_ENCODE_TYPE_VP8,
    RTC_VIDEO_ENCODE_TYPE_VP9,
    RTC_VIDEO_ENCODE_TYPE_HEVC,
    RTC_VIDEO_ENCODE_TYPE_OTHER
};

typedef NS_ENUM(NSInteger, RtcAudioEncodeType) {
    RTC_AUDIO_ENCODE_TYPE_OPUS = 0,
    RTC_AUDIO_ENCODE_TYPE_AAC,
    RTC_AUDIO_ENCODE_TYPE_EAAC,
    RTC_AUDIO_ENCODE_TYPE_SPEEX,
    RTC_AUDIO_ENCODE_TYPE_OTHER
};

typedef NS_ENUM(NSInteger, RtcAudioSessionNotificationType) {
    RTC_AUDIO_SESSION_NOTIFICATION_BEGIN_INTERRUPTION = 0,
    RTC_AUDIO_SESSION_NOTIFICATION_END_INTERRUPTION,
    RTC_AUDIO_SESSION_NOTIFICATION_CHANGE_ROUTE,
    RTC_AUDIO_SESSION_NOTIFICATION_MEDIA_SERVER_TERMINATED,
    RTC_AUDIO_SESSION_NOTIFICATION_MEDIA_SERVER_RESET,
    RTC_AUDIO_SESSION_NOTIFICATION_BEGIN_START_PLAY_OR_RECORD,
    RTC_AUDIO_SESSION_NOTIFICATION_BEGIN_STOP_PLAY_OR_RECORD,
    RTC_AUDIO_SESSION_NOTIFICATION_CHANGE_OUTPUT_VOLUME
};

typedef NS_ENUM(NSInteger, RtcSoundMode) {
    RTC_SOUND_MODE_SPEAKER = 0,
    RTC_SOUND_MODE_EAR
};

#pragma mark -- live related define.
@interface RtcLiveAuidoVideoParameters : NSObject
//Video parameters
@property(nonatomic, assign) UInt32 fps;
@property(nonatomic, assign) UInt32 width;
@property(nonatomic, assign) UInt32 height;
@property(nonatomic, assign) UInt32 vBitrate;
@property(nonatomic, assign) RtcVideoEncodeType vEncodeType;

//Audio parameters
@property(nonatomic, assign) UInt32 sampleRate;
@property(nonatomic, assign) UInt32 sampleSize;
@property(nonatomic, assign) UInt32 channelCount;
@property(nonatomic, assign) UInt32 aBitRate;
@property(nonatomic, assign) RtcAudioEncodeType aEncodeType;
@end

@interface LiveServerInfo : NSObject
@property (nonatomic, assign) BOOL isEnable;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *mixTemplate;
@property (nonatomic, assign) BOOL isMix;
@property (nonatomic, assign) BOOL isReocrding;
@property (nonatomic, strong) RtcLiveAuidoVideoParameters *avParam;
@end

typedef NS_ENUM(NSInteger, RtcLiveTransferMode) {
    RTC_LIVE_TRANSFER_MODE_ROOM_TRANSMISSION = 0,
    RTC_LIVE_TRANSFER_MODE_ANCHOR_TRASNSMISSION
};

typedef NS_ENUM(NSInteger, RtcServerMixTemplate) {
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_360P_4_3 = 0,  //主次平铺, 分辨率480x360
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_360P_16_9, //主次平铺, 分辨率640x360
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_480P_4_3,  //主次平铺, 分辨率640x480
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_480P_16_9, //主次平铺, 分辨率854x480
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_720P_4_3,  //主次平铺, 分辨率960x720
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_PRIMARY_720P_16_9, //主次平铺, 分辨率1280x720

    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_360P_4_3,  //平铺模式(大小相等), 分辨率480x360
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_360P_16_9, //平铺模式(大小相等), 分辨率640x360
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_480P_4_3,  //平铺模式(大小相等), 分辨率640x480
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_480P_16_9, //平铺模式(大小相等), 分辨率854x480
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_720P_4_3,  //平铺模式(大小相等), 分辨率960x720
    RTC_SERVER_MIX_TEMPLATE_SIDE_BY_SIDE_EQUAL_720P_16_9, //平铺模式(大小相等), 分辨率1280x720

    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_360P_4_3,  //画中画模式, 分辨率480x360
    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_360P_16_9, //画中画模式, 分辨率640x360
    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_480P_4_3,  //画中画模式, 分辨率640x480
    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_480P_16_9, //画中画模式, 分辨率854x480
    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_720P_4_3,  //画中画模式, 分辨率960x720
    RTC_SERVER_MIX_TEMPLATE_PICTURE_IN_PICTURE_BOTTOM_720P_16_9, //画中画模式, 分辨率1280x720
};

@interface RtcRoomEvents : NSObject
@property (nonatomic, assign) RtcRoomEventType rtcRoomEventType;
@property (nonatomic, strong) RtcRoomUserInfo *rtcRoomUserInfo;
@property (nonatomic, copy) NSString *byPassEventLevel;
@end

@interface RtcParameterSettings : NSObject
// Audio
@property (nonatomic, assign) BOOL hasAudio;
@property (nonatomic, assign) BOOL isCreatingAecDump;
@property (nonatomic, assign) BOOL isUsingLevelControl;
@property (nonatomic, assign) BOOL isUsingManualConfig;
@property (nonatomic, assign) BOOL isExportAudioRecord;
@property (nonatomic, assign) BOOL isExportAudioPlayout;
@property (nonatomic, assign) BOOL isExportAudioRecordPlayoutMix;
@property (nonatomic, assign) BOOL isEnableExternalAudioDevice;
@property (nonatomic, assign) BOOL disableAudioMixWithOthers;
@property (nonatomic, assign) int audioSampleRate;

// Video
@property (nonatomic, assign) BOOL hasVideo;
@property (nonatomic, assign) int videoFps;
@property (nonatomic, assign) int videoWidth;
@property (nonatomic, assign) int videoHeight;
@property (nonatomic, assign) int videoBitrate; // unit: kbps
@property (nonatomic, assign) int videoMinBitrate;  // unit: kbps
@property (nonatomic, assign) int videoMaxBitrate; // unit: kbps
@property (nonatomic, copy) NSString* videoCodecType;
@property (nonatomic, assign) BOOL isEnableExternalCapturer;
@property (nonatomic, assign) BOOL isEnableExternalRender;
@property (nonatomic, assign) BOOL isEnableHighProfile;
@property (nonatomic, assign) BOOL isEnableFixedResolution;
@property (nonatomic, assign) BOOL isEnableVideoDump;
@property (nonatomic, assign) BOOL isVideoFramingEnhance;

//发布订阅流
@property(nonatomic) BOOL isAutoPublish;
@property(nonatomic) BOOL isAutoSubscribe;

// Session Model
@property (nonatomic, assign) BOOL isMultiPlayerModel;

// Data channel
@property (nonatomic, assign) BOOL isEnableDataChannel;

// rtmp
@property (nonatomic, assign) LiveServerInfo *roomTransInfo;
@property (nonatomic, assign) LiveServerInfo *anchorTransInfo;
@property (nonatomic, assign) BOOL isMixing;
@property (nonatomic, copy) NSString *rtmpUrl;
@property (nonatomic, assign) RtcLiveTransferMode liveTransferMode;
@end

#endif /* BaiduRtcRoomApiDefines_h */
