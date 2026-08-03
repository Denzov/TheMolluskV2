#ifndef _FIRST_ORDER_MOVING_MODEL_H_
#define _FIRST_ORDER_MOVING_MODEL_H_

#include "../IMovingModel.h"

struct FirstOrderMovingProperty{
    const float desired_velocity;
    const float T;
};

class FirstOrderMovingModel :
    public IMovingModel
{
public:
    FirstOrderMovingModel(FirstOrderMovingProperty property)
        : _property(property) {}

    Vector2 process(MovingCue cue, float dt) override;

private:
    FirstOrderMovingProperty _property;

    Vector2 _velocity = {};
};

#endif // !_FIRST_ORDER_MOVING_MODEL_H_