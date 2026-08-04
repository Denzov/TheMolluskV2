#ifndef THEMOLLUSK_APP_H
#define THEMOLLUSK_APP_H

#include "EntityManager/EntityManager.h"
#include "EntitySystem/EntitySystem.h"

#include "TimeSystem/TickSystem.h"

#include "MainWindow/MWindowHandler.h"
#include "MainCamera2D/MCamera2DHandler.h"

#include "GameContext.h"

class GameSystem {
public:
	void Run();

private:
	void init();
	void draw();
	void close();
	void loop();
	void process();
	void simulate();	

private:
	TickSystem _tick_system;

	MWindowHandler _main_window;
	MCamera2DHandler _main_camera;

	EntityManager _entmanager;
	EntitySystem _entsystem;

	GameContext _context{
		_main_camera, 
		_tick_system,
		_entmanager};
};

#endif // !THEMOLLUSK_APP_H