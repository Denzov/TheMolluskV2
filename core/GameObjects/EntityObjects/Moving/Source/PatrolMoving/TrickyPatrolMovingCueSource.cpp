#include "TrickyPatrolMovingCueSource.h"

#include "Moving/Trajectory/ITrajectoryFunction.h"
#include "GameObjects/Vec2Source/IVec2Source.h"

TrickyPatrolMovingCueSource::TrickyPatrolMovingCueSource(
        TrickyPatrolMovingCueProperty property):
            _property(std::move(property)) 
{
    _prev_point = _property.trajectory.getBase();
    _property.trajectory.reload(
        _prev_point, 
        _property.waypoints[FIRST_POINT_IDX].source->get());
}       

TrickyPatrolMovingCueSource::~TrickyPatrolMovingCueSource() = default;

MovingCue TrickyPatrolMovingCueSource::get() const{
    Math::Vec2 base = _property.trajectory.getBase();
    Math::Vec2 waypoint = _property.waypoints[_cur_point_idx].source->get();

    const float distance_sq = 
        Math::distance_sq(base, waypoint);
    const float waypoint_reach_radius = 
        _property.waypoints[_cur_point_idx].reach_radius;
    const size_t waypoints_size = _property.waypoints.size();
    
    _property.trajectory.consume(
        _prev_point, 
        waypoint);

    const float direction_angle = _property.trajectory.getDirectionAngle();

    if(distance_sq <= waypoint_reach_radius * waypoint_reach_radius){
        _prev_point = waypoint;
        _cur_point_idx = (_cur_point_idx + 1) % waypoints_size;
    
        _property.trajectory.reload(
            _prev_point, 
            _property.waypoints[_cur_point_idx].source->get());
    }
    
    return {direction_angle, true};
}