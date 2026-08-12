#ifndef THEMOLLUSK_LINE_TRAJECTORY_H
#define THEMOLLUSK_LINE_TRAJECTORY_H

#include "../Base/TrajectoryBase.h"

struct LineTrajectoryProperty{
    const float reach_radius;
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<IVec2Source> target;
};

class LineTrajectory:
    public TrajectoryBase
{
public:
    LineTrajectory(
        LineTrajectoryProperty property);
};

#endif // !THEMOLLUSK_LINE_TRAJECTORY_H