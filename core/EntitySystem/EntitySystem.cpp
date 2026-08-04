#include "EntitySystem.h"

#include "EntityManager/EntityManager.h"
#include "GameSystem/GameContext.h"

void EntitySystem::update(EntityManager& entmanager, GameContext& context){
    entmanager.forEach([&](EntityBase& e){
        e._internal_update(context);
    });
}

void EntitySystem::draw(EntityManager& entmanager) const {
    entmanager.forEach([&](EntityBase& e){
        e.draw();
    });
}

void EntitySystem::cleanup(EntityManager& entmanager){
    std::vector<EntityHandle> dead;

    entmanager.forEach([&](EntityBase& e){        
        if(!e.isAlive())
            entmanager.destroyEntity(e.getHandle());
    });
}