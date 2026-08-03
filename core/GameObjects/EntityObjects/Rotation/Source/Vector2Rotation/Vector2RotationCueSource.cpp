#include "Vector2RotationCueSource.h"

#include "GameObjects/Vector2Source/IVector2Source.h"

Vector2RotationCueSource::Vector2RotationCueSource(
        std::unique_ptr<IVector2Source> cue) :
            _cue(std::move(cue)) {}

Vector2RotationCueSource::~Vector2RotationCueSource() = default;

RotationCue Vector2RotationCueSource::get() const {
    if(!_cue) return {{}, false};

    return {_cue->get(), true};
}