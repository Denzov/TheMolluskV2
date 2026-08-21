#include "Trajectory.h"

#include <algorithm>
#include <cmath>

#include "Math/Constants.h"

#include "GameObjects/Vec2Source/IVec2Source.h"
#include "ITrajectoryFunction.h"

Trajectory::Trajectory(
    TrajectoryProperty property):
        _property(std::move(property)) {}

float Trajectory::getDirectionAngle() const {
    return Math::angleFromTo(
        _property.base->get(), _target);
}

Math::Vec2 Trajectory::getBase() const {
    return _property.base->get();
}

bool Trajectory::isEnd() const {   
    return _is_end;
}

void Trajectory::reload(
        Math::Vec2 start,
        Math::Vec2 end) 
{
    _t = 0;
    _is_end = false;

    _on_position_change(start, end);
    _calc_target(start);
}

void Trajectory::consume (
    Math::Vec2 start,
    Math::Vec2 end)
{
    if(_is_end) return;

    const Math::Vec2 base_pos = _property.base->get();    
    const float reach_radius = _property.reach_radius;   

    const Math::Vec2 start_pos = start;
    const Math::Vec2 end_pos = end;

    const float end_skin_sq = Math::distance_sq(end_pos, _end_snapshot);
    const float start_skin_sq = Math::distance_sq(start_pos, _start_snapshot);

    const float valid_skin = reach_radius * _property.skin_threshold_ratio;
    const float valid_skin_sq = valid_skin * valid_skin;

    if( end_skin_sq > valid_skin_sq ||
        start_skin_sq > valid_skin_sq)
    {
        _on_position_change(start_pos, end_pos);
        _calc_target(start_pos);
    }

    float distance_sq = Math::distance_sq(base_pos, _target);

    while(distance_sq <= reach_radius * reach_radius &&
        _t < _normalized_end)
    {
        _increment();        
        _calc_target(start_pos);

        distance_sq = Math::distance_sq(base_pos, _target);
    }

    if( 
        _t >= _normalized_end && 
        distance_sq <= reach_radius * reach_radius) 
            _is_end = true;
}

void Trajectory::_increment(){
    _t = std::clamp(
        _t + _normalized_inc,
        _normalized_start, 
        _normalized_end
    );
}

void Trajectory::_on_position_change(Math::Vec2 start_pos, Math::Vec2 end_pos){
    _scale = Math::distance(
        start_pos, end_pos);

    if(_scale > Math::EPSILON)
        _normalized_inc = _inc_step / _scale;
    else 
        _normalized_inc = _normalized_end;
    
    const float world_rotate = Math::angleFromTo(
        start_pos, end_pos);

    _rot_sin_product = std::sin(world_rotate);
    _rot_cos_product = std::cos(world_rotate);

    _start_snapshot = start_pos;
    _end_snapshot = end_pos;
}

void Trajectory::_calc_target(Math::Vec2 start_pos){
    _point0 = _property.updater->calculate(_t);

    const Math::Vec2 rot = {
        .x = _point0.x * _rot_cos_product - _point0.y * _rot_sin_product,
        .y = _point0.x * _rot_sin_product + _point0.y * _rot_cos_product
    };

    const Math::Vec2 world_point = 
        rot * _scale + start_pos;

    _target = world_point;
}