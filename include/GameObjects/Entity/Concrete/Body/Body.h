#ifndef _BODY_H_
#define _BODY_H_

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

#include "../../MovingStrategy/FirstOrderMovingStrategy.h"
#include "../../MovingStrategy/SecondOrderMovingStrategy.h"

#include "../../IntentSource/Moving/LineMovingIntentSource.h"
#include "../../IntentSource/Moving/KeyboardMovingIntentSource.h"


#include "../../IntentSource/Aim/MouseAimIntentSource.h"
#include "../../IntentSource/Aim/MovingDirectionAimIntentSource.h"

#include "../../RotationStrategy/InstaRotationStrategy.h"
#include "../../RotationStrategy/PIRegRotationStrategy.h"
#include "../../RotationStrategy/PRegRotationStrategy.h"
#include "../../RotationStrategy/RegRotationStrategy.h"
#include "../../RotationStrategy/DelayedRotationStrategy.h"


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

        // setMovingIntentSource(std::make_unique<LineMovingIntentSource>(
        //     std::make_unique<EntityVector2Source>(*this),
        //     std::make_unique<MouseVector2Source>(context)
        // ));
        setMovingIntentSource(std::make_unique<KeyboardMovingIntentSource>());

        // setMovingStrategy(std::unique_ptr<IMovingStrategy> strategy)
        setMovingStrategy(std::make_unique<FirstOrderMovingStrategy>(
            FirstOrderMovingProperty{
                .desired_velocity = 1000,
                .T = 1.f
            }
        ));

        setAimIntentSource(std::make_unique<MovingDirectionAimIntentSource>(
            std::make_unique<EntityVector2Source>(*this)
        ));
        // setRotationStrategy(std::make_unique<DelayedRotationStrategy>(
        //     DelayedRotationProperty{
        //         .w = 10
        //     }
        // ));
        setRotationStrategy(std::make_unique<RegRotationStrategy>(
            RegRotationProperty{
                .kp_rot = 10,
                
                .kp_speed = 0.1,
                .ki_speed = 1.f,

                .max_w = 3
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