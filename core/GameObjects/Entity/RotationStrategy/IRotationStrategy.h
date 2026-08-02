#ifndef _I_ROTATION_STRATEGY_H_
#define _I_ROTATION_STRATEGY_H_

#include "../Intent/AimIntent.h"

class IRotationStrategy {
public:
    virtual ~IRotationStrategy() = default;

    virtual float process(AimIntent, Vector2 base, const float rot, const float dt) = 0;
};

#endif // !_I_ROTATION_STRATEGY_H_