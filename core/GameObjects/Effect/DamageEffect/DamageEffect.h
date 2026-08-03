#ifndef THEMOLLUSK_DAMAGE_EFFECT_H
#define THEMOLLUSK_DAMAGE_EFFECT_H

#include <math.h>

#include "../IEffect.h"

struct DamageEffect : 
    public IEffect
{
    int64_t damage;
    void apply(EntityBase& entity) override;
};

#endif // !THEMOLLUSK_DAMAGE_EFFECT_H