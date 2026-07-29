#ifndef _INSTA_ROTATION_STRATEGY_H_
#define _INSTA_ROTATION_STRATEGY_H_

#include <raylib.h>
#include <cmath>

#include "IRotationStrategy.h"

class InstaRotationStrategy :
    public IRotationStrategy
{
public:

    float process(const AimIntent intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        if(!intent.target_valid) return 0;

        const Vector2 abs_target = {
            .x = intent.target.x - base.x,
            .y = intent.target.y - base.y
        };

        const float target_rot = std::atan2(abs_target.y, abs_target.x);
        const float err = std::remainder(target_rot - rot, 2.0f * PI);;

        return err;
    }
};

#endif // !_INSTA_ROTATION_STRATEGY_H_