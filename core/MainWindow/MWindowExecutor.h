#ifndef _MAIN_WINDOW_EXECUTOR_H_
#define _MAIN_WINDOW_EXECUTOR_H_

#include <raylib.h>
#include <queue>

#include "MWindowCommand.h"

struct MWindowExecutor{
    void operator()(const MWExecutor::SetWidth& w){
        SetWindowSize(w.width, GetRenderHeight());
    }

    void operator()(const MWExecutor::SetHeight& h){
        SetWindowSize(GetRenderWidth(), h.height);
    }

    void operator()(const MWExecutor::SetFps& fps){
        SetTargetFPS(fps.fps);
    }

    void operator()(const MWExecutor::SetFullscreen& fs){
        if(fs.fullscreen == IsWindowFullscreen()) return;
            
        ToggleFullscreen();
    }

    void operator()(const MWExecutor::ToggleFullscreen&){
        ToggleFullscreen();
    }
};


inline void processMWindow(std::queue<MWindowCommand>& cmds){
    if(cmds.empty()){
        return;
    }

    MWindowExecutor exec;
    while (!cmds.empty()) {
        MWindowCommand cmd = std::move(cmds.front());
        
        std::visit(exec, cmd);
        cmds.pop();
    }
}

#endif // !_MAIN_WINDOW_EXECUTOR_H_