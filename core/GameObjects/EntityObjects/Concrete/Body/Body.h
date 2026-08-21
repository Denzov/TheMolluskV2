#ifndef THEMOLLUSK_BODY_H
#define THEMOLLUSK_BODY_H

#include <cmath>
#include <memory>

#include "GameSystem/GameContext.h"
#include "GameObjects/EntityObjects/Type/LivingEntity/LivingEntity.h"

#include "GameObjects/Vec2Source/Entity/EntityVec2Source.h"
#include "GameObjects/Vec2Source/Point/PointVec2Source.h"
#include "GameObjects/Vec2Source/Mouse/MouseVec2Source.h"

#include "Moving/Source/TargetMoving/TrickyTargetMovingCueSource.h"
#include "Moving/Trajectory/Function/LineFunction.h"
#include "Moving/Trajectory/Function/CubicFunction.h"
#include "Moving/Trajectory/Function/SquareFunction.h"
#include "Moving/Trajectory/Function/LoopFunction.h"
#include "Moving/Source/PatrolMoving/TrickyPatrolMovingCueSource.h"
#include "Moving/Model/FirstOrderMoving/FirstOrderMovingModel.h"
#include "Moving/Model/DirectMoving/DirectMovingModel.h"


#include "Rotation/Source/MovingDirection/MovingDirectionRotationCueSource.h"
#include "Rotation/Source/Vec2Rotation/Vec2RotationCueSource.h"
#include "Rotation/Model/RegRotation/RegRotationModel.h"

#include "Math/MathRaylibConverter.h"

#include "Common.h"

class Body :
    public LivingEntity
{
public:
    void init(const GameContext& context) override {
        setMaxHp(100);
        takeHp(100);

        getCollider().add(Shape::ClusterNode{
            .shape = Shape::Circle{
                .radius = 30
            },
            .anchor = {0, 0}
        });

        setMovingModel(
            std::make_unique<FirstOrderMovingModel>(
                Math::Vec2{
                    .x = (float)GetRandomValue(-15000, 15000) / 100.f, 
                    .y = (float)GetRandomValue(-15000, 15000) / 100.f
                },
                FirstOrderMovingProperty
                {
                    .desired_velocity = (float)GetRandomValue(3000, 5000),
                    .T = (float)GetRandomValue(200, 400) / 1000.f
                }
            )
        );

        setMovingCueSource(std::make_unique<TrickyPatrolMovingCueSource>(
            TrickyPatrolMovingCueProperty{
                .waypoints = make_vector<PatrolWaypoint>(
                    PatrolWaypoint{
                        .source = std::make_unique<PointVec2Source>(
                            Math::Vec2{0, 0}),
                        .reach_radius = 1000
                    },
                    PatrolWaypoint{
                        .source = std::make_unique<PointVec2Source>(
                            Math::Vec2{5000, std::sqrt(3.f) / 2 * 10000.f}),
                        .reach_radius = 1000
                    },
                    PatrolWaypoint{
                        .source = std::make_unique<PointVec2Source>(
                            Math::Vec2{10000, 0}),
                        .reach_radius = 1000
                    }
                ),
                .trajectory = Trajectory(
                    TrajectoryProperty{
                        .reach_radius = 300.f,
                        .skin_threshold_ratio = 0.5f,
                        .base = std::make_unique<EntityVec2Source>(
                            context,
                            getHandle()),
                        .updater = std::make_unique<SquareFunction>(
                            SquareFunctionProperty{
                                .amplitude = -0.5f
                            }
                        )
                    }
                )
            }   
        ));
         
        setRotationCueSource(std::make_unique<MovingDirectionRotationCueSource>(
            MovingDirectionRotationCueProperty{
                .base = std::make_unique<EntityVec2Source>(
                    context, 
                    getHandle()
                )
            }
        ));
        setRotationModel(std::make_unique<RegRotationModel>(
            0, 
            RegRotationProperty{
                .kp_rot = 10,
                
                .kp_speed = 0.5,
                .ki_speed = 3.f,

                .max_w = 100
            }
        ));
    }

    void draw() const override{
        const Math::Vec2 pos = getMovingModel().getPosition();
        const Shape::Cluster& form = getCollider();

        for(const auto& node : form.getNodes()){
            Shape::draw(node.shape, pos + node.anchor, RED);
        }

        const float rot = getRotationModel().getRotation();
        const Math::Vec2 rot_vec = {.x = std::cos(rot), .y = std::sin(rot)};
        const Math::Vec2 scale_rot_vec = rot_vec * 130;
        const Math::Vec2 b_add = {scale_rot_vec.x + pos.x, scale_rot_vec.y + pos.y};

        DrawLineEx(toRaylib(pos), toRaylib(b_add), 20, RED);
    }

    void update(const GameContext& constext) override{

    }
};

#endif // !THEMOLLUSK_BODY_H