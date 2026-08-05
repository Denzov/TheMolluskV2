#ifndef THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H
#define THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H

#include "../IVector2Source.h"

class GameContext;

class MouseVector2Source :
    public IVector2Source
{
public:
    MouseVector2Source(const GameContext& context) :
        _context(context){}

    Vector2 get() const override;
private:
    const GameContext& _context;
};

#endif // !THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H