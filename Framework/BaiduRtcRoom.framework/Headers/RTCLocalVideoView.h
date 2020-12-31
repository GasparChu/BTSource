//
//  RTCLocalVideoView.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/11/29.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef RTCLocalVideoView_h
#define RTCLocalVideoView_h
#import <UIKit/UIKit.h>
#import "RTCCommonDefine.h"
@interface RTCLocalVideoView : NSObject
@property(nonatomic, strong)RTCCameraPreviewView *videoView;

- (instancetype)initWithDelegate:(id)delegate;
@end

#endif /* RTCLocalVideoView_h */
