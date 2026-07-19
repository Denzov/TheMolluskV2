#ifndef _APP_H_
#define _APP_H_

#include <raylib.h>
#include <vector>

#include "../AppControl/AppControl.h"

class GameApp {
public:
	void Run(){
		init();
		simulate();
	}

private:
	void init(){
 	   AppControl::init();
	}

	void draw()
	{
		BeginDrawing();
		// BeginMode2D(_camera);    

		ClearBackground(BLUE);

		// EndMode2D();
		EndDrawing();
	}

	void close(){
		CloseWindow();
	}

	void simulate()
	{
		while (!WindowShouldClose())
		{
			compute();
			draw();
		}
		close();
	}

	void compute()
	{
		AppControl::process();
	}

};

#endif // !_APP_H_