#ifndef THEMOLLUSK_I_VECTOR2_SOURCE_H
#define THEMOLLUSK_I_VECTOR2_SOURCE_H

#include "Math/Vec2.h"

class IVec2Source {
public:
    virtual ~IVec2Source() = default;
    virtual Math::Vec2 get() const = 0;
};

#endif // !THEMOLLUSK_I_VECTOR2_SOURCE_H