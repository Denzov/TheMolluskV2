#ifndef _MAIN_CAMERA_2D_HANDLER_H_
#define _MAIN_CAMERA_2D_HANDLER_H_

#include "MCameraExecutor.h"

class MCamera2DHandler{
public:
    void init(){
        _camera.offset = {GetRenderWidth() / 2.f, GetRenderHeight() / 2.f};
    }

    void addCommand(CameraCommand cmd){
        _commands.push(cmd);
    }

    void process(){
        processCamera(_camera, _commands);

        addCommand(MCExecutor::CenterCameraOffset{});
    }

    Camera2D getData(){
        return _camera;
    }

    Vector2 screenToWorld(Vector2 screen) const {
        return GetScreenToWorld2D(screen, _camera);
    }

private:
    Camera2D _camera{
        .offset = {0.f, 0.f},
        .target = {0.f, 0.f},
        .rotation = 0.f,
        .zoom = 1.f
    };

    std::queue<CameraCommand> _commands;
};

#endif // !_MAIN_CAMERA_2D_HANDLER_H_