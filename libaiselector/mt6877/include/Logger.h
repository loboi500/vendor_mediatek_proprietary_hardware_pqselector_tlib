#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <android/log.h>
#include <sys/system_properties.h>
#include <stdlib.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "AISPQSelector"

static int mPQLoggable = -1;
#define SELECTOR_LOGD(fmt, ...) \
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s: " fmt, __FUNCTION__, ##__VA_ARGS__);
#define SELECTOR_LOGE(fmt, ...) \
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "%s: " fmt, __FUNCTION__, ##__VA_ARGS__);

inline int isDebugable()
{
    if (mPQLoggable == -1) {
        char value[PROP_VALUE_MAX] = {'\0'};
        if (__system_property_get("vendor.debug.pq.loggable", value) >= 0) {
            mPQLoggable = atoi(value);
            SELECTOR_LOGD("loggable = %d ", mPQLoggable);
        }
    }
    return mPQLoggable;
}

#define SELECTOR_LOGI(fmt, ...) \
    do { \
        if (isDebugable()) \
            __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "%s: " fmt, __FUNCTION__, ##__VA_ARGS__); \
    }while(0)

#endif // __LOGGER_H__