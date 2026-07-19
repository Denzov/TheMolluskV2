#ifndef _I_EFFECT_H_
#define _I_EFFECT_H_

#include "../Entity/EntityBase.h"

class EffectBase{
    EffectBase(EntityBasePtr target, float start_time, float duration, float applying_interval) : 
        _target(target), 
        _start_time(start_time), 
        _duration(duration), 
        _applying_interval(applying_interval){}

    virtual void apply() = 0;

private:
    EntityBasePtr _target;

    float _start_time;
    float _duration;

    float _applying_interval;
};

#endif // !_I_EFFECT_H_