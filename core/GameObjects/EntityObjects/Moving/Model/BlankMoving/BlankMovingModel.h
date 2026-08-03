#ifndef THEMOLLUSK_BLANK_MOVING_MODEL_H
#define THEMOLLUSK_BLANK_MOVING_MODEL_H

#include "../IMovingModel.h"

#include <raylib.h>

class BlankMovingModel :
    public IMovingModel
{
public:
    Vector2 process(MovingCue cue, const float dt) override;
};

#endif // !THEMOLLUSK_BLANK_MOVING_MODEL_H