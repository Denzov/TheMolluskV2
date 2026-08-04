#include "GameSystem.h"

void GameSystem::Run(){
    init();
    process();
    close();
}

void GameSystem::init(){
	_main_window.init();
	_main_camera.init();

	body = _entmanager.spawnEntity<Body>();
	 
	_entmanager.getEntity(body)->internalInit(_context);
}

void GameSystem::draw()
{
	BeginDrawing();
	BeginMode2D(_main_camera.getData());

	ClearBackground(BLANK);
	
	Shape::draw(Shape::Circle{.radius=300}, Vector2{-700, -700}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{-700, 700}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{700, -700}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{700, 700}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{0, 1400}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{0, -1400}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{1400, 0}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{-1400, 0}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Vector2{50000, -2000}, BLUE);
	
	_entmanager.getEntity(body)->draw();

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

		_main_camera.addCommand(
			MCExecutor::RelativeZoomAt{
				GetMouseWheelMove() * 0.2f,
				GetMousePosition()
			}
		);

		if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
			Vector2 dtarget = GetMouseDelta();

			_main_camera.addCommand(
				MCExecutor::AddTarget{
					.x = -dtarget.x,
					.y = -dtarget.y
				}
			);
		}

		draw();
	}
}

void GameSystem::simulate()
{
	_entmanager.getEntity(body)->internalUpdate(_context);
}