#ifndef _FIRST_ORDER_MOVING_MODEL_H_
#define _FIRST_ORDER_MOVING_MODEL_H_

#include "IMovingModel.h"

#include <math.h>
#include <raymath.h>

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

    Vector2 process(MovingCue intent, float dt) override
    {
        Vector2 target_velocity = {};

        if(intent.is_moving)
        {
            target_velocity = {
                std::cos(intent.angle) * _property.desired_velocity,
                std::sin(intent.angle) * _property.desired_velocity
            };
        }

        float alpha = 1.f - std::exp(-dt / _property.T);

        _velocity.x = std::lerp(_velocity.x, target_velocity.x, alpha);
        _velocity.y = std::lerp(_velocity.y, target_velocity.y, alpha);

        return Vector2Scale(_velocity, dt);
    }

private:
    FirstOrderMovingProperty _property;

    Vector2 _velocity = {};
};

#endif // !_FIRST_ORDER_MOVING_MODEL_H_