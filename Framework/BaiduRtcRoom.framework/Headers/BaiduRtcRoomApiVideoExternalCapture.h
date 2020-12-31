//
//  BaiduRtcRoomApiVideoExternalCapture.h
//  BaiduRtcRoom
//
//  Created by Sun,Jian(ACU-T102) on 2019/3/26.
//  Copyright © 2019年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduRtcRoomApiVideoExternalCapture_h
#define BaiduRtcRoomApiVideoExternalCapture_h

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

/** 视频外部采集代理 */
@protocol BaiduVideoCaptureDelegate <NSObject>

/**
 接收视频帧数据
 
 @param image 采集到的视频数据
 @param time 采集时间戳
 @discussion 设置成功视频外部采集对象，并启动采集后，在此通知中获取视频帧数据
 */
- (void)onIncomingCapturedData:(nonnull CVImageBufferRef)image withPresentationTimeStamp:(CMTime)time;

/**
 接收视频帧数据
 
 @param textureID texture ID, 可以通过 CVOpenGLESTextureGetName(texture) 取得
 @param width 帧宽
 @param height 帧高
 @param time 采集时间戳
 */
- (void)onIncomingCapturedData:(GLuint)textureID width:(int)width height:(int)height withPresentationTimeStamp:(CMTime)time;

/**
 接受已编码的视频帧数据
 
 @param data 已编码数据
 @param config 编码配置，请参考 BaiduVideoCodecConfig 定义
 @param bKeyframe 是否为关键帧
 @param time 采集到该帧的时间戳，用于音画同步，如果采集实现是摄像头，最好使用系统采集回调的原始时间戳。如果不是，最好是生成该帧的UTC时间戳
 */
//- (void)onEncodedFrame:(nonnull NSData *)data config:(BaiduVideoCodecConfig)config bKeyframe:(bool)bKeyframe withPresentationTimeStamp:(CMTime)time;

@optional

/**
 
 @warning Deprecated
 */
- (void)onTakeSnapshot:(nonnull CGImageRef)image __attribute__ ((deprecated));

@end


/** 视频外部采集客户端代理 */
@protocol BaiduVideoCaptureClientDelegate <NSObject, BaiduVideoCaptureDelegate>

/**
 销毁
 
 @discussion 调用者需要在此 API 中进行相关的销毁操作
 */
- (void)destroy;

/**
 错误信息
 
 @param reason 错误原因
 */
- (void)onError:(nullable NSString*)reason;


/**
 设置图像填充模式
 
 @param mode 填充模式
 */
//- (void)setFillMode:(BaiduVideoFillMode)mode;

/**
 设置图像翻转模式
 
 @param mode 翻转模式, 参考BaiduVideoFlipMode的定义
 @discussion supportBufferType 为 BaiduVideoCaptureDeviceOutputBufferTypeGlTexture2D 时有效
 @discussion 默认值 BaiduVideoFlipVertical, 如果不需要，设置成BaiduVideoFlipNone
 */
- (void)setFlipMode:(int)mode;

@end


/** 视频外部采集设备接口 */
@protocol BaiduVideoCaptureDevice <NSObject>

@required

/**
 初始化采集使用的资源（例如启动线程等）回调
 
 @param client SDK 实现回调的对象，一定要保存
 @discussion 第一次调用开始预览／推流／拉流时调用
 */
- (void)baidu_allocateAndStart:(nonnull id<BaiduVideoCaptureClientDelegate>)client;

/**
 停止并且释放采集占用的资源
 
 @discussion 在此之后，不能再调用 client 对象的接口
 */
- (void)baidu_stopAndDeAllocate;

/**
 启动采集，采集的数据通过 [client -onIncomingCapturedData:withPresentationTimeStamp:] 通知 SDK
 
 @return 0 表示成功，其他是错误
 @discussion 一定要实现，不要做丢帧逻辑，SDK内部已经包含了丢帧策略
 */
- (int)baidu_startCapture;

/**
 停止采集
 
 @return 0 表示成功，其它是错误
 @discussion 一定要实现
 */
- (int)baidu_stopCapture;

@end

/** 视频外部采集工厂接口 */
@protocol BaiduVideoCaptureFactory <NSObject>

@required

/**
 创建采集设备
 
 @param deviceId 设备 Id
 @return 采集设备实例
 @discussion 一定要实现
 */
- (nonnull id<BaiduVideoCaptureDevice>)baidu_create:(nonnull NSString*)deviceId;

/**
 销毁采集设备
 
 @param device Baidu_create返回的采集设备实例
 @discussion 一定要实现
 */
- (void)baidu_destroy:(nonnull id<BaiduVideoCaptureDevice>)device;

@end

#endif /* BaiduRtcRoomApiVideoExternalCapture_h */
