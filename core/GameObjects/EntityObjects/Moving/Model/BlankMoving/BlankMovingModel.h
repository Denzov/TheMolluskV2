#ifndef THEMOLLUSK_BLANK_MOVING_MODEL_H
#define THEMOLLUSK_BLANK_MOVING_MODEL_H

#include "../MovingModelBase.h"

class BlankMovingModel :
    public MovingModelBase
{
public:
    BlankMovingModel():
        MovingModelBase({0, 0}) {}
    void process(MovingCue cue, const float dt) override;
};

#endif // !THEMOLLUSK_BLANK_MOVING_MODEL_H