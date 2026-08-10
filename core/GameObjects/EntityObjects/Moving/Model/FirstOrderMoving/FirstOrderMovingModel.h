#ifndef THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H
#define THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H

#include "../MovingModelBase.h"

struct FirstOrderMovingProperty{
    const float desired_velocity;
    const float T;
};

class FirstOrderMovingModel :
    public MovingModelBase
{
public:
    FirstOrderMovingModel(
        Math::Vec2 position,
        FirstOrderMovingProperty property);

    void process(MovingCue, const float dt) override;

private:
    FirstOrderMovingProperty _property = {};
    Math::Vec2 _velocity = {};
};

#endif // !THEMOLLUSK_FIRST_ORDER_MOVING_MODEL_H