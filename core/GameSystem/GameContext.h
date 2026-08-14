#ifndef THEMOLLUSK_GAME_CONTEXT_H
#define THEMOLLUSK_GAME_CONTEXT_H

#include "MainWindow/MWindowHandler.h"
#include "MainCamera2D/MCamera2DHandler.h"
#include "TimeSystem/TickSystem.h"
#include "EntityManager/EntityManager.h"

#include "FrameData.h"

struct GameContext{
	MWindowHandler window;
    MCamera2DHandler camera;
    TickSystem tick;
    EntityManager entmanager;
    FrameData frame_data;
};

#endif // !THEMOLLUSK_GAME_CONTEXT_H