#ifndef _I_INTERACTION_SOURCE_
#define _I_INTERACTION_SOURCE_

#include "../Entity/EntityBase.h"

namespace InteractionSource
{
    struct collision{ 
        const EntityBase& entity1;
        const EntityBase& entity2;
    };

    struct internal{};    
};

struct InteractionSourceValidator
{
    bool operator()(InteractionSource::collision &t) const {
        const bool is_collide = Shape::intersect(
            t.entity1.getShape(), t.entity1.getPosition(), 
            t.entity2.getShape(), t.entity2.getPosition()
        );

        return is_collide;
    }

    bool operator()(InteractionSource::internal &t) const {
        return true;
    }
};

#endif // !_I_INTERACTION_SOURCE_