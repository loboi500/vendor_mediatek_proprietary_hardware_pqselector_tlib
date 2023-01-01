#ifndef __AISPQ_LICENSE_H__
#define __AISPQ_LICENSE_H__

#include "pthread.h"

enum AISPQLicenseStatus {
    FAIL = 0,
    SUCCESS,
    TEMP_LIB_SUCCESS,
    TEMP_LIB_TIME_OUT
};

class AISPQLicense {
public:
    AISPQLicense();
    ~AISPQLicense();
    static AISPQLicense*    getInstance();
    static void         destroyInstance();
    AISPQLicenseStatus getAISPQSupport(void);

private:
    static AISPQLicense *sPInstance;
    static pthread_mutex_t sLock;
    AISPQLicenseStatus mSupport;
};


#endif
