#ifndef THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H
#define THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H

#include "../IVec2Source.h"

class GameContext;

class MouseVec2Source :
    public IVec2Source
{
public:
    MouseVec2Source(const GameContext& context) :
        _context(context){}

    Math::Vec2 get() const override;
private:
    const GameContext& _context;
};

#endif // !THEMOLLUSK_MOUSE_VECTOR2_SOURCE_H