#ifndef THEMOLLUSK_HEALTH_MODULE_H
#define THEMOLLUSK_HEALTH_MODULE_H

#include <stdint.h>

namespace EntityModule {
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

        virtual void setMaxHp(const int64_t hp) = 0;
        virtual void addMaxHp(const int64_t hp) = 0;
    };
}

#endif // !THEMOLLUSK_HEALTH_MODULE_H