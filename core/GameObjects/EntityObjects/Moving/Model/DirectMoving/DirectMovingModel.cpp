#include "DirectMovingModel.h"

#include <raymath.h>

Math::Vec2 DirectMovingModel::process(MovingCue cue, const float dt) {
    if(!cue.is_moving) return {};

    const float ds_len = dt * _property.speed;

    const Math::Vec2 ds = {cos(cue.angle), sin(cue.angle)};
    const Math::Vec2 scaled_ds = ds * ds_len;

    return scaled_ds;
}