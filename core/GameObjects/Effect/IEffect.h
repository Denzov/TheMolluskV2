#ifndef _I_EFFECT_H_
#define _I_EFFECT_H_

class EntityBase;

class IEffect{
public:
    virtual ~IEffect() = default;
    virtual void apply(EntityBase& entity) = 0;
};

#endif // !_I_EFFECT_H_