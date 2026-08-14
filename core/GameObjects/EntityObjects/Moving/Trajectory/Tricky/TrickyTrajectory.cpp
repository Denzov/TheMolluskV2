#include "TrickyTrajectory.h"

#include <algorithm>
#include <cmath>

#include "GameObjects/Vec2Source/IVec2Source.h"
#include "../ITrajectoryFunction.h"

TrickyTrajectory::TrickyTrajectory(
    TrickyTrajectoryProperty property):
        _target(property.base->get()),
        _property(std::move(property)){}

float TrickyTrajectory::getDirectionAngle() const {
    return Math::angleFromTo(
        _property.base->get(), _target);
}

bool TrickyTrajectory::isEnd() const {   
    return _t >= _normalized_end;
}

void TrickyTrajectory::consume(){
    const Math::Vec2 base_pos = _property.base->get();
    const Math::Vec2 start_pos = _property.start->get();
    const Math::Vec2 end_pos = _property.end->get();
    const float reach_radius = _property.reach_radius;

    for(
        float distance_sq = Math::distance_sq(base_pos, _target);
        distance_sq <= reach_radius * reach_radius && !isEnd();
        distance_sq = Math::distance_sq(base_pos, _target)
    ){
        _increment();

        const float skin_sq = Math::distance_sq(end_pos, _end_snapshot);
        const float valid_skin = reach_radius * _property.skin_threshold_ratio;

        if(skin_sq > valid_skin * valid_skin) {
            _world_scale = Math::distance(
                start_pos, end_pos);
            
            const float world_rotate = Math::angleFromTo(
                start_pos, end_pos);

            _rot_sin_product = std::sin(world_rotate);
            _rot_cos_product = std::cos(world_rotate);

            _end_snapshot = end_pos;
        }
        
        const Math::Vec2 point0 = _property.updater->calculate(_t);

        const Math::Vec2 rot = {
            .x = point0.x * _rot_cos_product - point0.y * _rot_sin_product,
            .y = point0.x * _rot_sin_product + point0.y * _rot_cos_product
        };

        const Math::Vec2 world_point = 
            rot * _world_scale + start_pos;

        _target = world_point;
    }
}

void TrickyTrajectory::_increment(){
    _t = std::clamp(
        _t + _normalized_inc,
        _normalized_start, 
        _normalized_end
    );
}