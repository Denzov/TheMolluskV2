#ifndef THEMOLLUSK_APP_H
#define THEMOLLUSK_APP_H

#include <raylib.h>

#include "TimeSystem/TickSystem.h"
#include "EntityManager/EntityManager.h"

#include "MainWindow/MWindowHandler.h"
#include "MainCamera2D/MCamera2DHandler.h"

#include "GameObjects/EntityObjects/Concrete/Body/Body.h"
#include "GameContext.h"

class GameSystem {
public:
	void Run();

private:
	void init();
	void draw();
	void close();
	void process();
	void simulate();	

private:
	TickSystem _tick_system;

	MWindowHandler _main_window;
	MCamera2DHandler _main_camera;

	EntityManager _entmanager;

	GameContext _context{
		_main_camera, 
		_tick_system,
		_entmanager};

	EntityHandle body;
};

#endif // !THEMOLLUSK_APP_H