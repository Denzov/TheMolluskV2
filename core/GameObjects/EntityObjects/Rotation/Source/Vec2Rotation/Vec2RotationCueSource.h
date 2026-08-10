#ifndef THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H
#define THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H

#include "../IRotationCueSource.h"

#include <memory>

class IVec2Source;

struct Vec2RotationCueProperty{
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<IVec2Source> target;
};

class Vec2RotationCueSource :
    public IRotationCueSource
{
public:
    Vec2RotationCueSource(
        Vec2RotationCueProperty property);
    
    ~Vec2RotationCueSource();

    RotationCue get() const override;
    
private:
    Vec2RotationCueProperty _property;
};

#endif // !THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H