#ifndef _HEALTH_MODULE_H_
#define _HEALTH_MODULE_H_

#include <cstdint>
#include <stdint.h>

struct Health{
    int64_t hp;
    int64_t max_hp;
};

class IDamageable{
public:
    virtual ~IDamageable() = default;
    
    virtual int64_t getHp() const = 0;
    virtual int64_t getMaxHp() const = 0;
    virtual void takeHp(const int64_t delta_hp) = 0;
};

#endif // !_HEALTH_MODULE_H_