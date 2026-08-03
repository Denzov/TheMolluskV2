#ifndef THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H
#define THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H

#include "../IRotationCueSource.h"
#include "GameObjects/Vector2Source/IVector2Source.h"

#include <memory>

class MovingDirectionRotationCueSource :
    public IRotationCueSource
{
public:
    MovingDirectionRotationCueSource(std::unique_ptr<IVector2Source> base) :
        _base(std::move(base)) {}

    RotationCue get() const override;

private:
    mutable float _prev_angle = 0;
    mutable Vector2 _prev_base = {};
    mutable Vector2 _prev_target = {};
    
    std::unique_ptr<IVector2Source> _base;

};

#endif // !THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H