#ifndef _LIVING_ENTITY_H_
#define _LIVING_ENTITY_H_

#include "EntityBase.h"
#include "Module/HealthModule.h"
#include <cstdint>

class LivingEntity:
    public EntityBase, 
    public IDamageable
{
    int64_t getHp() const override { 
        return _health.hp; 
    }
    int64_t getMaxHp() const override { 
        return _health.max_hp; 
    }

    void takeHp(const int64_t delta_hp) override { 
        _health.hp += delta_hp;

    }

    bool isAlive() const override { 
        return _health.hp <= 0;
    }

private:
    Health _health;
};

#endif // !_LIVING_ENTITY_H_