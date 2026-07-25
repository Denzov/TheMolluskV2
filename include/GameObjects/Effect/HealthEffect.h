#ifndef _HEALTH_EFFECT_H_
#define _HEALTH_EFFECT_H_

#include "IEffect.h"
#include "../Entity/EntityBase.h"
#include "../Entity/Module/HealthModule.h"

struct HealthEffect :
    public IEffect
{
    int64_t hp;

    void apply(EntityBase& entity) override{
        if(auto* d = dynamic_cast<IDamageable*>(&entity)){
            d->takeHp(hp);
        }
    }
};

#endif // !_HEALTH_EFFECT_H_