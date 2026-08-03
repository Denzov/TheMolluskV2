#ifndef _ENTITY_VECTOR2_SOURCE_H_
#define _ENTITY_VECTOR2_SOURCE_H_

#include "IVector2Source.h"

#include "GameObjects/EntityObjects/Base/EntityBase.h"

class EntityVector2Source :
    public IVector2Source
{
public:
    EntityVector2Source(const EntityBase& source) :
        _source(source) {}

    Vector2 get() const override{
        return _source.getPosition();
    }

private:
    const EntityBase& _source;
};

#endif // !_ENTITY_VECTOR2_SOURCE_H_