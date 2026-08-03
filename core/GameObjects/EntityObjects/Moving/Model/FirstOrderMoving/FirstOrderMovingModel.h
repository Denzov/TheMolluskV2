#ifndef THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H
#define THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H

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

#endif // !THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H