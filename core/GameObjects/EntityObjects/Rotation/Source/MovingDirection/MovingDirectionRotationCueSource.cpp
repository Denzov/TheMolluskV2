#include "MovingDirectionRotationCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"
#include "Math/Constants.h"

MovingDirectionRotationCueSource::MovingDirectionRotationCueSource(
    MovingDirectionRotationCueProperty property):
            _property(std::move(property)) {}

MovingDirectionRotationCueSource::~MovingDirectionRotationCueSource() = default;

RotationCue MovingDirectionRotationCueSource::get() const {
    const Math::Vec2 diff = _property.base->get() - _prev_base;
    _prev_base = _property.base->get();

    const float diff_len_sq = diff.lengthSq();

    if(diff_len_sq >= Math::EPSILON)
        _angle = diff.angle();

    return {_angle, true};
}