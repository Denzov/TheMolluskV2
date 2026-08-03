#include "DamageEffect.h"

#include "GameObjects/EntityObjects/Base/EntityBase.h"
#include "GameObjects/EntityObjects/Module/HealthModule.h"

void DamageEffect::apply(EntityBase& entity) {
    if(auto* d = dynamic_cast<EntityModule::IDamageable*>(&entity)){
        damage = -abs(damage);
        d->takeHp(damage);
    }
}