#include "EntityVec2Source.h"

#include "GameSystem/GameContext.h"
#include "Base/EntityBase.h"
#include "Moving/Model/MovingModelBase.h"

Math::Vec2 EntityVec2Source::get() const {
    if(const EntityBase* entity = _context.entmanager.getEntity(_source)){
        _source_pos = entity->getMovingModel().getPosition();
    }

    return _source_pos;
}