#ifndef _HEALTH_EFFECT_H_
#define _HEALTH_EFFECT_H_

#include "../IEffect.h"

#include <stdint.h>

struct HealthEffect :
    public IEffect
{
    int64_t health;

    void apply(EntityBase& entity) override;
};

#endif // !_HEALTH_EFFECT_H_