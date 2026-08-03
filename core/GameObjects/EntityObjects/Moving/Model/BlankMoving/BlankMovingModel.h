#ifndef _BLANK_MOVING_MODEL_H_
#define _BLANK_MOVING_MODEL_H_

#include "../IMovingModel.h"

#include <raylib.h>

class BlankMovingModel :
    public IMovingModel
{
public:
    Vector2 process(MovingCue cue, const float dt) override;
};

#endif // !_BLANK_MOVING_MODEL_H_