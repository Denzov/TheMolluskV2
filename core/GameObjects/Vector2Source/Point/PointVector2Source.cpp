#include "PointVector2Source.h"

PointVector2Source::PointVector2Source(const Vector2 source) :
    _source(source) {}

Vector2 PointVector2Source::get() const {
    return _source;
}