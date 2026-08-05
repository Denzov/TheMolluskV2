#ifndef THEMOLLUSK_BLANK_MOVING_MODEL_H
#define THEMOLLUSK_BLANK_MOVING_MODEL_H

#include "../IMovingModel.h"

class BlankMovingModel :
    public IMovingModel
{
public:
    Math::Vec2 process(MovingCue cue, const float dt) override;
};

#endif // !THEMOLLUSK_BLANK_MOVING_MODEL_H