#ifndef THEMOLLUSK_I_MOVING_MODEL_H
#define THEMOLLUSK_I_MOVING_MODEL_H

#include "Math/Vec2.h"
#include "../MovingCue.h"

class IMovingModel{
public:
    virtual ~IMovingModel() = default;

    virtual Math::Vec2 process(MovingCue, 
        const float desired_velocity, const float dt) = 0;
};

#endif // !THEMOLLUSK_I_MOVING_MODEL_H