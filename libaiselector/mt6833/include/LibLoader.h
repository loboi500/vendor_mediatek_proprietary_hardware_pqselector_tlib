#ifndef __LIB_LOADER_H__
#define __LIB_LOADER_H__

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "LibLoader"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Logger.h>

class LibLoader {
private:
    static LibLoader mLoader; // Singleton

    void *mLib;
    void *mLib2; // prior to mLib

    template <typename T>
    void logLoadVar(const char *name, const T* var) {
        SELECTOR_LOGD("Load %s[%d]", name, (int)*var);
    }

public:
    LibLoader(const char *libPath, const char *libPath2 = NULL);

    ~LibLoader();

    bool isGood() {
        return (mLib != NULL || mLib2 != NULL);
    }

    void *getSymbol(const char *name);

    template <typename T>
    bool loadVar(const char *name, T* var, int index = 0) {
        if (index < 0)
            return false;

        void *symbolPtr = getSymbol(name);
        if (symbolPtr != NULL) {
            *var = static_cast<T*>(symbolPtr)[index];
            logLoadVar(name, var);
            return true;
        }

        return false;
    }

    template <typename T>
    bool loadArray(const char *name, T* var, unsigned int len, int index = 0) {
        if (index < 0)
            return false;

        void *symbolPtr = getSymbol(name);
        if (symbolPtr != NULL) {
            T *arrPtr = static_cast<T*>(symbolPtr) + len * index;
            memcpy(var, arrPtr, sizeof(T) * len);
            SELECTOR_LOGD("Load %s[%d]", name, index);
            return true;
        }

        return false;
    }

    void* getFunction(const char *name) {
        return getSymbol(name);
    }

    static LibLoader& getLoader() {
        return mLoader;
    }
};


template <>
inline void LibLoader::logLoadVar<int>(const char *name, const int* var) {
    SELECTOR_LOGD("Load %s = %d", name, *var);
}

template <>
inline void LibLoader::logLoadVar<float>(const char *name, const float* var) {
    SELECTOR_LOGD("Load %s = %f", name, *var);
}

#endif // __LIB_LOADER_H__
