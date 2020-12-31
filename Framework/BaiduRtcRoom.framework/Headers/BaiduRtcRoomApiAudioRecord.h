//
//  BaiduLiveRoomApiAudioDelegate.h
//  BaiduRtcRoom
//
//  Created by Sun,Jian(ACU-T102) on 2019/3/28.
//  Copyright © 2019年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduLiveRoomApiAudioDelegate_h
#define BaiduLiveRoomApiAudioDelegate_h


@protocol BaiduRtcApiAudioRecordDelegate <NSObject>

@optional

/**
 音频录制回调
 
 @param audioData SDK 录制的音频源数据
 @param sampleRate 音频采样率
 @param numOfChannels 通道数量，单通道
 @param bitDepth 位深度，16 bit
 @param type 音源类型，参考 BaiduAPIAudioRecordMask
 @discussion 开启音频录制并设置成功代理对象后，用户调用此 API 获取 SDK 录制的音频数据。用户可自行对数据进行处理，例如：存储等。SDK 发送音频数据的周期为 20ms。存储数据时注意取 sampleRate、numOfChannels、bitDepth 参数写包头信息。退出房间后或停止录制后，该回调不再被调用
 */
- (void)onAudioRecord:(NSData *)audioData sampleRate:(int)sampleRate numOfChannels:(int)numOfChannels bitDepth:(int)bitDepth type:(unsigned int)type;

/**
 音频录制回调
 
 @param audioData SDK 录制的音频源数据
 @param sampleRate 音频采样率
 @param numOfChannels 通道数量，单通道
 @param bitDepth 位深度，16 bit
 @param timeStamp 音频时间戳， unit：ms
 @param type 音源类型，参考 BaiduAPIAudioRecordMask
 @discussion 开启音频录制并设置成功代理对象后，用户调用此 API 获取 SDK 录制的音频数据。用户可自行对数据进行处理，例如：存储等。SDK 发送音频数据的周期为 20ms。存储数据时注意取 sampleRate、numOfChannels、bitDepth 参数写包头信息。退出房间后或停止录制后，该回调不再被调用
 */
- (void)onAudioRecord:(NSData *)audioData sampleRate:(int)sampleRate numOfChannels:(int)numOfChannels bitDepth:(int)bitDepth timeStamp:(uint64_t)timeStamp type:(unsigned int)type;

/**
 音频录制回调
 
 @warning Deprecated，请使用 onAudioRecord:sampleRate:numOfChannels:bitDepth:type:
 */
- (void)onAudioRecord:(NSData *)audioData sampleRate:(int)sampleRate numOfChannels:(int)numOfChannels bitDepth:(int)bitDepth __attribute__ ((deprecated));
@end


#endif /* BaiduLiveRoomApiAudioDelegate_h */
