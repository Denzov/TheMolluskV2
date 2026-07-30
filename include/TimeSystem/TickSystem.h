#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

#include <raylib.h>

#include <algorithm>
#include <stdint.h>

class TickSystem
{
public:
    constexpr float getTickPeriod() const {
        return TICK_PERIOD;
    }

    bool consumeTick(){
        if(_accumulator < TICK_PERIOD){
            return false;
        }

        _accumulator -= TICK_PERIOD;
        return true;
    }
    
    void update(){
        const float dt = GetFrameTime();

        _accumulator += dt;

        _accumulator = std::min(
            _accumulator, 
            TICK_PERIOD * MAX_ACCUMULATED_TICK);
    }
private:
    static constexpr float TICK_PERIOD = 0.01; // period in s
    static constexpr float MAX_ACCUMULATED_TICK = 25;

    float _accumulator = 0;
};

#endif // !_TIME_SYSTEM_H_