#include "GameSystem.h"

#include "GameObjects/EntityObjects/Concrete/Body/Body.h"
#include "Math/MathRaylibConverter.h"

#include <iostream>

void GameSystem::Run(){
    init();
    loop();
    close();
}

void GameSystem::init(){
	_context.window.init();
	_context.camera.init();
}

void GameSystem::draw()
{
	BeginDrawing();
	BeginMode2D(_context.camera.getData());

	ClearBackground(BLANK);

	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{0, 0}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{0, 10000}, BLUE);

	_entsystem.draw(_context.entmanager);

	EndMode2D();	

	DrawFPS(10, 100);

	EndDrawing();
}

void GameSystem::close(){
	CloseWindow();
}

void GameSystem::loop()
{
	while (!WindowShouldClose())
	{
		process();
		while(_context.tick.consumeTick()){
			simulate();
		}
		draw();
	}
}

void GameSystem::simulate()
{
	_context.frame_data.world_mouse_position = 
		toMath(
			GetScreenToWorld2D(toRaylib(_context.frame_data.mouse_position), 
			_context.camera.getData()));

	_entsystem.update(_context.entmanager, _context);
	_entsystem.cleanup(_context.entmanager);
}

void GameSystem::process(){
	_context.tick.process();
	_context.window.process();

	_context.camera.process();
	_context.camera.addCommand(MCExecutor::CenterCameraOffset{});

	_context.frame_data.mouse_position = toMath(GetMousePosition());

	_context.camera.addCommand(
		MCExecutor::RelativeZoomAt{
			GetMouseWheelMove() * 0.2f,
			GetMousePosition()
		}
	);

	if(IsKeyPressed(KEY_F)){
		std::cout << _context.entmanager.getSlotsSize() << '\n';
	}

	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
		Vector2 dtarget = GetMouseDelta();

		_context.camera.addCommand(
			MCExecutor::AddTarget{
				.x = -dtarget.x,
				.y = -dtarget.y
			}
		);
	}

	if(IsKeyDown(KEY_R)){
		std::vector<EntityHandle> dead;

		_context.entmanager.forEach([&](EntityBase& e){        
			Math::Vec2 pos = e.getMovingModel().getPosition();

			Math::Vec2 mouse = _context.frame_data.world_mouse_position;

			if(Math::distance(pos, mouse) < 1000){
				dead.push_back(e.getHandle());
			}
		});

		for(auto d : dead)
			_context.entmanager.destroyEntity(d);
	}

	if(IsKeyDown(KEY_SPACE)){
		EntityHandle handle = _context.entmanager.spawnEntity<Body>(_context);
	}
}