#include "FirstOrderMovingModel.h"

#include <math.h>
#include <raymath.h>

Math::Vec2 FirstOrderMovingModel::process(MovingCue cue, 
        const float desired_velocity, const float dt)
{
    Math::Vec2 target_velocity = {};

    if(cue.is_moving)
        target_velocity = {
            std::cos(cue.angle) * desired_velocity,
            std::sin(cue.angle) * desired_velocity
        };

    float alpha = 1.f - std::exp(-dt / _property.T);

    _velocity = {
        .x = std::lerp(_velocity.x, target_velocity.x, alpha),
        .y = std::lerp(_velocity.y, target_velocity.y, alpha)
    };

    return _velocity * dt;
}