#ifndef THEMOLLUSK_TRAJECTORY_H
#define THEMOLLUSK_TRAJECTORY_H

#include <memory>
#include "Math/Vec2.h"

class ITrajectoryFunction;
class IVec2Source;

struct TrajectoryProperty{
    const float reach_radius;
    const float skin_threshold_ratio;
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<ITrajectoryFunction> updater;
};

class Trajectory
{
public:    
    Trajectory(
        TrajectoryProperty property);     
    
    void consume(Math::Vec2 start,
                 Math::Vec2 end);
                 
    void reload(Math::Vec2 start,
                Math::Vec2 end);
                
    float getDirectionAngle() const;
    Math::Vec2 getBase() const;
    
    bool isEnd() const;

private:
    void _increment();
    void _on_position_change(Math::Vec2 start_pos, Math::Vec2 end_pos);
    void _calc_target(Math::Vec2 start_pos);

private:
    static constexpr float _normalized_start = 0.f;
    static constexpr float _normalized_end = 1.f;
    static constexpr float _inc_step = 100.f;
        
    Math::Vec2 _point0 = {};
    Math::Vec2 _target = {};

    Math::Vec2 _end_snapshot = {};
    Math::Vec2 _start_snapshot = {};
    
    float _t = 0;

    float _scale = 0;
    float _rot_sin_product = 0;
    float _rot_cos_product = 0;

    float _normalized_inc = 1.f;

    bool _is_end = false;

    TrajectoryProperty _property;
};

#endif // !THEMOLLUSK_TRAJECTORY_H