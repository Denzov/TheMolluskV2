#ifndef THEMOLLUSK_ENTITY_MANAGER_H
#define THEMOLLUSK_ENTITY_MANAGER_H

#include "EntityHandle.h"
#include "Base/EntityBase.h"

#include <raylib.h>

#include <vector>

#include <stdint.h>
#include <memory>

class EntityManager{
public:
    template<typename T, typename... Args>
    EntityHandle spawnEntity(Args&&... args) {
        uint32_t index;

        if(!_free_indices.empty()){
            index = _free_indices.back();
            _free_indices.pop_back();
        }
        else{
            index = _slots.size();
            _slots.push_back(Slot());
        }

        auto& slot = _slots[index];
        slot.entity = std::make_unique<T>(std::forward<Args>(args)...);
        slot.is_active = true;

        return EntityHandle{
            .index = index,
            .generation = slot.generation
        };
    }

    void destroyEntity(EntityHandle handle) {
        if(EntityBase* ent = getEntity(handle)){
            auto& slot = _slots[handle.index];
            slot.is_active = false;
            slot.entity.reset();
            slot.generation++;

            _free_indices.push_back(handle.index);
        }
    }

    EntityBase* getEntity(EntityHandle handle){
        if(handle.index >= _slots.size()) return nullptr;

        const auto& slot = _slots[handle.index];

        if(slot.is_active && slot.generation == handle.generation)
            return slot.entity.get();

        return nullptr;
    }

private:
    struct Slot {
        std::unique_ptr<EntityBase> entity;
        uint32_t generation = 1;
        bool is_active = false;
    };

    std::vector<Slot> _slots;
    std::vector<uint32_t> _free_indices;
};

#endif // !THEMOLLUSK_ENTITY_MANAGER_H