#include "TrajectoryBase.h"

#include <algorithm>
#include <cmath>

#include "Math/Constants.h"
#include "../ITrajectoryFunction.h"

TrajectoryBase::~TrajectoryBase() = default;

TrajectoryBase::TrajectoryBase(
        const float reach_radius,
        std::unique_ptr<IVec2Source> base,
        std::unique_ptr<IVec2Source> target,
        std::unique_ptr<ITrajectoryFunction> updater):
            _reach_radius(reach_radius),
            _start(base->get()),
            _target(base->get()),
            _base(std::move(base)),
            _end(std::move(target)),
            _updater(std::move(updater)){}

float TrajectoryBase::getDirectionAngle(){
    return Math::angleFromTo(
        _base->get(), _target);
}

bool TrajectoryBase::isEnd(){   
    return _t >= _normalized_end;
}

void TrajectoryBase::consume(){
    for(
        float distance_sq = Math::distance_sq(_base->get(), _target);
        distance_sq <= _reach_radius * _reach_radius && !isEnd();
        distance_sq = Math::distance_sq(_base->get(), _target)
    ){
        _increment();

        const float world_scale = Math::distance(
            _start, _end->get());
        const float world_rotate = Math::angleFromTo(
            _start, _end->get());

        const Math::Vec2 point0 = _updater->calculate(_t);

        const float sin_product = std::sin(world_rotate);
        const float cos_product = std::cos(world_rotate);

        const Math::Vec2 rot = {
            .x = point0.x * cos_product - point0.y * sin_product,
            .y = point0.x * sin_product + point0.y * cos_product
        };

        const Math::Vec2 world_point = 
            rot * world_scale + _start;

        _target = world_point;
    }
}

void TrajectoryBase::_increment(){
    _t = std::clamp(
        _t + _normalized_inc,
        _normalized_start, 
        _normalized_end
    );
}