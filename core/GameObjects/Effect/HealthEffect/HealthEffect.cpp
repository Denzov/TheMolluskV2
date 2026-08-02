#include "HealthEffect.h"

#include "GameObjects/EntityObjects/EntityBase.h"
#include "GameObjects/EntityObjects/Module/HealthModule.h"

void HealthEffect::apply(EntityBase& entity){
    if(auto* d = dynamic_cast<EntityModule::IDamageable*>(&entity)){
        d->takeHp(health);
    }
}