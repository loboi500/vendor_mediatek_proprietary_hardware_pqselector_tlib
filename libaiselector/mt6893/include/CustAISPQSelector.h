#ifndef __CUST_AISPQ_SELECTOR_H__
#define __CUST_AISPQ_SELECTOR_H__

#include "pthread.h"

typedef int (*CustSelector)(const float*, const int, const int, const int, int *, int&);

enum CustAISPQSelectorStatus {
    NOT_SUPPORT = 0,
    SUPPORT,
};

class CustAISPQSelector {
public:
    CustAISPQSelector();
    ~CustAISPQSelector();
    static CustAISPQSelector*    getInstance();
    static void         destroyInstance();

    CustAISPQSelectorStatus getCustAISPQSelectorSupport(void);
    CustSelector getColorSelector();
    CustSelector getDSSelector();
    CustSelector getSCLTMSelector();

private:
    static CustAISPQSelector *sPInstance;
    static pthread_mutex_t sLock;
    CustAISPQSelectorStatus mSupport;
    CustSelector mColorSelector;
    CustSelector mDSSelector;
    CustSelector mSCLTMSelector;
};
#endif