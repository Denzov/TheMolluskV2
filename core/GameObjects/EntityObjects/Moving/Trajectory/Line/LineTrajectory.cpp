#include "LineTrajectory.h"

#include "LineFunction.h"
LineTrajectory::LineTrajectory(
        LineTrajectoryProperty property):
        TrajectoryBase(
            property.reach_radius,
            std::move(property.base),
            std::move(property.target), 
            std::make_unique<LineFunction>()){}