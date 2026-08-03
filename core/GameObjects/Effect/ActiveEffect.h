#ifndef THEMOLLUSK_EFFECT_INSTANCE_H
#define THEMOLLUSK_EFFECT_INSTANCE_H

#include <memory>
#include "IEffect.h"

struct ActiveEffect{
    std::unique_ptr<IEffect> effect;

    float elapsed;
    float duration;
    float interval;
    float next_apply;
};

#endif // !THEMOLLUSK_EFFECT_INSTANCE_H