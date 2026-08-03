#ifndef THEMOLLUSK_BODY_H
#define THEMOLLUSK_BODY_H

#include <cmath>
#include <memory>
#include <raylib.h>
#include <raymath.h>

#include "GameObjects/EntityObjects/Type/LivingEntity/LivingEntity.h"

#include "GameObjects/Vector2Source/EntityVector2Source.h"
#include "GameObjects/Vector2Source/MouseVector2Source.h"

#include "Moving/Source/LineMoving/LineMovingCueSource.h"
#include "Moving/Model/FirstOrderMoving/FirstOrderMovingModel.h"

#include "Rotation/Source/MovingDirection/MovingDirectionRotationCueSource.h"
#include "Rotation/Model/RegRotation/RegRotationModel.h"

class Body :
    public LivingEntity
{
public:
    void init(const GameContext& context) override{
        setPosition({0, 0});

        setShape(Shape::Circle{
            .radius = 15.f
        });

        setMovingCueSource(std::make_unique<LineMovingCueSource>(
            std::make_unique<EntityVector2Source>(*this),
            std::make_unique<MouseVector2Source>(context)
        ));
        setMovingModel(std::make_unique<FirstOrderMovingModel>(
            FirstOrderMovingProperty{
                .desired_velocity = 1000,
                .T = 1.f
            }
        ));

        setRotationCueSource(std::make_unique<MovingDirectionRotationCueSource>(
            std::make_unique<EntityVector2Source>(*this)
        ));
        setRotationModel(std::make_unique<RegRotationModel>(
            RegRotationProperty{
                .kp_rot = 10,
                
                .kp_speed = 0.3,
                .ki_speed = 5.f,

                .max_w = 100
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

#endif // !THEMOLLUSK_BODY_H