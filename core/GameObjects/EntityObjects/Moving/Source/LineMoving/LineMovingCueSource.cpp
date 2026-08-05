#include "LineMovingCueSource.h"

#include <cmath>

#include "Math/Constants.h"
#include "GameObjects/Vec2Source/IVec2Source.h"

LineMovingCueSource::LineMovingCueSource(
        std::unique_ptr<IVec2Source> cur_pos,
        std::unique_ptr<IVec2Source> aim_pos) : 
            _aim_pos(std::move(aim_pos)), _cur_pos(std::move(cur_pos)){}

LineMovingCueSource::~LineMovingCueSource() = default;

MovingCue LineMovingCueSource::get() const {
    const Math::Vec2 sub = _aim_pos->get() - _cur_pos->get();
    const float sq_len = sub.lengthSq();

    if(sq_len < Math::EPSILON) return {0.f, false};

    const float angle = std::atan2(sub.y, sub.x);
    return {angle, true};
}