#include "MereTrajectory.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

MereTrajectory::MereTrajectory(
    MereTrajectoryProperty property):
        _property(std::move(property)){}

void MereTrajectory::consume(){}

float MereTrajectory::getDirectionAngle() const {
    return Math::angleFromTo(
        _property.base->get(), 
        _property.target->get()
    );
}

bool MereTrajectory::isEnd() const {
    const float distance_sq = 
        Math::distance_sq(
            _property.base->get(), 
            _property.target->get());

    return distance_sq <= _property.reach_radius * _property.reach_radius;
}