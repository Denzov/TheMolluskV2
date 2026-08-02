#ifndef _REG_ROTATION_STRATEGY_H_
#define _REG_ROTATION_STRATEGY_H_

#include <algorithm>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "IRotationModel.h"

struct RegRotationProperty {
    const float kp_rot;
    
    const float kp_speed;
    const float ki_speed;

    const float max_w;
};

class RegRotationModel :
    public IRotationModel
{
public:
    RegRotationModel(RegRotationProperty property) :
        _property(property){}

    float process(const RotationCue intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        const Vector2 d = Vector2Subtract(intent.target, base);
        const float target_rot = std::atan2(d.y, d.x);

        const float err_rot = std::remainder(target_rot - rot, 2.0f * PI);
        
        const float P_rot_product = err_rot * _property.kp_rot;
        const float w_target = intent.is_aim?
        std::clamp(
            P_rot_product,
            -_property.max_w,
            _property.max_w
        ) : 0;

        const float err_speed = w_target - _w;

        speed_integrator += err_speed * dt;

        const float P_speed_product = _property.kp_speed * err_speed;
        const float I_speed_product = _property.ki_speed * speed_integrator;

        const float dw = 

        _w = P_speed_product + I_speed_product;
        
        const float da = _w * dt;
        return da;
    }

private:
    RegRotationProperty _property;

    float speed_integrator = 0;
    float _w = 0;
};

#endif // !_REG_ROTATION_STRATEGY_H_