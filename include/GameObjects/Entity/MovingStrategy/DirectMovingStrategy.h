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
        const Vector2 ds = {
            .x = static_cast<float>(intent.move_west.status - intent.move_west.status),
            .y = static_cast<float>(intent.move_north.status - intent.move_south.status)
        };

        const float ds_len = dt * _property.speed;

        const Vector2 normalize_ds = Vector2Normalize(ds);
        const Vector2 scaled_ds = Vector2Scale(normalize_ds, ds_len);

        return scaled_ds;
    }

private:
    const DirectMovingProperty _property;

};

#endif // !_DIRECT_MOVING_STRATEGY_H_