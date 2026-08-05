#include "MouseVector2Source.h"

#include "GameSystem/GameContext.h"

Vector2 MouseVector2Source::get() const {
    const Vector2 mouse_pos = GetMousePosition();
    const Vector2 target = GetScreenToWorld2D(
        mouse_pos, _context.camera.getData());
    return target;
}