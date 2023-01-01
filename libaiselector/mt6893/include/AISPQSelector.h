#ifndef __AISPQ_SELECTOR_H__
#define __AISPQ_SELECTOR_H__

#include "ColorAIselectorCore.h"
#include "PQDSImpl.h"
#include "mdpAALVPImpl.h"
#include "PQHDRImpl.h"
#include "PQSDR2HDRImpl.h"
#include "LibLoader.h"

class AISPQSelector {
public:
    AISPQSelector(){};
    ~AISPQSelector(){};

    void AISPQSelectorProxy(ColorAISelector *pColorAISelector, PQSelectorInput selectorInput, int *vHist, int &colorSel);
    void AISPQSelectorProxy(CPQDSFW *pDsFw, PQSelectorInput selectorInput, int *vHist, int &tdshpSel);
    void AISPQSelectorProxy(CDREVPTopFW *pDreVpFw, PQSelectorInput selectorInput, int *vHist, int &scltmSel);

private:
    bool hasLicense();
    int mHasLicense = -1;
};

#endif