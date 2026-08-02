#ifndef _MOVING_DIRECTION_AIM_SOURCE_H_
#define _MOVING_DIRECTION_AIM_SOURCE_H_

#include "IRotationCueSource.h"

#include <raymath.h>
#include <memory>

#include "GameObjects/Vector2Source/IVector2Source.h"

class MovingDirectionRotationCueSource :
    public IRotationCueSource
{
public:
    MovingDirectionRotationCueSource(std::unique_ptr<IVector2Source> base) :
        _base(std::move(base)) {}

    RotationCue get() override 
    {
        const Vector2 current = _base->get();
        const Vector2 velocity = Vector2Subtract(current, _prev_base);

        const float velocity_sq_len = Vector2LengthSqr(velocity);

        if (velocity_sq_len < EPSILON) return {_prev_target, true};

        const Vector2 target = Vector2Add(current, velocity);

        _prev_base = current;
        _prev_target = target;

        return {target, true};
    }

private:
    float _prev_angle = 0;
    Vector2 _prev_base = {};
    Vector2 _prev_target = {};
    std::unique_ptr<IVector2Source> _base;

};

#endif // !_MOVING_DIRECTION_AIM_SOURCE_H_