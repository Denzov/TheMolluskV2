#ifndef _MOUSE_AIM_INTENT_SOURCE_H_
#define _MOUSE_AIM_INTENT_SOURCE_H_

#include <raylib.h>

#include "IRotationCueSource.h"

#include "GameSystem/GameContext.h"

class MouseRotationCueSource :
    public IRotationCueSource 
{
public:
    MouseRotationCueSource(const GameContext& context) :
        _context(context) {}

    RotationCue get() override {
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return {{}, false};

        const Vector2 mouse_pos = GetMousePosition();
        const Vector2 target = GetScreenToWorld2D(
            mouse_pos, _context.camera.getData());

        return {target, true};
    }

private:
    const GameContext& _context;
};

#endif // !_MOUSE_AIM_INTENT_SOURCE_H_