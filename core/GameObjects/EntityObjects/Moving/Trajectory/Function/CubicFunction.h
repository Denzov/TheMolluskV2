#ifndef THEMOLLUSK_CUBIC_FUNCTION_H
#define THEMOLLUSK_CUBIC_FUNCTION_H

#include "../ITrajectoryFunction.h"

#include "Math/Vec2.h"

struct CubicFunctionProperty{
    const Math::Vec2 anchor;
};

class CubicFunction:
    public ITrajectoryFunction
{
public:
    CubicFunction(CubicFunctionProperty property):
        _property(property){}

    Math::Vec2 calculate(const float t) override{
        return {
            .x = t,
            .y = t * (t-1) * (t-_property.anchor.x) * _property.anchor.y
        };
    }

private:
    CubicFunctionProperty _property;
};

#endif // !THEMOLLUSK_CUBIC_FUNCTION_H