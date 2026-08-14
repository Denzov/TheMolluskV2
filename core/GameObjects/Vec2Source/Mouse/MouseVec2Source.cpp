#include "MouseVec2Source.h"

#include "GameSystem/GameContext.h"

Math::Vec2 MouseVec2Source::get() const {
    return _context.frame_data.world_mouse_position;
}