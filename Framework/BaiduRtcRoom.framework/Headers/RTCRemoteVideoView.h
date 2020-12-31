//
//  RTCRemoteVideoView.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/11/29.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef RTCRemoteVideoView_h
#define RTCRemoteVideoView_h
#import <UIKit/UIKit.h>
#import "RTCCommonDefine.h"

@class RTCRemoteVideoView;

@protocol RTCRemoteVideoViewDelegate
- (void)remoteVideoView:(RTCRemoteVideoView *)videoView didChangeVideoSize:(CGSize)size;
@end

@interface RTCRemoteVideoView : NSObject
@property (nonatomic, strong) __kindof UIView <RTCVideoRenderer> *videoView;
@property (nonatomic, weak) id <RTCRemoteVideoViewDelegate> videoViewDelegate;
- (instancetype)initWithDelegate:(id<RTCRemoteVideoViewDelegate>)delegate;
@end

#endif /* RTCRemoteVideoView_h */
