#ifndef THEMOLLUSK_I_MOVING_MODEL_H
#define THEMOLLUSK_I_MOVING_MODEL_H

#include <raylib.h>

#include "../MovingCue.h"

class IMovingModel{
public:
    virtual ~IMovingModel() = default;

    virtual Vector2 process(MovingCue, const float dt) = 0;
};

#endif // !THEMOLLUSK_I_MOVING_MODEL_H