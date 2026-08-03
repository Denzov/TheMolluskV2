#include "PatrolMovingCueSource.h"

#include "GameObjects/Vector2Source/IVector2Source.h"

#include <raymath.h>

PatrolMovingCueSource::PatrolMovingCueSource(
    const float reach_radius,
    std::unique_ptr<IVector2Source> self_pos,
    std::vector<std::unique_ptr<IVector2Source>> waypoints) :
        _reach_radius(reach_radius),
        _self_pos(std::move(self_pos)),
        _waypoints(std::move(waypoints)) {}

PatrolMovingCueSource::~PatrolMovingCueSource() = default;

MovingCue PatrolMovingCueSource::get() const{
    if(!_waypoints[_cur_point_idx]) return {0, false};

    Vector2 cur = _self_pos->get();
    Vector2 aim = _waypoints[_cur_point_idx]->get();

    const Vector2 sub = Vector2Subtract(aim, cur);
    const float angle = std::atan2(sub.y, sub.x);

    const float dist_sq = Vector2DistanceSqr(cur, aim);
    if(dist_sq <= _reach_radius * _reach_radius) 
        _cur_point_idx = (_cur_point_idx + 1) % _waypoints.size();

    return {angle, true};
}