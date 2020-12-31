//
//  BaiduRtcRoomApiAudioExternalDeviceDelegate.h
//  BaiduRtcRoom
//
//  Created by fusheng on 2020/7/31.
//  Copyright © 2020 Sun,Jian(ACU-T102). All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Record
@protocol BaiduRtcRoomApiAudioExternalRecordDevice <NSObject>
- (BOOL)initializeExternalRecordFormat:(AudioStreamBasicDescription *)asdes;
- (BOOL)uninitializeExternalRecord;
- (BOOL)startExternalRecord;
- (BOOL)stopExternalRecord;
- (OSStatus)onRenderData:(AudioUnitRenderActionFlags *)flags
                    time:(const AudioTimeStamp *)time
                  busNum:(UInt32)busNum
               numFrames:(UInt32)numFrames
                  ioData:(AudioBufferList *)ioData;
@end

@protocol BaiduRtcRoomApiAudioExternalRecordClient <NSObject>
- (OSStatus)onRecordData:(AudioUnitRenderActionFlags *)flags
                    time:(const AudioTimeStamp *)time
                  busNum:(UInt32)busNum
               numFrames:(UInt32)numFrames
                  ioData:(AudioBufferList *)ioData;
@end

// player
@protocol BaiduRtcRoomApiAudioExternalPlayerDevice <NSObject>
- (BOOL)initializeExternalPlayerFormat:(AudioStreamBasicDescription *)asdes;
- (BOOL)uninitializeExternalPlayer;
- (BOOL)startExternalPlayer;
- (BOOL)stopExternalPlayer;
@end

@protocol BaiduRtcRoomApiAudioExternalPlayerClient <NSObject>
- (OSStatus)onGetPlayoutData:(AudioUnitRenderActionFlags *)flags
                        time:(const AudioTimeStamp *)time
                      busNum:(UInt32)busNum
                   numFrames:(UInt32)numFrames
                      ioData:(AudioBufferList *)ioData;
@end

@protocol BaiduRtcRoomApiAudioExternalDeviceDelegate <NSObject>
- (id<BaiduRtcRoomApiAudioExternalRecordDevice>)createExternalRecord:(id<BaiduRtcRoomApiAudioExternalRecordClient>)client;
- (id<BaiduRtcRoomApiAudioExternalPlayerDevice>)createExternalPlayer:(id<BaiduRtcRoomApiAudioExternalPlayerClient>)client;
@end
NS_ASSUME_NONNULL_END
