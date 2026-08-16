#ifndef THEMOLLUSK_SQUARE_FUNCTION_H
#define THEMOLLUSK_SQUARE_FUNCTION_H

#include "../ITrajectoryFunction.h"

struct SquareFunctionProperty{
    const float amplitude;
};

class SquareFunction:
    public ITrajectoryFunction
{
public:
    SquareFunction(SquareFunctionProperty property):
        _property(property){}

    Math::Vec2 calculate(const float t) override{
        return {
            .x = t,
            .y = t * (t-1) * _property.amplitude
        };
    }

private:
    const SquareFunctionProperty _property;
};

#endif // !THEMOLLUSK_SQUARE_FUNCTION_H