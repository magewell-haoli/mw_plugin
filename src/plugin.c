#include "mw_plugin/plugin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int mw_plugin_version()
{
    return MW_PLUGIN_VERSION_NUMBER;
}

bool mw_plugin_init()
{
    printf("mw_plugin_init ok");
    return true;
}

void mw_plugin_shutdown()
{
    printf("mw_plugin_shutdown ok");
}

static void get_time_string(char *buf, size_t buf_size)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm tm_info;
    localtime_r(&tv.tv_sec, &tm_info);
    snprintf(buf, buf_size, "%4d-%02d-%02d %02d:%02d:%02d.%03ld",
        tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday, tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec, tv.tv_usec / 1000);
}

static void get_fourcc_name(mw_fourcc_t fourcc, char name[5])
{
    name[0] = (char)(fourcc & 0xFF);
    name[1] = (char)((fourcc >> 8) & 0xFF);
    name[2] = (char)((fourcc >> 16) & 0xFF);
    name[3] = (char)((fourcc >> 24) & 0xFF);
    if (name[3] == ' ')
        name[3] = '\0';
    name[4] = '\0';
}

char* mw_plugin_video_frame_metadata_create(uint32_t stream_index, const mw_plugin_video_frame_t *p_video_frame)
{
    if (stream_index > e_video_stream_index_max) return NULL;
    if (!p_video_frame) return NULL;

    /*
    char name[5] = { 0 };
    get_fourcc_name(p_video_frame->fourcc, name);
    printf("video_frame: fourcc=%s, size=%dx%d, frame_duration=%d, interlaced=%d\n", name, p_video_frame->cx, p_video_frame->cy, p_video_frame->frame_duration, p_video_frame->interlaced);
    for (int32_t k = 0; k < p_video_frame->num_planes; k ++) {
        printf("plane[%d]: addr=%p, nbytes=%d, stride=%d\n", k, p_video_frame->planes[k].p_plane, p_video_frame->planes[k].nbytes, p_video_frame->planes[k].stride);
    }
    */

    char time_buf[256];
    get_time_string(time_buf, sizeof(time_buf));

    char *metadata = (char *)malloc(256);
    if (!metadata) return NULL;

    snprintf(metadata, 256, "<magewell_metadata type=\"video-%d\" time=\"%s\"/>", stream_index, time_buf);

    return metadata;
}

void mw_plugin_video_frame_metadata_free(uint32_t stream_index, char *metadata)
{
    if (stream_index > e_video_stream_index_max) return;

    if (metadata) free(metadata);
}

char* mw_plugin_audio_frame_metadata_create(const mw_plugin_audio_frame_t *p_audio_frame)
{
    if (!p_audio_frame) return NULL;

    /*
    char name[5] = { 0 };
    get_fourcc_name(p_audio_frame->fourcc, name);
    printf("audio_frame: fourcc=%s, sample_rate=%d, num_channel=%d, nbytes=%d\n", name, p_audio_frame->sample_rate, p_audio_frame->num_channels, p_audio_frame->nbytes);
    */

    char time_buf[256];
    get_time_string(time_buf, sizeof(time_buf));

    char *metadata = (char *)malloc(256);
    if (!metadata) return NULL;

    snprintf(metadata, 256, "<magewell_metadata type=\"audio\" time=\"%s\"/>", time_buf);

    return metadata;
}

void mw_plugin_audio_frame_metadata_free(char *metadata)
{
    if (metadata) free(metadata);
}

char* mw_plugin_ndi_source_metadata_create()
{
    char *metadata = (char *)malloc(256);
    if (!metadata) return NULL;

    static uint64_t g_source_id = 0;
    snprintf(metadata, 256, "<magewell_metadata type=\"ndi_source\" value=%ld/>", g_source_id ++);

    return metadata;
}

void mw_plugin_ndi_source_metadata_free(char *metadata)
{
    if (metadata) free(metadata);
}
