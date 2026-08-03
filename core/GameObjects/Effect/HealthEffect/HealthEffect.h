#ifndef THEMOLLUSK_HEALTH_EFFECT_H
#define THEMOLLUSK_HEALTH_EFFECT_H

#include "../IEffect.h"

#include <stdint.h>

struct HealthEffect :
    public IEffect
{
    int64_t health;

    void apply(EntityBase& entity) override;
};

#endif // !THEMOLLUSK_HEALTH_EFFECT_H