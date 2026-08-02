#ifndef _DAMAGE_EFFECT_H_
#define _DAMAGE_EFFECT_H_

#include <math.h>

#include "../IEffect.h"

struct DamageEffect : 
    public IEffect
{
    int64_t damage;
    void apply(EntityBase& entity) override;
};

#endif // !_DAMAGE_EFFECT_H_