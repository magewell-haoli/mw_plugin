////////////////////////////////////////////////////////////////////////////////
// CONFIDENTIAL and PROPRIETARY software of Magewell Electronics Co., Ltd.
// Copyright (c) 2011-2026 Magewell Electronics Co., Ltd. (Nanjing)
// All rights reserved.
// This copyright notice MUST be reproduced on all authorized copies.
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "fourcc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MW_PLUGIN_VERSION_NUMBER 1000001

typedef struct _mw_plugin_time_code {
    uint8_t hours;      // Hours (0-23)
    uint8_t minutes;    // Minutes (0-59)
    uint8_t seconds;    // Seconds (0-59)
    uint8_t frames;     // Frame count within the second
    uint8_t drop_flag;  // 1 if drop-frame timecode, 0 otherwise
} mw_plugin_time_code_t;

typedef struct _mw_plugin_video_frame {
    mw_fourcc_t fourcc;        // Pixel format, e.g. MW_FOURCC_YUYV, MW_FOURCC_NV12
    uint16_t cx;            // Frame width in pixels
    uint16_t cy;            // Frame height in pixels; for interlaced video, field height is cy / 2
    uint32_t frame_duration;// Frame duration in 100ns units
    bool interlaced;        // true if the frame is interlaced

    int num_planes;         // Number of data planes (1-4)
    struct {
        void *p_plane;      // Pointer to plane data buffer
        uint32_t nbytes;    // Number of valid bytes in the plane
        uint32_t stride;    // Stride in bytes per row
    } planes[4];            // Plane descriptors
} mw_plugin_video_frame_t;

typedef struct _mw_plugin_audio_frame {
    mw_fourcc_t fourcc;        // Audio sample format, e.g. MW_FOURCC_IF32
    uint32_t sample_rate;   // Sample rate in Hz
    uint16_t num_channels;  // Number of audio channels

    void *p_data;           // Pointer to audio data buffer
    uint32_t nbytes;        // Number of valid bytes in the buffer
} mw_plugin_audio_frame_t;

/** @brief Get the version number of the MW plugin.
    @return Plugin version number. */
int mw_plugin_version();

/** @brief Initialize the MW plugin.
    @return true on success, false on failure. */
bool mw_plugin_init();

/** @brief Shutdown the MW plugin and release resources. */
void mw_plugin_shutdown();

/** @brief Create metadata string for a video frame.
    @param p_video_frame Pointer to the video frame descriptor.
    @return Allocated metadata string, or NULL on failure. The string length must not exceed 255. */
char* mw_plugin_video_frame_metadata_create(const mw_plugin_video_frame_t *p_video_frame);

/** @brief Free the metadata string returned by mw_plugin_video_frame_metadata_create. */
void mw_plugin_video_frame_metadata_free(char *metadata);

/** @brief Create metadata string for an audio frame.
    @param p_audio_frame Pointer to the audio frame descriptor.
    @return Allocated metadata string, or NULL on failure. The string length must not exceed 255. */
char* mw_plugin_audio_frame_metadata_create(const mw_plugin_audio_frame_t *p_audio_frame);

/** @brief Free the metadata string returned by mw_plugin_audio_frame_metadata_create. */
void mw_plugin_audio_frame_metadata_free(char *metadata);

/** @brief Create metadata string for the NDI source.
    @return Allocated metadata string, or NULL on failure. The string length must not exceed 255. */
char* mw_plugin_ndi_source_metadata_create();

/** @brief Free the metadata string returned by mw_plugin_ndi_source_metadata_create. */
void mw_plugin_ndi_source_metadata_free(char *metadata);

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif