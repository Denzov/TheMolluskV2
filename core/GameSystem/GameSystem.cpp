#include "GameSystem.h"

#include "GameObjects/EntityObjects/Concrete/Body/Body.h"

#include "GameObjects/Effect/DamageEffect/DamageEffect.h"

void GameSystem::Run(){
    init();
    loop();
    close();
}

void GameSystem::init(){
	_main_window.init();
	_main_camera.init();
}

void GameSystem::draw()
{
	BeginDrawing();
	BeginMode2D(_main_camera.getData());

	ClearBackground(BLANK);

	Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{0, 0}, BLUE);
	Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{10000, 0}, BLUE);
	Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{5000, (float)std::sqrt(3) / 2 * 10000}, BLUE);
	// Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{-50000, 0}, BLUE);
	// Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{0, 50000}, BLUE);
	// Shape::draw(Shape::Circle{.radius=200}, Math::Vec2{0, -50000}, BLUE);
	
	_entsystem.draw(_entmanager);

	EndMode2D();
	EndDrawing();
}

void GameSystem::close(){
	CloseWindow();
}

void GameSystem::loop()
{
	while (!WindowShouldClose())
	{
		while(_tick_system.consumeTick()){
			simulate();
		}

		process();
		draw();
	}
}

void GameSystem::simulate()
{
	_entsystem.update(_entmanager, _context);
	_entsystem.cleanup(_entmanager);
}

void GameSystem::process(){
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

	if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)){
		Vector2 dtarget = GetMouseDelta();

		_main_camera.addCommand(
			MCExecutor::AddTarget{
				.x = -dtarget.x,
				.y = -dtarget.y
			}
		);
	}

	if(IsKeyDown(KEY_SPACE)){
		EntityHandle handle = _entmanager.spawnEntity<Body>(_context);
		_entmanager.getEntity(handle)->setPosition({
			(float)GetRandomValue(-20000, 20000) / 100.f + 
				GetScreenToWorld2D(GetMousePosition(), _context.camera.getData()).x, 
			(float)GetRandomValue(-20000, 20000) / 100.f + 
				GetScreenToWorld2D(GetMousePosition(), _context.camera.getData()).y});

		_entmanager.getEntity(handle)->setMovingModel(std::make_unique<FirstOrderMovingModel>(
            FirstOrderMovingProperty{
                .T = 2.5f + (float)GetRandomValue(-2000, 2000) / 1000.f
            }
        ));

		_entmanager.getEntity(handle)->
			setDesiredVelocity((float)GetRandomValue(2000, 6000));
	}
}