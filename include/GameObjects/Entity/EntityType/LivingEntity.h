#ifndef _LIVING_ENTITY_H_
#define _LIVING_ENTITY_H_

#include "../EntityBase.h"
#include "../Module/HealthModule.h"

class LivingEntity:
    public EntityBase, 
    public EntityModule::IDamageable
{
public:
    virtual ~LivingEntity() = default;

    int64_t getHp() const override { 
        return _health.hp; 
    }
    int64_t getMaxHp() const override { 
        return _health.max_hp; 
    }

    void takeHp(const int64_t delta_hp) override { 
        _health.hp += delta_hp;
    }

    void setMaxHp(const int64_t hp) override {
        _health.max_hp = hp;
    }

    void addMaxHp(const int64_t hp) override {
        _health.max_hp += hp;
    }

    bool isAlive() const override { 
        return _health.hp > 0;
    }

private:
    EntityModule::Health _health;
};

#endif // !_LIVING_ENTITY_H_