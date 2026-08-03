#ifndef THEMOLLUSK_I_VECTOR2_SOURCE_H
#define THEMOLLUSK_I_VECTOR2_SOURCE_H

#include <raylib.h>

class IVector2Source {
public:
    virtual ~IVector2Source() = default;
    virtual Vector2 get() const = 0;
};

#endif // !THEMOLLUSK_I_VECTOR2_SOURCE_H