#include "MereTargetMovingCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

MereTargetMovingCueSource::MereTargetMovingCueSource(
        MereTargetMovingCueProperty property):
            _property(std::move(property)) {}

MereTargetMovingCueSource::~MereTargetMovingCueSource() = default;

MovingCue MereTargetMovingCueSource::get() const {
    return {
        .direction_angle = Math::angleFromTo(
            _property.base->get(), 
            _property.target->get()), 
        .is_moving = true
    };
}