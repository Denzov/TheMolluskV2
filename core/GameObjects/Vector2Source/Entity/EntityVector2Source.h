#ifndef THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H
#define THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H

#include "../IVector2Source.h"

#include "EntityManager/EntityManager.h"

class EntityVector2Source :
    public IVector2Source
{
public:
    EntityVector2Source(
        const EntityManager& entmanager,
        const EntityHandle& source) :
            _entmanager(entmanager),
            _source(source){}

    Vector2 get() const override;

private:
    mutable Vector2 _last_source_pos = {};
    const EntityManager& _entmanager;
    const EntityHandle _source;
};

#endif // !THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H