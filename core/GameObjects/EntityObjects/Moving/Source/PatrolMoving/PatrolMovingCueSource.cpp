#include "PatrolMovingCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

#include <cmath>

PatrolMovingCueSource::PatrolMovingCueSource(
    const float reach_radius,
    std::unique_ptr<IVec2Source> self_pos,
    std::vector<std::unique_ptr<IVec2Source>> waypoints) :
        _reach_radius(reach_radius),
        _self_pos(std::move(self_pos)),
        _waypoints(std::move(waypoints)) {}

PatrolMovingCueSource::~PatrolMovingCueSource() = default;

MovingCue PatrolMovingCueSource::get() const{
    Math::Vec2 cur = _self_pos->get();
    Math::Vec2 aim = _waypoints[_cur_point_idx]->get();

    const Math::Vec2 sub = aim - cur;
    const float angle = std::atan2(sub.y, sub.x);

    const float dist_sq = Math::distance_sq(cur, aim);
    if(dist_sq <= _reach_radius * _reach_radius){
        _cur_point_idx = (_cur_point_idx + 1) % _waypoints.size();
    }

    return {angle, true};
}