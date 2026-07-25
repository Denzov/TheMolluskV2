#ifndef _EFFECT_INSTANCE_H_
#define _EFFECT_INSTANCE_H_

#include <memory>
#include "IEffect.h"

struct ActiveEffect{
    std::unique_ptr<IEffect> effect;

    float elapsed;
    float duration;
    float interval;
    float next_apply;
};

#endif // !_EFFECT_INSTANCE_H_