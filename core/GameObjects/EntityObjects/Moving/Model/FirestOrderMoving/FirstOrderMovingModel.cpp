#include "FirstOrderMovingModel.h"

#include <math.h>
#include <raymath.h>

Vector2 FirstOrderMovingModel::process(MovingCue cue, float dt)
{
    Vector2 target_velocity = {};

    if(cue.is_moving)
    {
        target_velocity = {
            std::cos(cue.angle) * _property.desired_velocity,
            std::sin(cue.angle) * _property.desired_velocity
        };
    }

    float alpha = 1.f - std::exp(-dt / _property.T);

    _velocity.x = std::lerp(_velocity.x, target_velocity.x, alpha);
    _velocity.y = std::lerp(_velocity.y, target_velocity.y, alpha);

    return Vector2Scale(_velocity, dt);
}