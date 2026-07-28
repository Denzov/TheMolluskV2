#ifndef _I_INTERACTION_SOURCE_
#define _I_INTERACTION_SOURCE_

#include "../Entity/EntityBase.h"
#include <memory>

namespace InteractionSource
{
    struct collision{ 
        const std::shared_ptr<EntityBase> entity1;
        const std::shared_ptr<EntityBase> entity2;
    };

    struct internal{};    
};

struct InteractionSourceValidator
{
    bool operator()(InteractionSource::collision &t){
        const bool is_collide = Collider::intersect(
            t.entity1.get()->getCollider(), t.entity1.get()->getPosition(), 
            t.entity2.get()->getCollider(), t.entity2.get()->getPosition()
        );

        return is_collide;
    }

    bool operator()(InteractionSource::internal &t){
        return true;
    }
};

#endif // !_I_INTERACTION_SOURCE_