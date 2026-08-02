#ifndef _APP_H_
#define _APP_H_

#include <raylib.h>

#include "../TimeSystem/TickSystem.h"

#include "../MainWindow/MWindowHandler.h"
#include "../MainCamera2D/MCamera2DHandler.h"

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

	GameContext _context{_main_camera, _tick_system};

	Body body;
};

#endif // !_APP_H_