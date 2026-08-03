#include "LineMovingCueSource.h"

#include <raylib.h>
#include <raymath.h>

#include <cmath>

#include "GameObjects/Vector2Source/IVector2Source.h"

LineMovingCueSource::LineMovingCueSource(
        std::unique_ptr<IVector2Source> cur_pos,
        std::unique_ptr<IVector2Source> aim_pos) : 
            _aim_pos(std::move(aim_pos)), _cur_pos(std::move(cur_pos)){}

LineMovingCueSource::~LineMovingCueSource() = default;

MovingCue LineMovingCueSource::get() const {
    const Vector2 sub = Vector2Subtract(_aim_pos->get(), _cur_pos->get());
    const float sq_len = Vector2LengthSqr(sub);

    if(sq_len < EPSILON) return {0.f, false};

    const float angle = std::atan2(sub.y, sub.x);
    return {angle, true};
}