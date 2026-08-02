#ifndef _BLANK_MOVING_STRATEGY_H_
#define _BLANK_MOVING_STRATEGY_H_

#include <raylib.h>

#include "IMovingStrategy.h"

class BlankMovingStrategy :
    public IMovingStrategy
{
public:
    Vector2 process(MovingIntent intent, const float dt) override {
        return {0, 0};
    }
};

#endif // !_BLANK_MOVING_STRATEGY_H_