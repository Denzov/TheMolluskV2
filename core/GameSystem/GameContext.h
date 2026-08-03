#ifndef THEMOLLUSK_GAME_CONTEXT_H
#define THEMOLLUSK_GAME_CONTEXT_H

#include "../MainCamera2D/MCamera2DHandler.h"
#include "../TimeSystem/TickSystem.h"

struct GameContext{
    MCamera2DHandler& camera;
    TickSystem& tick;

    GameContext(MCamera2DHandler& camera, TickSystem& tick)
        : camera(camera), tick(tick) {}
};

#endif // !THEMOLLUSK_GAME_CONTEXT_H