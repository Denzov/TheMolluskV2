#ifndef THEMOLLUSK_BLANK_MOVING_MODEL_H
#define THEMOLLUSK_BLANK_MOVING_MODEL_H

#include "../IMovingModel.h"

class BlankMovingModel :
    public IMovingModel
{
public:
    Math::Vec2 process(MovingCue, 
        const float desired_velocity, const float dt) override;
};

#endif // !THEMOLLUSK_BLANK_MOVING_MODEL_H