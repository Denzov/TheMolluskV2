#include "DirectMovingModel.h"

#include <raymath.h>

Vector2 DirectMovingModel::process(MovingCue cue, const float dt) {
    if(!cue.is_moving) return {};

    const float ds_len = dt * _property.speed;

    const Vector2 ds = {cos(cue.angle), sin(cue.angle)};
    const Vector2 scaled_ds = Vector2Scale(ds, ds_len);

    return scaled_ds;
}