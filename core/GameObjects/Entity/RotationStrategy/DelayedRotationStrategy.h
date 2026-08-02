#ifndef _DELAYED_ROTATION_STRATEGY_H_
#define _DELAYED_ROTATION_STRATEGY_H_

#include <raylib.h>
#include <cmath>

#include "IRotationStrategy.h"

struct DelayedRotationProperty{
    const float w;
};

class DelayedRotationStrategy :
    public IRotationStrategy
{
public:
    DelayedRotationStrategy(DelayedRotationProperty propery) : 
        _property(propery){}

    float process(const AimIntent intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        if(!intent.is_aim) return 0;

        const Vector2 abs_target = {
            .x = intent.target.x - base.x,
            .y = intent.target.y - base.y
        };

        const float target_rot = std::atan2(abs_target.y, abs_target.x);
        const float err = std::remainder(target_rot - rot, 2.0f * PI);;

        const float max_step = _property.w * dt;

        if (std::abs(err) <= max_step)
            return err;

        return std::copysign(max_step, err);
    }

private:
    const DelayedRotationProperty _property;
};

#endif // !_DELAYED_ROTATION_STRATEGY_H_