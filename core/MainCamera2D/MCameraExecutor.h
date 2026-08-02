#ifndef _MCAMERA_EXECUTOR_H_
#define _MCAMERA_EXECUTOR_H_

#include "MCameraCommand.h"

#include <queue>
#include <raymath.h>


struct MCameraExecutor{
    Camera2D& camera;

    void operator()(const MCExecutor::SetTarget& t){
        camera.target = {t.x, t.y};
    }

    void operator()(const MCExecutor::AddTarget& t){
        camera.target.x += t.x / camera.zoom;
        camera.target.y += t.y / camera.zoom;
    }

    void operator()(const MCExecutor::SetOffset& t){
        camera.offset = {t.x, t.y}; 
    }

    void operator()(const MCExecutor::AddOffset& t){
        camera.offset.x += t.x;
        camera.offset.y += t.y;
    }

    void operator()(const MCExecutor::SetRotation& t){
        camera.rotation = t.rotation;
    }

    void operator()(const MCExecutor::AddRotation& t){
        camera.rotation += t.rotation;
    }

    void operator()(const MCExecutor::SetZoom& t){
        camera.zoom = t.zoom;
    }

    void operator()(const MCExecutor::ZoomAt& t){
        const Vector2 before = GetScreenToWorld2D(t.anchor, camera);
        camera.zoom = t.zoom;
        const Vector2 after = GetScreenToWorld2D(t.anchor, camera);

        camera.target.x += before.x - after.x;
        camera.target.y += before.y - after.y;
    }

    void operator()(const MCExecutor::AddZoom& t){
        camera.zoom += t.dzoom;
    }

    void operator()(const MCExecutor::RelativeZoom& t){
        Vector2 screen_center = {
            GetRenderWidth() / 2.f, 
            GetRenderHeight() / 2.f
        };

        const Vector2 before = GetScreenToWorld2D(screen_center, camera);
        camera.zoom += camera.zoom * t.dzoom;
        const Vector2 after  = GetScreenToWorld2D(screen_center, camera);

        camera.target.x += before.x - after.x;
        camera.target.y += before.y - after.y;
    }

    void operator()(const MCExecutor::RelativeZoomAt& t){
        const Vector2 before = GetScreenToWorld2D(t.anchor, camera);
        camera.zoom *= (1 + t.dzoom);
        const Vector2 after  = GetScreenToWorld2D(t.anchor, camera);

        camera.target.x += before.x - after.x;
        camera.target.y += before.y - after.y;
    }

    void operator()(const MCExecutor::CenterCameraOffset& t){
        camera.offset = {
            .x = GetRenderWidth() / 2.f, 
            .y = GetRenderHeight() / 2.f
        };
    }
};

inline void processCamera(Camera2D& cam, std::queue<MCameraCommand>& cmds){
    if(cmds.empty()){
        return;
    }
    
    MCameraExecutor exec{cam};
    while (!cmds.empty()) {
        const MCameraCommand cmd = std::move(cmds.front());
        
        std::visit(exec, cmd);
        cmds.pop();
    }
}
#endif // !_MCAMERA_EXECUTOR_H_