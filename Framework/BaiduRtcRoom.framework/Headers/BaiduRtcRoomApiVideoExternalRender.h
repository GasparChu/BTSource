//
//  BaiduRtcRoomApiVideoExternalRender.h
//  BaiduRtcRoom
//
//  Created by Sun,Jian(ACU-T102) on 2019/3/28.
//  Copyright © 2019年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduRtcRoomApiVideoExternalRender_h
#define BaiduRtcRoomApiVideoExternalRender_h

@protocol BaiduRtcApiRenderDelegate <NSObject>

/**
 SDK 从用户端获取 PixelBuffer 地址
 
 @param width 视频宽度
 @param height 视频高度
 @param stride 视频帧数据每一行字节数
 @param format 视频帧数据格式
 @param userID 流名
 @return CVPixelBufferRef 对象
 @discussion 开启外部渲染，设置外部渲染代理对象成功后，SDK 通过此 API 从用户端获取 PixelBuffer 地址。SDK 获取到用户指定的 PixelBuffer 后，将采集的视频源数据拷贝进去
 */
- (CVPixelBufferRef)onCreateInputBufferWithWidth:(int)width
                                          height:(int)height
                                          stride:(int)stride
                                          format:(OSType)format
                                          userID:(NSInteger)userID;

/**
 SDK 拷贝视频数据完成通知
 
 @param pixelBuffer 拷贝完成的 PixelBuffer 地址
 @param userID 流名
 @discussion SDK 通过此回调通知用户数据拷贝完成。当外部渲染拉流数据，userID 为拉流流名
 */
- (void)onPixelBufferCopyed:(CVPixelBufferRef)pixelBuffer userID:(NSInteger)userID;

/**
 video 分辨率变化通知
 @param size 视频分辨率，size.width and size.height
 @param userID 流名
 @discussion 当远端传输过来的视频大小发生变化时，通过该callback通知用户，用户可使用变化后的size调整远端显示view
 */
- (void)onVideoSizeChange:(CGSize)size userID:(NSInteger)userID;

@end

#endif /* BaiduRtcRoomApiVideoExternalRender_h */
