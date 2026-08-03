#ifndef _DIRECT_MOVING_MODEL_H_
#define _DIRECT_MOVING_MODEL_H_

#include "../IMovingModel.h"

#include <raylib.h>

struct DirectMovingProperty{
    const float speed; // [1 / s]
};

class DirectMovingModel :
    public IMovingModel
{
public:
    DirectMovingModel(DirectMovingProperty property) : _property(property){}

    Vector2 process(MovingCue cue, const float dt) override;

private:
    const DirectMovingProperty _property;

};

#endif // !_DIRECT_MOVING_MODEL_H_