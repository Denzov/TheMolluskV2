#include "FirstOrderMovingModel.h"

#include <cmath>

FirstOrderMovingModel::FirstOrderMovingModel(
    Math::Vec2 position,
    FirstOrderMovingProperty property):
        MovingModelBase(position),
        _property(property) {}

void FirstOrderMovingModel::process(MovingCue cue, const float dt) {
    const Math::Vec2 target_velocity = (cue.is_moving)?
        Math::Vec2{
            std::cos(cue.direction_angle) * _property.desired_velocity,
            std::sin(cue.direction_angle) * _property.desired_velocity} : 
        Math::Vec2{0, 0};

    const float alpha = 1.f - std::exp(-dt / _property.T);

    _velocity = {
        .x = std::lerp(_velocity.x, target_velocity.x, alpha),
        .y = std::lerp(_velocity.y, target_velocity.y, alpha)
    };

    _position += _velocity * dt;
}