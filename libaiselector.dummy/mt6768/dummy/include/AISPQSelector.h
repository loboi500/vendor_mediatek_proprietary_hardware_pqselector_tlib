#ifndef __AISPQ_SELECTOR_H__
#define __AISPQ_SELECTOR_H__
#include <android/log.h>
#include <sys/system_properties.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class AISPQSelector {
public:
    AISPQSelector(){};
    ~AISPQSelector(){};
    template <typename T>
    void AISPQSelectorProxy(T *pSelector, PQSelectorInput selectorInput, int *vHist, int &Sel)
    {
        ALOGE("Dummy AISPQ Selector....");
    }
};

#endif