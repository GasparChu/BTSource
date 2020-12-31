//
//  RTCStatsBuilder.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/12/31.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef RTCStatsBuilder_h
#define RTCStatsBuilder_h
#import <Foundation/Foundation.h>

@class RTCLegacyStatsReport;

@interface RTCStatsInfo : NSObject
// Connection stats.
@property(nonatomic, copy) NSString *pConnRecvBitrate;
@property(nonatomic, copy) NSString *pConnRtt;
@property(nonatomic, copy) NSString *pConnSendBitrate;
@property(nonatomic, copy) NSString *pLocalCandType;
@property(nonatomic, copy) NSString *pRemoteCandType;
@property(nonatomic, copy) NSString *pTransportType;

// BWE stats.
@property(nonatomic, copy) NSString *pActualEncBitrate;
@property(nonatomic, copy) NSString *pAvailableRecvBw;
@property(nonatomic, copy) NSString *pAvailableSendBw;
@property(nonatomic, copy) NSString *pTargetEncBitrate;

// Video send stats.
@property(nonatomic, copy) NSString *pVideoEncodeMs;
@property(nonatomic, copy) NSString *pVideoInputFps;
@property(nonatomic, copy) NSString *pVideoInputHeight;
@property(nonatomic, copy) NSString *pVideoInputWidth;
@property(nonatomic, copy) NSString *pVideoSendCodec;
@property(nonatomic, copy) NSString *pVideoSendBitrate;
@property(nonatomic, copy) NSString *pVideoSendFps;
@property(nonatomic, copy) NSString *pVideoSendHeight;
@property(nonatomic, copy) NSString *pVideoSendWidth;
@property(nonatomic, copy) NSString *pVideoSendPacketsLost;
@property(nonatomic, copy) NSString *pVideoSendPacket;

// QP stats.
@property(nonatomic, assign) int iVideoQPSum;
@property(nonatomic, assign) int iFramesEncoded;
@property(nonatomic, assign) int iOldVideoQPSum;
@property(nonatomic, assign) int iOldFramesEncoded;

// Video receive stats.
@property(nonatomic, copy) NSString *pVideoDecodeMs;
@property(nonatomic, copy) NSString *pVideoDecodedFps;
@property(nonatomic, copy) NSString *pVideoOutputFps;
@property(nonatomic, copy) NSString *pVideoRecvBitrate;
@property(nonatomic, copy) NSString *pVideoRecvFps;
@property(nonatomic, copy) NSString *pVideoRecvHeight;
@property(nonatomic, copy) NSString *pVideoRecvWidth;
@property(nonatomic, copy) NSString *pVideoRecvPacket;
@property(nonatomic, copy) NSString *pVideoRecvPacketLost;
@property(nonatomic, copy) NSString *pVideoRecvEndToEndDelay;

// Audio send stats.
@property(nonatomic, copy) NSString *pAudioSendBitrate;
@property(nonatomic, copy) NSString *pAudioSendCodec;

// Audio receive stats.
@property(nonatomic, copy) NSString *pAudioCurrentDelay;
@property(nonatomic, copy) NSString *pAudioExpandRate;
@property(nonatomic, copy) NSString *pAudioRecvBitrate;
@property(nonatomic, copy) NSString *pAudioRecvCodec;
@end

/** Class used to accumulate stats information into a single displayable string.
 */
@interface RTCStatsBuilder : NSObject

/** String that represents the accumulated stats reports passed into this
 *  class.
 */
@property(nonatomic, readonly) NSString *statsString;

/* Struct that represents the accumulated stats reports passed into this class.
 */
@property(nonatomic, readonly) RTCStatsInfo* statsInfo;

/** Parses the information in the stats report into an appropriate internal
 *  format used to generate the stats string.
 */
- (void)parseStatsReport:(RTCLegacyStatsReport *)statsReport;

@end

#endif /* RTCStatsBuilder_h */
