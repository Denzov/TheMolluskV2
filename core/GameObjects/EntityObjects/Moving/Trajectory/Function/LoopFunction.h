#ifndef THEMOLLUSK_LOOP_FUNCTION_H
#define THEMOLLUSK_LOOP_FUNCTION_H

#include "../ITrajectoryFunction.h"

struct LoopFunctionProperty{
    Math::Vec2 anchor;
};

class LoopFunction:
    public ITrajectoryFunction
{
public:
    LoopFunction(LoopFunctionProperty property):
        _property(property){}

    Math::Vec2 calculate(const float t) {
        return {
            t+5.f*t*(1.f-t)*(1.f-2.f * t),
            20.f*t*(1.f-t)*(0.25f-t)*(0.75f-t)
        };
    }

private:
    const LoopFunctionProperty _property;
};

#endif // !THEMOLLUSK_LOOP_FUNCTION_H