#ifndef _P_REG_ROTATION_STRATEGY_H_
#define _P_REG_ROTATION_STRATEGY_H_

#include <algorithm>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "IRotationStrategy.h"

struct PRegRotationProperty{
    const float kp;
    const float max_w;
};

class PRegRotationStrategy : 
    public IRotationStrategy
{
public:
    PRegRotationStrategy(PRegRotationProperty property) :
        _property(property){}

    float process(const AimIntent intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        if(!intent.is_aim) return 0;

        const Vector2 d = Vector2Subtract(intent.target, base);
        const float target_rot = std::atan2(d.y, d.x);

        const float err = std::remainder(target_rot - rot, 2.0f * PI);

        const float P = err * _property.kp;

        const float u = P;
        const float w = std::clamp(
            u,
            -_property.max_w,
            _property.max_w
        );
        const float da = w * dt;

        return da;
    }

private:
    const PRegRotationProperty _property;
};

#endif // !_P_REG_ROTATION_STRATEGY_H_