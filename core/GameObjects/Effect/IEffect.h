#ifndef THEMOLLUSK_I_EFFECT_H
#define THEMOLLUSK_I_EFFECT_H

class EntityBase;

class IEffect{
public:
    virtual ~IEffect() = default;
    virtual void apply(EntityBase& entity) = 0;
};

#endif // !THEMOLLUSK_I_EFFECT_H