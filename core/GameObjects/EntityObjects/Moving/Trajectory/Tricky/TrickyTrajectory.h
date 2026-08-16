#ifndef THEMOLLUSK_TRICKY_TRAJECTORY_H
#define THEMOLLUSK_TRICKY_TRAJECTORY_H

#include "../ITrajectory.h"

#include <memory>
#include "Math/Vec2.h"

class ITrajectoryFunction;
class IVec2Source;

struct TrickyTrajectoryProperty{
    const float reach_radius;
    const float skin_threshold_ratio;
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<IVec2Source> start;
    std::unique_ptr<IVec2Source> end;
    std::unique_ptr<ITrajectoryFunction> updater;
};

class TrickyTrajectory: 
    public ITrajectory
{
public:    
    TrickyTrajectory(
        TrickyTrajectoryProperty property);        

    void consume() override;
    float getDirectionAngle() const override;
    bool isEnd() const override;    

private:
    void _increment();
    void _on_position_change(Math::Vec2 start_pos, Math::Vec2 end_pos);
    void _calc_target(Math::Vec2 start_pos);

private:
    static constexpr float _normalized_start = 0;
    static constexpr float _normalized_end = 1;
    static constexpr float _inc_step = 100;
        
    Math::Vec2 _point0 = {};
    Math::Vec2 _target = {};

    Math::Vec2 _end_snapshot = {};
    Math::Vec2 _start_snapshot = {};
    
    float _t = 0;

    float _scale = 0;
    float _rot_sin_product = 0;
    float _rot_cos_product = 0;

    float _normalized_inc = 0.01;

    bool _is_end = false;

    TrickyTrajectoryProperty _property;
};

#endif // !THEMOLLUSK_I_TRAJECTORY_H