#ifndef _DIRECT_MOVING_STRATEGY_H_
#define _DIRECT_MOVING_STRATEGY_H_

#include <raylib.h>
#include <raymath.h>

#include "IMovingStrategy.h"

struct DirectMovingProperty{
    const float speed; // [1 / s]
};

class DirectMovingStrategy :
    public IMovingStrategy
{
public:
    DirectMovingStrategy(DirectMovingProperty property) : _property(property){}

    Vector2 process(MovingIntent intent, const float dt) override {
        if(!intent.is_moving) return {};

        const float ds_len = dt * _property.speed;

        const Vector2 ds = {cos(intent.angle), sin(intent.angle)};
        const Vector2 scaled_ds = Vector2Scale(ds, ds_len);

        return scaled_ds;
    }

private:
    const DirectMovingProperty _property;

};

#endif // !_DIRECT_MOVING_STRATEGY_H_