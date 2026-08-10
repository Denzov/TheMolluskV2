#include "DirectMovingModel.h"

#include <cmath>

DirectMovingModel::DirectMovingModel(
    Math::Vec2 position, DirectMovingPropery property):
        MovingModelBase(position),
        _property(property) {}

void DirectMovingModel::process(MovingCue cue, const float dt) {
    if(!cue.is_moving) return;

    const float ds_len = dt * _property.velocity;

    const Math::Vec2 ds = {std::cos(cue.direction_angle), std::sin(cue.direction_angle)};
    const Math::Vec2 scaled_ds = ds * ds_len;

    _position += scaled_ds;
}