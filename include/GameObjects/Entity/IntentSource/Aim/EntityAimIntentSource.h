#ifndef _MOUSE_AIM_INTENT_SOURCE_H_
#define _MOUSE_AIM_INTENT_SOURCE_H_

#include <memory.h>

#include "IAimIntentSource.h"

#include "../../EntityBase.h"

class EntityAimIntentSource :
    public IAimIntentSource 
{
public:
    AimIntent get() override {
        if(_target)
            return {_target->getPosition(), true};

        return {{}, false};
    }

private:
    std::shared_ptr<EntityBase> _target;
};

#endif // !_MOUSE_AIM_INTENT_SOURCE_H_