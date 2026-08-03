#include "LineMovingCueSource.h"

#include <raylib.h>
#include <raymath.h>

#include <cmath>

MovingCue LineMovingCueSource::get() const {
    const Vector2 sub = Vector2Subtract(_aim_pos->get(), _cur_pos->get());
    const float sq_len = Vector2LengthSqr(sub);

    if(sq_len < EPSILON) return {0.f, false};

    const float angle = std::atan2(sub.y, sub.x);
    return {angle, true};
}