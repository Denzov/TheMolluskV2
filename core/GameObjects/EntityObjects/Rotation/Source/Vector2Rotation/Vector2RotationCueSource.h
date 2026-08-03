#ifndef THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H
#define THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H

#include "../IRotationCueSource.h"
#include "GameObjects/Vector2Source/IVector2Source.h"

#include <memory>

class Vector2RotationCueSource :
    public IRotationCueSource
{
public:
    Vector2RotationCueSource(
        std::unique_ptr<IVector2Source> cue) :
            _cue(std::move(cue)) {}

    RotationCue get() const override;
private:
    std::unique_ptr<IVector2Source> _cue;
};

#endif // !THEMOLLUSK_VECTOR2_ROTATION_CUE_SOURCE_H