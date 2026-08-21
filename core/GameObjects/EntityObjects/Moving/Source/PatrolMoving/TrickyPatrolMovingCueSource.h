#ifndef THEMOLLUSK_TRICKY_PATROL_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_TRICKY_PATROL_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include "Moving/Trajectory/Trajectory.h"

#include <vector>
#include <memory>

class IVec2Source;

struct PatrolWaypoint{
    std::unique_ptr<IVec2Source> source;
    float reach_radius;
};


struct TrickyPatrolMovingCueProperty{
    std::vector<PatrolWaypoint> waypoints;
    Trajectory trajectory;
};

class TrickyPatrolMovingCueSource : 
    public IMovingCueSource 
{
public:
    TrickyPatrolMovingCueSource(
        TrickyPatrolMovingCueProperty property);

    ~TrickyPatrolMovingCueSource();

    MovingCue get() const override;

private:
    static constexpr size_t FIRST_POINT_IDX = 0;

    mutable TrickyPatrolMovingCueProperty _property;

    mutable Math::Vec2 _prev_point = {};
    mutable size_t _cur_point_idx = 0;
};

#endif // !THEMOLLUSK_TRICKY_PATROL_MOVING_CUE_SOURCE_H