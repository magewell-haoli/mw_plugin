#include <dlfcn.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "mw_plugin/plugin.h"

typedef int (*MwPluginVersionFunc)();
typedef bool (*MwPluginInitFunc)();
typedef void (*MwPluginShutdownFunc)();
typedef char* (*MwPluginVideoFrameMetadataCreateFunc)(const mw_plugin_video_frame_t *p_video_frame);
typedef void (*MwPluginVideoFrameMetadataFreeFunc)(char *metadata);
typedef char* (*MwPluginAudioFrameMetadataCreateFunc)(const mw_plugin_audio_frame_t *p_audio_frame);
typedef void (*MwPluginAudioFrameMetadataFreeFunc)(char *metadata);
typedef char* (*MwPluginNdiSourceMetadataCreateFunc)();
typedef void (*MwPluginNdiSourceMetadataFreeFunc)(char *metadata);

MwPluginVersionFunc                   mw_plugin_version_fp = NULL;
MwPluginInitFunc                      mw_plugin_init_fp = NULL;
MwPluginShutdownFunc                  mw_plugin_shutdown_fp = NULL;
MwPluginVideoFrameMetadataCreateFunc  mw_plugin_video_frame_metadata_create_fp = NULL;
MwPluginVideoFrameMetadataFreeFunc    mw_plugin_video_frame_metadata_free_fp = NULL;
MwPluginAudioFrameMetadataCreateFunc  mw_plugin_audio_frame_metadata_create_fp = NULL;
MwPluginAudioFrameMetadataFreeFunc    mw_plugin_audio_frame_metadata_free_fp = NULL;
MwPluginNdiSourceMetadataCreateFunc   mw_plugin_ndi_source_metadata_create_fp = NULL;
MwPluginNdiSourceMetadataFreeFunc     mw_plugin_ndi_source_metadata_free_fp = NULL;

typedef struct _mw_plugin_func {
    char symbol[64];
    void **func;
} mw_plugin_func_t;

const static mw_plugin_func_t g_plugin_funcs[] = {
    { "mw_plugin_version",                      (void **)&mw_plugin_version_fp },
    { "mw_plugin_init",                         (void **)&mw_plugin_init_fp },
    { "mw_plugin_shutdown",                     (void **)&mw_plugin_shutdown_fp },
    { "mw_plugin_video_frame_metadata_create",  (void **)&mw_plugin_video_frame_metadata_create_fp },
    { "mw_plugin_video_frame_metadata_free",    (void **)&mw_plugin_video_frame_metadata_free_fp },
    { "mw_plugin_audio_frame_metadata_create",  (void **)&mw_plugin_audio_frame_metadata_create_fp },
    { "mw_plugin_audio_frame_metadata_free",    (void **)&mw_plugin_audio_frame_metadata_free_fp },
    { "mw_plugin_ndi_source_metadata_create",   (void **)&mw_plugin_ndi_source_metadata_create_fp },
    { "mw_plugin_ndi_source_metadata_free",     (void **)&mw_plugin_ndi_source_metadata_free_fp },
};

static bool us_dlsym(void *handle, const char *symbol, void **func)
{
    assert(handle);
    assert(symbol);
    assert(func);

    *func = dlsym(handle, symbol);
    char *error = dlerror();
    if (error) {
        printf("dlsym %s failed(%s)\n", symbol, error);
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    printf("mw_plugin_test in\n");

    void *handle = NULL;
    do {
        handle = dlopen("./libmw_plugin.so", RTLD_LAZY);
        if (!handle) {
            printf("dlopen failed\n");
            break;
        }
        dlerror();

        bool error = false;
        for (int i = 0; i < sizeof(g_plugin_funcs) / sizeof(mw_plugin_func_t); i++) {
            if (!us_dlsym(handle, g_plugin_funcs[i].symbol, g_plugin_funcs[i].func)) {
                error = true;
                break;
            }
        }
        if (error) {
            printf("dlsym failed\n");
            break;
        }

        int version = mw_plugin_version_fp();
        printf("mw_plugin_version: %d\n", version);

        bool init_ok = mw_plugin_init_fp();
        printf("mw_plugin_init: %s\n", init_ok ? "true" : "false");
        if (!init_ok) break;

        mw_plugin_video_frame_t video_frame;
        memset(&video_frame, 0, sizeof(video_frame));
        video_frame.fourcc = MW_FOURCC_NV12;
        video_frame.cx = 1920;
        video_frame.cy = 1080;
        video_frame.frame_duration = 333333;
        video_frame.interlaced = false;
        video_frame.num_planes = 2;

        char *video_metadata = mw_plugin_video_frame_metadata_create_fp(&video_frame);
        if (video_metadata) {
            printf("mw_plugin_video_frame_metadata_create: %s\n", video_metadata);
        }
        mw_plugin_video_frame_metadata_free_fp(video_metadata);

        mw_plugin_audio_frame_t audio_frame;
        memset(&audio_frame, 0, sizeof(audio_frame));
        audio_frame.fourcc = MW_FOURCC_IF32;
        audio_frame.sample_rate = 48000;
        audio_frame.num_channels = 2;
        audio_frame.nbytes = 8192;

        char *audio_metadata = mw_plugin_audio_frame_metadata_create_fp(&audio_frame);
        if (audio_metadata) {
            printf("mw_plugin_audio_frame_metadata_create: %s\n", audio_metadata);
        }
        mw_plugin_audio_frame_metadata_free_fp(audio_metadata);

        char *ndi_metadata = mw_plugin_ndi_source_metadata_create_fp();
        if (ndi_metadata) {
            printf("mw_plugin_ndi_source_metadata_create: %s\n", ndi_metadata);
        }
        mw_plugin_ndi_source_metadata_free_fp(ndi_metadata);

        mw_plugin_shutdown_fp();
    } while (false);

    if (handle) {
        dlclose(handle);
    }

    printf("mw_plugin_test out\n");
    return 0;
}
