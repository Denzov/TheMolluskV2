#ifndef THEMOLLUSK_I_TRAJECTORY_FUNCTION_H
#define THEMOLLUSK_I_TRAJECTORY_FUNCTION_H

#include "Math/Vec2.h"

class ITrajectoryFunction{
public:
    virtual ~ITrajectoryFunction() = default;
    virtual Math::Vec2 calculate(const float t) = 0;
};

#endif // !THEMOLLUSK_I_TRAJECTORY_FUNCTION_H