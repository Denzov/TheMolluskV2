#ifndef _KEYBOARD_
#define _KEYBOARD_

#include <raylib.h>

class Keyboard{
public:
    bool down(KeyboardKey key){
        return IsKeyDown(key);
    }

    bool pressed(KeyboardKey key){
        return IsKeyPressed(key);
    }

    bool released(KeyboardKey key){
        return IsKeyReleased(key);
    }
};

#endif // !_KEYBOARD_