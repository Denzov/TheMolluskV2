#include "GameSystem.h"

#include "GameObjects/EntityObjects/Concrete/Body/Body.h"

#include "GameObjects/Effect/DamageEffect/DamageEffect.h"
#include <iostream>

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
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{0, 10000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{0, 30000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{10000, 30000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{10000, 15000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{20000, 15000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{20000, 30000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{30000, 30000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{30000, 10000}, BLUE);
	Shape::draw(Shape::Circle{.radius=300}, Math::Vec2{15000, -10000}, BLUE);

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

#include <Moving/Model/DirectMoving/DirectMovingModel.h>

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

	if(IsKeyPressed(KEY_F)){
		std::cout << _entmanager.getSlotsSize() << '\n';
	}

	if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)){
		Vector2 dtarget = GetMouseDelta();

		_main_camera.addCommand(
			MCExecutor::AddTarget{
				.x = -dtarget.x,
				.y = -dtarget.y
			}
		);
	}

	if(IsKeyPressed(KEY_A)){
		_entmanager.forEach([](EntityBase& e){
			e.setMovingModel(
				std::make_unique<DirectMovingModel>(
					e.getPosition(),
					DirectMovingPropery{
						.velocity = (float)GetRandomValue(1000, 9000)
					}
				)
			);
		});
	}

	if(IsKeyPressed(KEY_S)){
		_entmanager.forEach([](EntityBase& e){
			e.setMovingModel(
				std::make_unique<FirstOrderMovingModel>(
					e.getPosition(),
					FirstOrderMovingProperty
					{
						.desired_velocity = (float)GetRandomValue(1000, 9000),
						.T = ((float)GetRandomValue(1, 3000) / 1000.f)
					}
				)	
			);
		});
	}

	if(IsKeyDown(KEY_SPACE)){
		EntityHandle handle = _entmanager.spawnEntity<Body>(_context);
		
		_entmanager.getEntity(handle)->setMovingModel(
			std::make_unique<FirstOrderMovingModel>(
				Math::Vec2{
					.x = (float)GetRandomValue(-20000, 20000) / 100.f + 
						GetScreenToWorld2D(GetMousePosition(), _context.camera.getData()).x, 
					.y = (float)GetRandomValue(-20000, 20000) / 100.f + 
						GetScreenToWorld2D(GetMousePosition(), _context.camera.getData()).y
				},
				FirstOrderMovingProperty
				{
					.desired_velocity = (float)GetRandomValue(2000, 6000),
					.T = (1.1f + (float)GetRandomValue(-1000, 1000) / 1000.f) / 1.5f
				}
			)
		);
	}
}