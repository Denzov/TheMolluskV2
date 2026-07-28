#ifndef _APP_H_
#define _APP_H_

#include <raylib.h>

#include "../TimeSystem/TickSystem.h"

#include "../MainWindow/MWindowHandler.h"
#include "../MainCamera2D/MCamera2DHandler.h"

class GameSystem {
public:
	void Run(){
		init();
		process();
		close();
	}

private:
	void init(){
		_main_window.init();
		_main_camera.init();
	}

	void draw()
	{
		BeginDrawing();
		BeginMode2D(_main_camera.getData());

		ClearBackground(BLANK);

		DrawCircle(0, 0, 10, RED);

		DrawFPS(0, 100);

		EndMode2D();
		EndDrawing();
	}

	void close(){
		CloseWindow();
	}

	void process()
	{
		while (!WindowShouldClose())
		{
			while(_tick_system.consumeTick()){
				simulate(_tick_system.getTickPeriod());
			}

			_tick_system.update();

			_main_window.process();
			_main_camera.process();

			draw();
		}
	}

	void simulate(float dt)
	{
		
	}

private:
	TickSystem _tick_system;

	MWindowHandler _main_window;
	MCamera2DHandler _main_camera;
};

#endif // !_APP_H_