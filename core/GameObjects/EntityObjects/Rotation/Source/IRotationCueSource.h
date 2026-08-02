#ifndef _I_AIM_INTENT_SOURCE_
#define _I_AIM_INTENT_SOURCE_

#include <raylib.h>

#include "../RotationCue.h"

class IRotationCueSource{
public:
    virtual ~IRotationCueSource() = default;

    virtual RotationCue get() = 0;
};

#endif // !_I_AIM_INTENT_SOURCE_