#ifndef _I_AIM_INTENT_SOURCE_
#define _I_AIM_INTENT_SOURCE_

#include <raylib.h>

#include "../../Intent/AimIntent.h"

class IAimIntentSource{
public:
    virtual ~IAimIntentSource() = default;

    virtual AimIntent get() = 0;
};

#endif // !_I_AIM_INTENT_SOURCE_