#ifndef _MOUSE_AIM_INTENT_SOURCE_H_
#define _MOUSE_AIM_INTENT_SOURCE_H_

#include <memory.h>

#include "IRotationCueSource.h"

#include "../../EntityBase.h"

class EntityRotationCueSource :
    public IRotationCueSource 
{
public:
    RotationCue get() override {
        if(_target)
            return {_target->getPosition(), true};

        return {{}, false};
    }

private:
    std::shared_ptr<EntityBase> _target;
};

#endif // !_MOUSE_AIM_INTENT_SOURCE_H_