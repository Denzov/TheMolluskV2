#ifndef THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H
#define THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H

#include "IVector2Source.h"

#include "GameSystem/GameContext.h"

class MouseVector2Source :
    public IVector2Source
{
public:
    MouseVector2Source(const GameContext& context) :
        _context(context){}

    Vector2 get() const override {
        const Vector2 mouse_pos = GetMousePosition();
        const Vector2 target = GetScreenToWorld2D(
            mouse_pos, _context.camera.getData());
        return target;
    }

private:
    const GameContext& _context;
};

#endif // !THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H