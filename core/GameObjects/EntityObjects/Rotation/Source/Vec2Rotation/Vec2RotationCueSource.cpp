#include "Vec2RotationCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

Vec2RotationCueSource::Vec2RotationCueSource(
        Vec2RotationCueProperty property) :
            _property(std::move(property)) {}

Vec2RotationCueSource::~Vec2RotationCueSource() = default;

RotationCue Vec2RotationCueSource::get() const {
    const float direction_angle = Math::angleFromTo(
        _property.base->get(), 
        _property.target->get()
    );

    return {direction_angle, true};
}