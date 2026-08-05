#ifndef THEMOLLUSK_BODY_H
#define THEMOLLUSK_BODY_H

#include <cmath>
#include <memory>

#include "GameObjects/EntityObjects/Type/LivingEntity/LivingEntity.h"

#include "GameObjects/Vec2Source/Entity/EntityVec2Source.h"
#include "GameObjects/Vec2Source/Point/PointVec2Source.h"
#include "GameObjects/Vec2Source/Mouse/MouseVec2Source.h"

#include "Moving/Source/PatrolMoving/PatrolMovingCueSource.h"
#include "Moving/Model/FirstOrderMoving/FirstOrderMovingModel.h"

#include "Rotation/Source/MovingDirection/MovingDirectionRotationCueSource.h"
#include "Rotation/Source/Vec2Rotation/Vec2RotationCueSource.h"
#include "Rotation/Model/RegRotation/RegRotationModel.h"

#include "Math/MathRaylibConverter.h"

#include "Common.h"

class Body :
    public LivingEntity
{
public:
    void init(const GameContext& context) override{
        setMaxHp(100);
        takeHp(100);

        setPosition({0, 0});

        setShape(Shape::Circle{
            .radius = 15.f
        });

        setMovingCueSource(std::make_unique<PatrolMovingCueSource>(
            200,
            std::make_unique<EntityVec2Source>(
                context,
                getHandle()),
            make_unique_vector<IVec2Source>(
                std::make_unique<PointVec2Source>(
                    Math::Vec2{0, 0}),
                std::make_unique<PointVec2Source>(
                    Math::Vec2{50000, 0}),
                std::make_unique<PointVec2Source>(
                    Math::Vec2{0, -50000}),
                std::make_unique<PointVec2Source>(
                    Math::Vec2{-50000, 0}),
                std::make_unique<PointVec2Source>(
                    Math::Vec2{0, 50000})
            )
        ));
        setMovingModel(std::make_unique<FirstOrderMovingModel>(
            FirstOrderMovingProperty{
                .desired_velocity = 3000,
                .T = 1.5f
            }
        ));

        setRotationCueSource(std::make_unique<MovingDirectionRotationCueSource>(
            std::make_unique<EntityVec2Source>(
                context,
                getHandle())
        ));
        setRotationModel(std::make_unique<RegRotationModel>(
            RegRotationProperty{
                .kp_rot = 10,
                
                .kp_speed = 0.5,
                .ki_speed = 3.f,

                .max_w = 100
            }
        ));
    }

    void draw() const override{
        const Math::Vec2 pos = getPosition();
        const Shape::Variant form = getShape();
        Shape::draw(form, pos, RED);

        const float rot = getRotation();
        const Math::Vec2 rot_vec = {.x = std::cos(rot), .y = std::sin(rot)};
        const Math::Vec2 scale_rot_vec = rot_vec * 100;
        const Math::Vec2 b_add = {scale_rot_vec.x + pos.x, scale_rot_vec.y + pos.y};
        DrawLineV(toRaylib(pos), toRaylib(b_add), WHITE);
    }

    void update(const GameContext& constext) override{

    }
};

#endif // !THEMOLLUSK_BODY_H