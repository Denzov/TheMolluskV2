#include "Vec2RotationCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

Vec2RotationCueSource::Vec2RotationCueSource(
        std::unique_ptr<IVec2Source> cue) :
            _cue(std::move(cue)) {}

Vec2RotationCueSource::~Vec2RotationCueSource() = default;

RotationCue Vec2RotationCueSource::get() const {
    return {_cue->get(), true};
}