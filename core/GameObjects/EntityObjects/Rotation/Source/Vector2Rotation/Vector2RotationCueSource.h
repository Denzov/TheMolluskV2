#ifndef _VECTOR2_ROTATION_CUE_SOURCE_H_
#define _VECTOR2_ROTATION_CUE_SOURCE_H_

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

#endif // !_VECTOR2_ROTATION_CUE_SOURCE_H_