#ifndef _I_MOVING_MODEL_H_
#define _I_MOVING_MODEL_H_

#include <raylib.h>

#include "../MovingCue.h"

class IMovingModel{
public:
    virtual ~IMovingModel() = default;

    virtual Vector2 process(MovingCue, const float dt) = 0;
};

#endif // !_I_MOVING_MODEL_H_