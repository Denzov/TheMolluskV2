#ifndef _I_MOVING_INTENT_SOURCE_STRATEGY_H_
#define _I_MOVING_INTENT_SOURCE_STRATEGY_H_

#include "../../Intent/MovingIntent.h"

class IMovingIntentSourceStrategy {
public:
    virtual ~IMovingIntentSourceStrategy() = default;

    virtual MovingIntent process() = 0;
};

#endif // !_I_MOVING_INTENT_SOURCE_STRATEGY_H_