#include "RegRotationModel.h"

#include <algorithm>
#include <raymath.h>
#include <cmath>

float RegRotationModel::process(const RotationCue cue, 
              const Vector2 base, 
              const float rot, const float dt)
{
    const Vector2 d = Vector2Subtract(cue.target, base);
    const float target_rot = std::atan2(d.y, d.x);

    const float err_rot = std::remainder(target_rot - rot, 2.0f * PI);
    
    const float P_rot_product = err_rot * _property.kp_rot;
    const float w_target = cue.is_rotation?
        std::clamp(
            P_rot_product,
            -_property.max_w, _property.max_w
        ) : 0;

    const float err_speed = w_target - _w;

    _speed_integrator += err_speed * dt;

    const float P_speed_product = _property.kp_speed * err_speed;
    const float I_speed_product = _property.ki_speed * _speed_integrator;

    _w = P_speed_product + I_speed_product;
    
    const float da = _w * dt;
    return da;
}