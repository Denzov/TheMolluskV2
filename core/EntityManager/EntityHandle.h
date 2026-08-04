#ifndef THEMOLLUSK_ENTITY_HANDLE
#define THEMOLLUSK_ENTITY_HANDLE

#include <stdint.h>

struct EntityHandle{
    uint32_t index = 0;
    uint32_t generation = 0;
    bool operator==(const EntityHandle& other) const {
        return 
            index == other.index && 
            generation == other.generation;
    }
};

#endif // !THEMOLLUSK_ENTITY_HANDLE