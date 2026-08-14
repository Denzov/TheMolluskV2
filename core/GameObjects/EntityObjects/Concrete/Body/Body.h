#ifndef THEMOLLUSK_BODY_H
#define THEMOLLUSK_BODY_H

#include <cmath>
#include <memory>

#include "GameSystem/GameContext.h"
#include "GameObjects/EntityObjects/Type/LivingEntity/LivingEntity.h"

#include "GameObjects/Vec2Source/Entity/EntityVec2Source.h"
#include "GameObjects/Vec2Source/Point/PointVec2Source.h"
#include "GameObjects/Vec2Source/Mouse/MouseVec2Source.h"

#include "Moving/Source/TargetMoving/TargetMovingCueSource.h"
#include "Moving/Trajectory/Mere/MereTrajectory.h"
#include "Moving/Trajectory/Function/LineFunction.h"
#include "Moving/Trajectory/Function/CubicFunction.h"
#include "Moving/Trajectory/Function/SquareFunction.h"
#include "Moving/Trajectory/Tricky/TrickyTrajectory.h"
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

        getShapeCluster().add(Shape::ClusterNode{
            .shape = Shape::Circle{
                .radius = 30
            },
            .anchor = {0, 0}
        });

        setMovingModel(
			std::make_unique<FirstOrderMovingModel>(
				// Math::Vec2{
	            //     .x = (float)GetRandomValue(-15000, 15000) / 100.f + 
		        //         GetScreenToWorld2D(GetMousePosition(), context.camera.getData()).x, 
	            //     .y = (float)GetRandomValue(-15000, 15000) / 100.f +
		        //         GetScreenToWorld2D(GetMousePosition(), context.camera.getData()).y
                // },
                Math::Vec2{
                    .x = (float)GetRandomValue(-15000, 15000) / 100.f, 
                    .y = (float)GetRandomValue(-15000, 15000) / 100.f
                },
				FirstOrderMovingProperty
				{
					.desired_velocity = (float)GetRandomValue(4000, 7000),
					.T = (float)GetRandomValue(1, 2500) / 1000.f
				}
			)
		);
        setMovingCueSource(std::make_unique<TargetMovingCueSource>(
            std::make_unique<TrickyTrajectory>(
                TrickyTrajectoryProperty{
                    .reach_radius = 500,
                    .skin_threshold_ratio = 0.5,
                    .base = std::make_unique<EntityVec2Source>(
                        context,
                        getHandle()),
                    .start = std::make_unique<PointVec2Source>(
                        getMovingModel().getPosition()),
                    .end = std::make_unique<MouseVec2Source>(
                        context),
                    .updater = std::make_unique<CubicFunction>(
                        CubicFunctionProperty{
                            .anchor = Math::Vec2{
                                0.5f, 5.f}
                        }
                    )
                }
            )
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
        const Shape::Cluster& form = getShapeCluster();

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