#ifndef THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H
#define THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H

#include "../IVec2Source.h"

#include "EntityManager/EntityHandle.h"

class GameContext;

class EntityVec2Source :
    public IVec2Source
{
public:
    EntityVec2Source(
        const GameContext& context,
        const EntityHandle& source) :
            _context(context),
            _source(source){}

    Math::Vec2 get() const override;

private:
    mutable Math::Vec2 _last_source_pos = {};
    const GameContext& _context;
    const EntityHandle _source;
};

#endif // !THEMOLLUSK_ENTITY_VECTOR2_SOURCE_H