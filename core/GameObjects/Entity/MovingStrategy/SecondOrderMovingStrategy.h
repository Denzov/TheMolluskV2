#ifndef _SECOND_ORDER_MOVING_STRATEGY_H_
#define _SECOND_ORDER_MOVING_STRATEGY_H_

#include <cmath>

#include <raylib.h>
#include <raymath.h>

#include "IMovingStrategy.h"

struct SecondOrderMovingProperty{
    const float desired_velocity;
    const float frequency;   // Hz
    const float damping;     // ζ
};

class SecondOrderMovingStrategy :
    public IMovingStrategy
{
public:
    SecondOrderMovingStrategy(
        SecondOrderMovingProperty property) :
        _property(property){}

    Vector2 process(MovingIntent intent,
                    const float dt) override
    {
        Vector2 target_velocity{};

        if(intent.is_moving){
            target_velocity = {
                std::cos(intent.angle) * _property.desired_velocity,
                std::sin(intent.angle) * _property.desired_velocity
            };
        }

        const float w = 2.f * PI * _property.frequency;

        const Vector2 accel =
            Vector2Subtract(
                Vector2Scale(
                    Vector2Subtract(target_velocity, _velocity),
                    w * w
                ),
                Vector2Scale(
                    _velocity,
                    2.f * _property.damping * w
                )
            );

        _velocity = Vector2Add(
            _velocity,
            Vector2Scale(accel, dt)
        );

        return Vector2Scale(_velocity, dt);
    }

private:
    const SecondOrderMovingProperty _property;

    Vector2 _velocity{};
};

#endif // !_SECOND_ORDER_MOVING_STRATEGY_H_