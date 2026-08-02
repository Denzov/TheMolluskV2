#include "TickSystem.h"

#include <raylib.h>

#include <algorithm>
#include <stdint.h>


bool TickSystem::consumeTick() {
    if(_accumulator < TICK_PERIOD){
        return false;
    }

    _accumulator -= TICK_PERIOD;
    return true;
}

void TickSystem::process() {
    const float dt = GetFrameTime();

    _accumulator += dt;

    _accumulator = std::min(
        _accumulator, 
        TICK_PERIOD * MAX_ACCUMULATED_TICK);
}