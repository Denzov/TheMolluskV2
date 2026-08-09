#include "EntityManager.h"

EntityManager::~EntityManager() = default;

void EntityManager::destroyEntity(EntityHandle handle) {
    if(EntityBase* ent = getEntity(handle)){
        auto& slot = _slots[handle.index];
        slot.is_active = false;
        slot.entity.reset();
        slot.generation++;

        _free_indices.push_back(handle.index);
    }
}

EntityBase* EntityManager::getEntity(EntityHandle handle) const {
    if(handle.index >= _slots.size()) return nullptr;

    const auto& slot = _slots[handle.index];

    if(slot.is_active && slot.generation == handle.generation)
        return slot.entity.get();

    return nullptr;
}

size_t EntityManager::getSlotsSize(){
    return _slots.size();
}


EntityManager::Slot::Slot() = default;
EntityManager::Slot::~Slot() = default;
EntityManager::Slot::Slot(Slot&& other) noexcept = default;
EntityManager::Slot& EntityManager::Slot::operator=(Slot&& other) noexcept = default;