#ifndef THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H
#define THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H

#include "../IRotationCueSource.h"

#include <memory>

class IVec2Source;

struct MovingDirectionRotationCueProperty{
    std::unique_ptr<IVec2Source> base;
};

class MovingDirectionRotationCueSource :
    public IRotationCueSource
{
public:
    MovingDirectionRotationCueSource(
        MovingDirectionRotationCueProperty property);
    
    ~MovingDirectionRotationCueSource();

    RotationCue get() const override;

private:
    mutable float _angle = 0;
    mutable Math::Vec2 _prev_base = {};
    
    MovingDirectionRotationCueProperty _property;
};

#endif // !THEMOLLUSK_MOVING_DIRECTION_AIM_SOURCE_H