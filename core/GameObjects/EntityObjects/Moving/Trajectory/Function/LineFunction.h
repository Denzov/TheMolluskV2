#ifndef THEMOLLUSK_LINE_FUNCTION_H
#define THEMOLLUSK_LINE_FUNCTION_H

#include "../ITrajectoryFunction.h"

class LineFunction:
    public ITrajectoryFunction
{
public:
    Math::Vec2 calculate(const float t) override{
        return {
            .x = t,
            .y = 0.f
        };
    }
};

#endif // !THEMOLLUSK_LINE_FUNCTION_H