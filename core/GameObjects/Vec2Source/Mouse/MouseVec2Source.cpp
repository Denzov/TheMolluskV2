#include "MouseVec2Source.h"

#include "GameSystem/GameContext.h"
#include "Math/MathRaylibConverter.h"

Math::Vec2 MouseVec2Source::get() const {
    const Math::Vec2 mouse_pos = toMath(GetMousePosition());
    const Math::Vec2 target = toMath(GetScreenToWorld2D(
        toRaylib(mouse_pos), _context.camera.getData()));
    return target;
}