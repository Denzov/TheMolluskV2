#ifndef _PI_REG_ROTATION_STRATEGY_H_
#define _PI_REG_ROTATION_STRATEGY_H_

#include <algorithm>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "IRotationStrategy.h"

struct PIRegRotationProperty{
    const float kp;
    const float ki;
    const float max_w;
};

class PIRegRotationStrategy : 
    public IRotationStrategy
{
public:
    PIRegRotationStrategy(PIRegRotationProperty property) :
        _property(property){}

    float process(const AimIntent intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        if(!intent.is_aim) return 0;

        const Vector2 d = Vector2Subtract(intent.target, base);
        const float target_rot = std::atan2(d.y, d.x);

        const float err = std::remainder(target_rot - rot, 2.0f * PI);;

        const float P = err * _property.kp;
        const float I = integrator;

        const float u = P + I;

        if(abs(u) < _property.max_w){
            integrator += err * dt * _property.ki;
        }

        const float w = std::clamp(
            u,
            -_property.max_w,
            _property.max_w
        );
        const float da = w * dt;

        return da;
    }

private:
    const PIRegRotationProperty _property;
    float integrator = 0;
};

#endif // !_PI_REG_ROTATION_STRATEGY_H_