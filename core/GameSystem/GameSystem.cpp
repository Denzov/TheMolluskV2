#include "GameSystem.h"

void GameSystem::Run(){
    init();
    process();
    close();
}

void GameSystem::init(){
	_main_window.init();
	_main_camera.init();

	body.internalInit(_context);
}

void GameSystem::draw()
{
	BeginDrawing();
	BeginMode2D(_main_camera.getData());


	ClearBackground(BLANK);

	body.draw();

	Shape::draw(Shape::Circle{.radius=5}, Vector2{-400, -400}, BLUE);
	Shape::draw(Shape::Circle{.radius=5}, Vector2{-400, 400}, BLUE);
	Shape::draw(Shape::Circle{.radius=5}, Vector2{400, -400}, BLUE);

	EndMode2D();
	EndDrawing();
}

void GameSystem::close(){
	CloseWindow();
}

void GameSystem::process()
{
	while (!WindowShouldClose())
	{
		while(_tick_system.consumeTick()){
			simulate();
		}

		_tick_system.process();
		_main_window.process();

		_main_camera.addCommand(MCExecutor::CenterCameraOffset{});
		_main_camera.process();

		draw();
	}
}

void GameSystem::simulate()
{
	body.internalUpdate(_context);
}