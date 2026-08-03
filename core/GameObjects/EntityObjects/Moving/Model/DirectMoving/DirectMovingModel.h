#ifndef THEMOLLUSK_DIRECT_MOVING_MODEL_H
#define THEMOLLUSK_DIRECT_MOVING_MODEL_H

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

#endif // !THEMOLLUSK_DIRECT_MOVING_MODEL_H