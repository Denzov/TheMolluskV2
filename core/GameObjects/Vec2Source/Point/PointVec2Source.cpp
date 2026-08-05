#include "PointVec2Source.h"

PointVec2Source::PointVec2Source(const Math::Vec2 source) :
    _source(source) {}

Math::Vec2 PointVec2Source::get() const {
    return _source;
}