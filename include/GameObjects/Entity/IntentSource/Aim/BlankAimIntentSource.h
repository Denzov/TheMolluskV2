#ifndef _BLANK_AIM_INTENT_SOURCE_H_
#define _BLANK_AIM_INTENT_SOURCE_H_

#include "IAimIntentSource.h"

class BlankAimIntentSource :
    public IAimIntentSource
{
public:
    AimIntent get() override{
        return {{}, true};
    }
};

#endif // !_BLANK_AIM_INTENT_SOURCE_H_