#ifndef _GAME_CONTEXT_H_
#define _GAME_CONTEXT_H_

#include "../MainCamera2D/MCamera2DHandler.h"
#include "../TimeSystem/TickSystem.h"

struct GameContext{
    MCamera2DHandler& camera;
    TickSystem& tick;

    GameContext(MCamera2DHandler& camera, TickSystem& tick)
        : camera(camera), tick(tick) {}
};

#endif // !_GAME_CONTEXT_H_