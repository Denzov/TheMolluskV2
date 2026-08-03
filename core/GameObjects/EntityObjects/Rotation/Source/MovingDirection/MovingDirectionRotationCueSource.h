#ifndef THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H
#define THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H

#include "../IRotationCueSource.h"

#include <memory>

class IVector2Source;

class MovingDirectionRotationCueSource :
    public IRotationCueSource
{
public:
    MovingDirectionRotationCueSource(std::unique_ptr<IVector2Source> base);
    ~MovingDirectionRotationCueSource();

    RotationCue get() const override;

private:
    mutable float _prev_angle = 0;
    mutable Vector2 _prev_base = {};
    mutable Vector2 _prev_target = {};
    
    std::unique_ptr<IVector2Source> _base;
};

#endif // !THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H