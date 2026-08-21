#ifndef THEMOLLUSK_MERE_PATROL_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_MERE_PATROL_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <vector>
#include <memory>

class IVec2Source;

struct PatrolWaypoint{
    std::unique_ptr<IVec2Source> source;
    float reach_radius;
};

struct MerePatrolMovingCueProperty{
    std::unique_ptr<IVec2Source> base;
    std::vector<PatrolWaypoint> waypoints;
};

class MerePatrolMovingCueSource : 
    public IMovingCueSource 
{
public:
    MerePatrolMovingCueSource(
        MerePatrolMovingCueProperty property);

    ~MerePatrolMovingCueSource();

    MovingCue get() const override;

private:
    MerePatrolMovingCueProperty _property;

    mutable size_t _cur_point_idx = 0;
};

#endif // !THEMOLLUSK_MERE_PATROL_MOVING_CUE_SOURCE_H