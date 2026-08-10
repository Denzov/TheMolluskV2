#include "DelayedRotationModel.h"

#include "Math/Constants.h"
#include <cmath>

DelayedRotationModel::DelayedRotationModel(
    float rotation, 
    DelayedRotationProperty property):
        RotationModelBase(rotation), 
        _property(property){}

void DelayedRotationModel::process(const RotationCue cue, const float dt) {
    if(!cue.is_rotation) return;

    const float err = std::remainder(
        cue.direction_angle - _rotation, 2.0f * Math::PI);;

    const float max_step = _property.w * dt;

    if(std::abs(err) <= max_step)
        _rotation = cue.direction_angle;    
    else
        _rotation += std::copysign(max_step, err);
}