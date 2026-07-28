#ifndef _I_MOVING_STRATEGY_H_
#define _I_MOVING_STRATEGY_H_

#include <raylib.h>

#include "../Intent/MovingIntent.h"

class IMovingStrategy{
public:
    virtual ~IMovingStrategy() = default;

    virtual Vector2 process(MovingIntent, const float dt) = 0;
};

#endif // !_I_MOVING_STRATEGY_H_