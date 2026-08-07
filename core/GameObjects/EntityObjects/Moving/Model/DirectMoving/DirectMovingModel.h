#ifndef THEMOLLUSK_DIRECT_MOVING_MODEL_H
#define THEMOLLUSK_DIRECT_MOVING_MODEL_H

#include "../IMovingModel.h"

class DirectMovingModel :
    public IMovingModel
{
public:
    Math::Vec2 process(MovingCue, 
        const float desired_velocity, const float dt) override;
};

#endif // !THEMOLLUSK_DIRECT_MOVING_MODEL_H