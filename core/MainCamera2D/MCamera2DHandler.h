#ifndef _MAIN_CAMERA_2D_HANDLER_H_
#define _MAIN_CAMERA_2D_HANDLER_H_

#include <queue>

#include "MCameraCommand.h"

class MCamera2DHandler{
public:
    void init();
    void addCommand(MCameraCommand cmd);
    void process();

    Camera2D getData();

private:
    Camera2D _camera{
        .offset = {0.f, 0.f},
        .target = {0.f, 0.f},
        .rotation = 0.f,
        .zoom = 1.f
    };

    std::queue<MCameraCommand> _commands;
};

#endif // !_MAIN_CAMERA_2D_HANDLER_H_