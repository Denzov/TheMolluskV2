#ifndef THEMOLLUSK_TO_RAYLIB
#define THEMOLLUSK_TO_RAYLIB

#include <raylib.h>
#include "Vec2.h"

inline Vector2 toRaylib(const Math::Vec2 v){
    return {
        .x = v.x,
        .y = v.y
    };
}

inline Math::Vec2 toMath(const Vector2 v){
    return {
        .x = v.x,
        .y = v.y
    };
}

#endif // !THEMOLLUSK_TO_RAYLIB