#ifndef THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H
#define THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H

#include "../IRotationCueSource.h"

#include <memory>

class IVec2Source;

class RotationCueSource :
    public IRotationCueSource
{
public:
    RotationCueSource(std::unique_ptr<IVec2Source> cue);
    
    ~RotationCueSource();

    RotationCue get() const override;
private:
    std::unique_ptr<IVec2Source> _cue;
};

#endif // !THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H