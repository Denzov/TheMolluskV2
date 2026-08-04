#ifndef THEMOLLUSK_GAME_CONTEXT_H
#define THEMOLLUSK_GAME_CONTEXT_H

#include "MainCamera2D/MCamera2DHandler.h"
#include "TimeSystem/TickSystem.h"
#include "EntityManager/EntityManager.h"

struct GameContext{
    MCamera2DHandler& camera;
    TickSystem& tick;
    EntityManager& entmanager;

    GameContext(
        MCamera2DHandler& camera, 
        TickSystem& tick,
        EntityManager& entmanager): 
            camera(camera), 
            tick(tick),
            entmanager(entmanager){}
};

#endif // !THEMOLLUSK_GAME_CONTEXT_H