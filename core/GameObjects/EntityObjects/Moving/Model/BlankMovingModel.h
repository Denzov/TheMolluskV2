#ifndef _BLANK_MOVING_MODEL_H_
#define _BLANK_MOVING_MODEL_H_

#include <raylib.h>

#include "IMovingModel.h"

class BlankMovingModel :
    public IMovingModel
{
public:
    Vector2 process(MovingCue intent, const float dt) override {
        return {0, 0};
    }
};

#endif // !_BLANK_MOVING_MODEL_H_