#include "EntityVector2Source.h"

#include "Base/EntityBase.h"

Vector2 EntityVector2Source::get() const {
    if(const EntityBase* entity = _entmanager.getEntity(_source)){
        _last_source_pos = entity->getPosition();
    }

    return _last_source_pos;
}