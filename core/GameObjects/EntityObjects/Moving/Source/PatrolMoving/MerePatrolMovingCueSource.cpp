#include "MerePatrolMovingCueSource.h"

#include "GameObjects/Vec2Source/IVec2Source.h"

MerePatrolMovingCueSource::MerePatrolMovingCueSource(
        MerePatrolMovingCueProperty property):
        _property(std::move(property)){}

MerePatrolMovingCueSource::~MerePatrolMovingCueSource() = default;

MovingCue MerePatrolMovingCueSource::get() const{
    Math::Vec2 base = _property.base->get();
    Math::Vec2 waypoint = _property.waypoints[_cur_point_idx].source->get();

    const float distance_sq  = Math::distance_sq(base, waypoint);
    const float reach_radius = _property.waypoints[_cur_point_idx].reach_radius;
    const size_t waypoints_size = _property.waypoints.size();
    
    if(distance_sq <= reach_radius * reach_radius){
        _cur_point_idx = (_cur_point_idx + 1) % waypoints_size;
    }
    
    const float direction_angle = Math::angleFromTo(base, waypoint);
    
    return {direction_angle, true};
}