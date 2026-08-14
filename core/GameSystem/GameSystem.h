#ifndef THEMOLLUSK_APP_H
#define THEMOLLUSK_APP_H

#include "EntitySystem/EntitySystem.h"

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
	EntitySystem _entsystem;

	GameContext _context;

};

#endif // !THEMOLLUSK_APP_H