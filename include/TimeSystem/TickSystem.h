#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

#include <cmath>
#include <cstdint>
#include <raylib.h>

#include <stdint.h>

class TickSystem
{
public:
    float getTickPeriod(){
        return TICK_PERIOD;
    }

    bool consumeTick(){
        if(_accumulator <= TICK_PERIOD){
            return false;
        }

        _accumulator -= TICK_PERIOD;
        return true;
    }
    
    void update(){
        const float cur_time = GetTime();

        if(cur_time - _last_update_time > TICK_PERIOD){
            _accumulator += TICK_PERIOD;
            _last_update_time = cur_time;
        }
    }
private:
    static constexpr float TICK_PERIOD = 0.01; // period in ms

    float _last_update_time = 0;
    float _accumulator = 0;
};

#endif // !_TIME_SYSTEM_H_