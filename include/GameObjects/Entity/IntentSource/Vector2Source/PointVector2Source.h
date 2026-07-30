#ifndef _POINT_VECTOR2_SOURCE_H_
#define _POINT_VECTOR2_SOURCE_H_

#include "IVector2Source.h"

class PointVector2Source :
    public IVector2Source
{
public:
    PointVector2Source(const Vector2 source) :
        _source(source) {}

    Vector2 get() const override {
        return _source;
    }

private:
    const Vector2 _source;
};

#endif // !_POINT_VECTOR2_SOURCE_H_