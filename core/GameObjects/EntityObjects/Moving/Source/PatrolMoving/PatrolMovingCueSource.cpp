#include "PatrolMovingCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

PatrolMovingCueSource::PatrolMovingCueSource(
        std::unique_ptr<IVec2Source> base, 
        std::vector<PatrolWaypoint> waypoints) :
        _base(std::move(base)),
        _waypoints(std::move(waypoints)) {}

PatrolMovingCueSource::~PatrolMovingCueSource() = default;

MovingCue PatrolMovingCueSource::get() const{
    Math::Vec2 base = _base->get();
    Math::Vec2 waypoint = _waypoints[_cur_point_idx].source->get();

    const float distance_sq  = Math::distance_sq(base, waypoint);
    const float reach_radius = _waypoints[_cur_point_idx].reach_radius;
    
    if(distance_sq <= reach_radius * reach_radius){
        _cur_point_idx = (_cur_point_idx + 1) % _waypoints.size();
    }
    
    const float direction_angle = Math::angleFromTo(base, waypoint);
    
    return {direction_angle, true};
}