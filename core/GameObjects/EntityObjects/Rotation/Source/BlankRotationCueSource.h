#ifndef _BLANK_AIM_INTENT_SOURCE_H_
#define _BLANK_AIM_INTENT_SOURCE_H_

#include "IRotationCueSource.h"

class BlankRotationCueSource :
    public IRotationCueSource
{
public:
    RotationCue get() override{
        return {{}, true};
    }
};

#endif // !_BLANK_AIM_INTENT_SOURCE_H_