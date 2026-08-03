#include "MovingDirectionRotationCueSource.h"

#include "GameObjects/Vector2Source/IVector2Source.h"

#include <raymath.h>

MovingDirectionRotationCueSource::MovingDirectionRotationCueSource
    (std::unique_ptr<IVector2Source> base) :
        _base(std::move(base)) {}

MovingDirectionRotationCueSource::~MovingDirectionRotationCueSource() = default;

RotationCue MovingDirectionRotationCueSource::get() const {
    const Vector2 current = _base->get();
    const Vector2 velocity = Vector2Subtract(current, _prev_base);

    const float velocity_sq_len = Vector2LengthSqr(velocity);

    if (velocity_sq_len < EPSILON) return {_prev_target, true};

    const Vector2 target = Vector2Add(current, velocity);

    _prev_base = current;
    _prev_target = target;

    return {target, true};
}