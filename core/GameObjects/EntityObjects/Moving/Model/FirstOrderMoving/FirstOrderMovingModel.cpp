#include "FirstOrderMovingModel.h"

#include <cmath>

FirstOrderMovingModel::FirstOrderMovingModel(
    Math::Vec2 position,
    FirstOrderMovingProperty property):
        MovingModelBase(position),
        _property(property) {}

void FirstOrderMovingModel::process(MovingCue cue, const float dt) {
    if(!cue.is_moving) return;

    const Math::Vec2 target_velocity = {
        std::cos(cue.direction_angle) * _property.desired_velocity,
        std::sin(cue.direction_angle) * _property.desired_velocity
    };

    const float alpha = 1.f - std::exp(-dt / _property.T);

    _velocity = {
        .x = std::lerp(_velocity.x, target_velocity.x, alpha),
        .y = std::lerp(_velocity.y, target_velocity.y, alpha)
    };

    _position += _velocity * dt;
}