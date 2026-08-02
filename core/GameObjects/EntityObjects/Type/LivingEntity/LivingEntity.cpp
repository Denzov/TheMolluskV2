#include "LivingEntity.h"

int64_t LivingEntity::getHp() const { 
    return _health.hp; 
}
int64_t LivingEntity::getMaxHp() const { 
    return _health.max_hp; 
}

void LivingEntity::takeHp(const int64_t delta_hp) { 
    _health.hp += delta_hp;
}

void LivingEntity::setMaxHp(const int64_t hp) {
    _health.max_hp = hp;
}

void LivingEntity::addMaxHp(const int64_t hp) {
    _health.max_hp += hp;
}

bool LivingEntity::isAlive() const {
    return _health.hp > 0;
}