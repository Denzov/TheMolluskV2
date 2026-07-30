#ifndef _BODY_H_
#define _BODY_H_

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

#include "../../MovingStrategy/FirstOrderMovingStrategy.h"
#include "../../MovingStrategy/SecondOrderMovingStrategy.h"
#include "../../IntentSource/Moving/LineTargetMovingIntentSource.h"
#include "../../IntentSource/Moving/KeyboardMovingIntentSource.h"

#include "../../IntentSource/Aim/MouseAimIntentSource.h"
#include "../../RotationStrategy/PIRegRotationStrategy.h"

#include "../../IntentSource/Vector2Source/EntityVector2Source.h"
#include "../../IntentSource/Vector2Source/MouseVector2Source.h"

#include "../../EntityType/LivingEntity.h"

class Body :
    public LivingEntity
{
public:
    void init(const GameContext& context) override{
        setPosition({0, 0});

        setShape(Shape::Circle{
            .radius = 15.f
        });

        setMovingIntentSource(std::make_unique<LineMovingIntentSource>(
            std::make_unique<EntityVector2Source>(*this), 
            std::make_unique<MouseVector2Source>(context)
        ));

        setMovingStrategy(std::make_unique<FirstOrderMovingStrategy>(
            FirstOrderMovingProperty{
                .desired_velocity = 100,
                .T = 0.3
            }
        ));

        setAimIntentSource(std::make_unique<MouseAimIntentSource>(context));
        setRotationStrategy(std::make_unique<PIRegRotationStrategy>(
            PIRegRotationProperty{
                .kp = 4, 
                .ki = 14.0, 
                .max_w = 10 
            }
        ));
    }

    void draw() const override{
        const Vector2 pos = getPosition();
        const Shape::Variant form = getShape();
        Shape::draw(form, pos, RED);

        const float rot = getRotation();
        const Vector2 rot_vec = {.x = cos(rot), .y = sin(rot)};
        const Vector2 scale_rot_vec = Vector2Scale(rot_vec, 100);
        const Vector2 b_add = {scale_rot_vec.x + pos.x, scale_rot_vec.y + pos.y};
        DrawLineV(pos, b_add, WHITE);
    }

    void update(const GameContext& constext) override{

    }
};

#endif // !_BODY_H_