#ifndef THEMOLLUSK_I_TRAJECTORY_H
#define THEMOLLUSK_I_TRAJECTORY_H

#include <memory>

#include "GameObjects/Vec2Source/IVec2Source.h"

class ITrajectoryFunction;

class TrajectoryBase{
public:
    virtual ~TrajectoryBase();
    
    TrajectoryBase(
        const float reach_radius,
        std::unique_ptr<IVec2Source> base,
        std::unique_ptr<IVec2Source> end,
        std::unique_ptr<ITrajectoryFunction> updater);

    void consume();
    float getDirectionAngle();
    bool isEnd();    

protected:
    static constexpr float _normalized_start = 0;
    static constexpr float _normalized_end = 1;

    const float _reach_radius;

    const Math::Vec2 _start;

    Math::Vec2 _target;

    std::unique_ptr<IVec2Source> _base;
    std::unique_ptr<IVec2Source> _end;

private:
    void _increment();

private:
    static constexpr float _normalized_inc = 0.01;
    float _t = 0;

    std::unique_ptr<ITrajectoryFunction> _updater;
};

#endif // !THEMOLLUSK_I_TRAJECTORY_H