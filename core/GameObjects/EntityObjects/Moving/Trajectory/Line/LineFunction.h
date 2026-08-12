#ifndef THEMOLLUSK_LINE_FUNCTION_H
#define THEMOLLUSK_LINE_FUNCTION_H

#include "../ITrajectoryFunction.h"

#include <cmath>
#include "Math/Constants.h"

class LineFunction:
    public ITrajectoryFunction
{
public:
    Math::Vec2 calculate(const float t) override{
        return {
            .x = t + -0.5f*std::sin(2.f * Math::PI * t),
            .y = -0.3f * std::sin(Math::PI * t) * std::sin(4.f * Math::PI * t)
        };
    }
};

#endif // !THEMOLLUSK_LINE_FUNCTION_H