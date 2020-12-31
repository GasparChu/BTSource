//
//  BaiduRtcRoomApiAudioSession.h
//  BaiduRtcRoom
//
//  Created by Sun,Jian(ACU-T102) on 2020/1/7.
//  Copyright © 2020年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef BaiduRtcRoomApiAudioSession_h
#define BaiduRtcRoomApiAudioSession_h

@protocol BaiduRtcRoomApiAudioSessionDelegate <NSObject>
@optional
/** Called on a system notification thread when AVAudioSession starts an
 *  interruption event.
 */
- (void)onAudioSessionDidBeginInterruption;

/** Called on a system notification thread when AVAudioSession ends an
 *  interruption event.
 */
- (void)onAudioSessionDidEndInterruption;

/** Called on a system notification thread when AVAudioSession changes the
 *  route.
 */
- (void)onAudioSessionDidChangeRouteWithReason:(AVAudioSessionRouteChangeReason)reason
                     previousRoute:(AVAudioSessionRouteDescription *)previousRoute;

/** Called on a system notification thread when AVAudioSession media server
 *  terminates.
 */
- (void)onAudioSessionMediaServerTerminated;

/** Called on a system notification thread when AVAudioSession media server
 *  restarts.
 */
- (void)onAudioSessionMediaServerReset;

/** Called on a BaiduRTC thread when the audio device is notified to begin
 *  playback or recording.
 */
- (void)onAudioSessionDidStartPlayOrRecord;

/** Called on a BaiduRTC thread when the audio device is notified to stop
 *  playback or recording.
 */
- (void)onAudioSessionDidStopPlayOrRecord;

/** Called when the AVAudioSession output volume value changes. */
- (void)onAudioSessiondidChangeOutputVolume:(float)outputVolume;

@end

#endif /* BaiduRtcRoomApiAudioSession_h */
