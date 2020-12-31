//
//  RTCSettingsModel.h
//  rtc_sdk_ios
//
//  Created by Sun,Jian(ACU-T102) on 2018/11/27.
//  Copyright © 2018年 Sun,Jian(ACU-T102). All rights reserved.
//

#ifndef RTCSettingsModel_h
#define RTCSettingsModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Model class for user defined settings.
 *
 * Handles storing the settings and provides default values if setting is not
 * set. Also provides list of available options for different settings. Stores
 * for example video codec, video resolution and maximum bitrate.
 */
@interface RTCSettingsModel : NSObject

/**
 * Returns current video fps nsnumber.
 * If no fps is in store, default value of 24 is returned.
 */
- (NSNumber *)currentVideoFpsSettingFromStore;

/**
 * Stores the provided fps value into the store.
 *
 * @param fps NSNumber representation of capture fps value.
 */
- (void)storeVideoFpsSetting:(NSNumber *)fps;

/**
 *  Return current video external render.
 */
- (BOOL)currentVideoExternalRenderSettingFromStore;

/**
 *  Stores the provided external render bool value.
 */
- (void)storeVideoExternalRenderSetting:(BOOL)isEnableExternalRender;

/**
 * Returns current video external capturer model.
 */
- (BOOL)currentVideoExternalCapturerSettingFromStore;

/**
 * Stores the provided external capturer bool value.
 */
- (void)storeVideoExternalCaptrerSetting:(BOOL)isEnableExternalCapturer;

/**
 * Returns currrent exporting audio record setting.
 */
- (BOOL)currentExportAudioRecordSettingFromStore;

/**
 * Store the provided audio exporting recording setting.
 */
- (void)storeExportAudioRecordSetting:(BOOL)isExportingAudioRecord;

/**
 * Returns current exporting audio playout setting.
 */
- (BOOL)currentExportAudioPlayoutSettingFromStore;

/**
 * Store the provided exporting audio playout setting.
 */
- (void)storeExportAudioPlayoutSetting:(BOOL)isExportingAudioPlayout;

/**
 * Returns current exporting audio record and playout mixing setting.
 */
- (BOOL)currentExportAudioRecordPlayoutMixSettingFromStore;

/**
 * Store the provided exporting audio record and playout mixing setting.
 */
- (void)storeExportAudioRecordPlayoutMixSetting:(BOOL)isExportingAudioRecordPlayoutMix;

/**
 * Store the provided external audio device bool value..
 */
- (void)storeAudioExternalDeviceSetting:(BOOL)isEnableExternalAudioDeivce;

/**
 * Returns current audio external device model.
 */
- (BOOL)currentAudioExteranlDeviceSettingFromStore;

/**
 * Returns array of available capture resoultions.
 *
 * The capture resolutions are represented as strings in the following format
 * [width]x[height]
 */
- (NSArray<NSString *> *)availableVideoResolutions;

/**
 * Returns current video resolution string.
 * If no resolution is in store, default value of 640x480 is returned.
 * When defaulting to value, the default is saved in store for consistency reasons.
 */
- (NSString *)currentVideoResolutionSettingFromStore;
- (int)currentVideoResolutionWidthFromStore;
- (int)currentVideoResolutionHeightFromStore;

/**
 * Stores the provided video resolution string into the store.
 *
 * If the provided resolution is no part of the available video resolutions
 * the store operation will not be executed and NO will be returned.
 * @param resolution the string to be stored.
 * @return YES/NO depending on success.
 */
- (BOOL)storeVideoResolutionSetting:(NSString *)resolution;

/**
 * Returns array of available video codecs.
 */
- (NSArray<NSString *> *)availableVideoCodecs;

/**
 * Returns current video codec setting from store if present or default (H264) otherwise.
 */
- (NSString *)currentVideoCodecSettingFromStore;

/**
 * Stores the provided video codec setting into the store.
 *
 * If the provided video codec is not part of the available video codecs
 * the store operation will not be executed and NO will be returned.
 * @param videoCodec settings the string to be stored.
 * @return YES/NO depending on success.
 */
- (BOOL)storeVideoCodecSetting:(NSString *)videoCodec;

/**
 * Returns current max bitrate setting from store if present.
 */
- (nullable NSNumber *)currentMaxBitrateSettingFromStore;

/**
 * Stores the provided bitrate value into the store.
 *
 * @param bitrate NSNumber representation of the max bitrate value.
 */
- (void)storeMaxBitrateSetting:(nullable NSNumber *)bitrate;

/**
 * Returns current session mode setting from store if present or default (NO) otherwise.
 */
- (BOOL)currentSessionModeSettingFromStore;

/**
 * Stores the provided session mode setting into the store.
 *
 * @param sessionMode the boolean value to be stored.
 */
- (void)storeSessionModeSetting:(BOOL)sessionMode;

/**
 * Returns current create AecDump setting from store if present or default (NO) otherwise.
 */
- (BOOL)currentCreateAecDumpSettingFromStore;

/**
 * Stores the provided create AecDump setting into the store.
 *
 * @param createAecDump the boolean value to be stored.
 */
- (void)storeCreateAecDumpSetting:(BOOL)createAecDump;

/**
 * Returns current setting whether to use level controller from store if present or default (NO)
 * otherwise.
 */
- (BOOL)currentUseLevelControllerSettingFromStore;

/**
 * Stores the provided use level controller setting into the store.
 *
 * @param useLevelController the boolean value to be stored.
 */
- (void)storeUseLevelControllerSetting:(BOOL)useLevelController;

/**
 * Returns current setting whether to use manual audio config from store if present or default (YES)
 * otherwise.
 */
- (BOOL)currentUseManualAudioConfigSettingFromStore;

/**
 * Stores the provided use manual audio config setting into the store.
 *
 * @param useManualAudioConfig the boolean value to be stored.
 */
- (void)storeUseManualAudioConfigSetting:(BOOL)useManualAudioConfig;

//hasVideo
- (BOOL)currentHasVideoSettingFromStore;

- (void)storeHasVideoSetting:(BOOL)hasVideo;

//hasAudio
- (BOOL)currentHasAudioSettingFromStore;

- (void)storeHasAudioSetting:(BOOL)hasAudio;

//isAutoPublish
- (BOOL)currentIsAutoPublishSettingFromStore;

- (void)storeIsAutoPublishSetting:(BOOL)isAutoPublish;

//isAutoASubscribe
- (BOOL)currentIsAutoSubscribeSettingFromStore;

- (void)storeIsAutoSubscribeSetting:(BOOL)isAutoSubscribe;

/**
 *   Live server transfer configuration related.
 */
//live url
- (NSString*)currentLiveUrlSettingFromStore;

- (void)storeLiveUrlSetting:(NSString*)liveUrl;

//live isMix
- (BOOL)currentLiveMixSettingFromStore;

- (void)storeLiveMixSetting:(BOOL)isLiveMix;

//live isRecord
- (BOOL)currentLiveRecordSettingFromStore;

- (void)storeLiveRecordSetting:(BOOL)isLiveRecord;

//live mix template
- (NSString *)currentLiveMixTemplateSettingFromStore;

- (void)storeLiveMixTemplateSetting:(NSString *)liveMixTemplate;

//live transfer mode
- (NSString *)currentLiveTransferModSettingFromStore;

- (void)storeLiveTransferModeSetting:(NSString *)liveTransferMode;

@end
NS_ASSUME_NONNULL_END

#endif /* RTCSettingsModel_h */
