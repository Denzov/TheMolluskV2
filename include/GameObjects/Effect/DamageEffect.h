#ifndef _DAMAGE_EFFECT_H_
#define _DAMAGE_EFFECT_H_

#include <math.h>

#include "IEffect.h"
#include "../Entity/EntityBase.h"
#include "../Entity/Module/HealthModule.h"

struct DamageEffect : 
    public IEffect
{
    int64_t damage;

    void apply(EntityBase& entity) override{
        if(auto* d = dynamic_cast<IDamageable*>(&entity)){
            damage = -abs(damage);
            d->takeHp(damage);
        }
    }
};

#endif // !_DAMAGE_EFFECT_H_