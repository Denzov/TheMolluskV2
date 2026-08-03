#ifndef THEMOLLUSK_LIVING_ENTITY_H
#define THEMOLLUSK_LIVING_ENTITY_H

#include "GameObjects/EntityObjects/Base/EntityBase.h"
#include "GameObjects/EntityObjects/Module/HealthModule.h"

class LivingEntity:
    public EntityBase, 
    public EntityModule::IDamageable
{
public:
    virtual ~LivingEntity() = default;

    int64_t getHp() const override;
    int64_t getMaxHp() const override;

    void takeHp(const int64_t delta_hp) override;
    
    void setMaxHp(const int64_t hp) override;
    void addMaxHp(const int64_t hp) override;
    
    bool isAlive() const override;

private:
    EntityModule::Health _health;
};

#endif // !THEMOLLUSK_LIVING_ENTITY_H