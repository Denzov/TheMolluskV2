#include "MovingDirectionRotationCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

#include <raymath.h>

MovingDirectionRotationCueSource::MovingDirectionRotationCueSource
    (std::unique_ptr<IVec2Source> base) :
        _base(std::move(base)) {}

MovingDirectionRotationCueSource::~MovingDirectionRotationCueSource() = default;

RotationCue MovingDirectionRotationCueSource::get() const {
    const Math::Vec2 current = _base->get();
    const Math::Vec2 velocity = current - _prev_base;

    const float velocity_sq_len = velocity.lengthSq();

    if (velocity_sq_len < EPSILON) return {_prev_target, true};

    const Math::Vec2 target = current + velocity;

    _prev_base = current;
    _prev_target = target;

    return {target, true};
}