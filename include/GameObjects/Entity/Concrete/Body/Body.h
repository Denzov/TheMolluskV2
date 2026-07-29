#ifndef _BODY_H_
#define _BODY_H_

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

#include "../../MovingStrategy/DirectMovingStrategy.h"
#include "../../IntentSource/Moving/KeyboardMovingIntentSource.h"

#include "../../IntentSource/Aim/MouseAimIntentSource.h"
#include "../../RotationStrategy/DelayedRotationStrategy.h"
#include "../../RotationStrategy/PRegRotationStrategy.h"
#include "../../RotationStrategy/PIRegRotationStrategy.h"
#include "../../RotationStrategy/InstaRotationStrategy.h"


#include "../../EntityType/LivingEntity.h"

class Body :
    public LivingEntity
{
public:
    void init(const GameContext& context) override{
        setPosition({0, 0});

        Shape::Circle shape {.radius = 15};
        setShape(shape);

        setMovingIntentSource(std::make_unique<KeyboardMovingIntentSource>());

        DirectMovingProperty moving_property {.speed = 1000 };
        setMovingStrategy(std::make_unique<DirectMovingStrategy>(moving_property));

        setAimIntentSource(std::make_unique<MouseAimIntentSource>(context));

        DelayedRotationProperty rotation_property {.w = 100 };
        setRotationStrategy(std::make_unique<DelayedRotationStrategy>(rotation_property));

        PRegRotationProperty preg1 {.kp = 10, .max_w = 100};
        setRotationStrategy(std::make_unique<PRegRotationStrategy>(preg1));
        
        PIRegRotationProperty preg2 {.kp = 4, .ki = 14.0, .max_w = 10 };
        setRotationStrategy(std::make_unique<PIRegRotationStrategy>(preg2));

        // setRotationStrategy(std::make_unique<InstaRotationStrategy>());
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

    void update(const GameContext& constext, const float dt) override{

    }
};

#endif // !_BODY_H_