#ifndef THEMOLLUSK_POINT_VECTOR2_SOURCE_H
#define THEMOLLUSK_POINT_VECTOR2_SOURCE_H

#include "../IVec2Source.h"

class PointVec2Source :
    public IVec2Source
{
public:
    PointVec2Source(const Math::Vec2 source);
    Math::Vec2 get() const override;

private:
    const Math::Vec2 _source;
};

#endif // !THEMOLLUSK_POINT_VECTOR2_SOURCE_H