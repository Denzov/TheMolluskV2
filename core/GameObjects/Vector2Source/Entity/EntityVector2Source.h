#ifndef THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H
#define THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H

#include "../IVector2Source.h"

#include "EntityManager/EntityHandle.h"

class GameContext;

class EntityVector2Source :
    public IVector2Source
{
public:
    EntityVector2Source(
        const GameContext& context,
        const EntityHandle& source) :
            _context(context),
            _source(source){}

    Vector2 get() const override;

private:
    mutable Vector2 _last_source_pos = {};
    const GameContext& _context;
    const EntityHandle _source;
};

#endif // !THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H