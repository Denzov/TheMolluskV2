#ifndef THEMOLLUSK_ENTITY_MANAGER_H
#define THEMOLLUSK_ENTITY_MANAGER_H

#include "EntityHandle.h"
#include "Base/EntityBase.h"

#include <vector>
#include <stdint.h>
#include <memory>

class GameContext;

class EntityManager{
public:
    ~EntityManager();

    template<typename T, typename... Args>
    EntityHandle spawnEntity(GameContext& context, Args&&... args) {
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
        
        auto handle = EntityHandle{
            .index = index,
            .generation = slot.generation
        };

        slot.entity->_internal_init(context, handle);

        return handle;
    }

    void destroyEntity(EntityHandle handle);

    EntityBase* getEntity(EntityHandle handle) const;

    size_t getSlotsSize();
    
    template<typename Func>
    void forEach(Func func)
    {
        for (Slot& slot : _slots)
        {
            if (!slot.is_active)
                continue;

            func(*slot.entity.get());
        }
    }

    template<typename T, typename Func>
    void forEach(Func func)
    {
        for (Slot& slot : _slots)
        {
            if (!slot.is_active)
                continue;

            if (auto* obj = dynamic_cast<T*>(slot.entity.get()))
                func(*obj);
        }
    }

private:
    struct Slot {
        std::unique_ptr<EntityBase> entity;
        uint32_t generation = 1;
        bool is_active = false;

        Slot();
        ~Slot();
        Slot(Slot&&) noexcept;
        Slot& operator=(Slot&&) noexcept;
    };

    std::vector<Slot> _slots;
    std::vector<uint32_t> _free_indices;
};

#endif // !THEMOLLUSK_ENTITY_MANAGER_H