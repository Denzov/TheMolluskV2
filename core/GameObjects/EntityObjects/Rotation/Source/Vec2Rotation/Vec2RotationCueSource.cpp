#include "Vec2RotationCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

RotationCueSource::RotationCueSource(
        std::unique_ptr<IVec2Source> cue) :
            _cue(std::move(cue)) {}

RotationCueSource::~RotationCueSource() = default;

RotationCue RotationCueSource::get() const {
    return {_cue->get(), true};
}