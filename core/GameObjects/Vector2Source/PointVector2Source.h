#ifndef THEMOLLUSK_POINT_VECTOR2_SOURCE_H
#define THEMOLLUSK_POINT_VECTOR2_SOURCE_H

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

#endif // !THEMOLLUSK_POINT_VECTOR2_SOURCE_H