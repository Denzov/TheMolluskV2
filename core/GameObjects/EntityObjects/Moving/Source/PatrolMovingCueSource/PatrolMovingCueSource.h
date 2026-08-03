#ifndef THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <vector>
#include <memory>

class IVector2Source;

class PatrolMovingCueSource : 
    public IMovingCueSource 
{
public:
    PatrolMovingCueSource(
        const float reach_radius,
        std::unique_ptr<IVector2Source> self_pos, 
        std::vector<std::unique_ptr<IVector2Source>> waypoints);

    ~PatrolMovingCueSource();

    MovingCue get() const override;

private:
    const float _reach_radius;
    std::unique_ptr<IVector2Source> _self_pos;
    std::vector<std::unique_ptr<IVector2Source>> _waypoints;

    mutable size_t _cur_point_idx = 0;
};

#endif // !THEMOLLUSK_PATROL_MOVING_CUE_SOURCE_H