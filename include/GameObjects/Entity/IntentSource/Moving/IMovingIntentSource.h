#ifndef _I_MOVING_INTENT_SOURCE_H_
#define _I_MOVING_INTENT_SOURCE_H_

#include "../../Intent/MovingIntent.h"

class IMovingIntentSource {
public:
    virtual ~IMovingIntentSource() = default;

    virtual MovingIntent get() = 0;
};

#endif // !_I_MOVING_INTENT_SOURCE_H_