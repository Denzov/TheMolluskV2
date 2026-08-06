#ifndef THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H
#define THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H

#include "../IRotationCueSource.h"

#include <memory>

class IVec2Source;

class Vec2RotationCueSource :
    public IRotationCueSource
{
public:
    Vec2RotationCueSource(std::unique_ptr<IVec2Source> cue);
    
    ~Vec2RotationCueSource();

    RotationCue get() const override;
private:
    std::unique_ptr<IVec2Source> _cue;
};

#endif // !THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H