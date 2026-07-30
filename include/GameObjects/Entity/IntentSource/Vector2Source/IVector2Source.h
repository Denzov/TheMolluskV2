#ifndef _I_VECTOR2_SOURCE_H_
#define _I_VECTOR2_SOURCE_H_

#include <raylib.h>

class IVector2Source {
public:
    virtual ~IVector2Source() = default;
    virtual Vector2 get() const = 0;
};

#endif // !_I_VECTOR2_SOURCE_H_