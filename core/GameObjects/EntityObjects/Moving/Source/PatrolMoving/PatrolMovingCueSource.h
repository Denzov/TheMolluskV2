#ifndef THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <vector>
#include <memory>

class IVec2Source;

struct PatrolWaypoint{
    std::unique_ptr<IVec2Source> source;
    float reach_radius;
};

class PatrolMovingCueSource : 
    public IMovingCueSource 
{
public:
    PatrolMovingCueSource(
        std::unique_ptr<IVec2Source> base, 
        std::vector<PatrolWaypoint> waypoints);

    ~PatrolMovingCueSource();

    MovingCue get() const override;

private:
    std::unique_ptr<IVec2Source> _base;
    std::vector<PatrolWaypoint> _waypoints;

    mutable size_t _cur_point_idx = 0;
};

#endif // !THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H