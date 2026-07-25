#ifndef _MAIN_WINDOW_HANDLER_H_
#define _MAIN_WINDOW_HANDLER_H_

#include <string>
#include <string_view>
#include "MWindowExecutor.h"

class MWindowHandler{
public:
    struct DefaultData {
        static constexpr const char* title = "TheMollusk";
        static constexpr int width = 1000;
        static constexpr int height = 1000;
        static constexpr int fps = 60;
    };

    void init(){
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(DefaultData::width, DefaultData::height, DefaultData::title);
        SetTargetFPS(DefaultData::fps);
    }

    void addCommand(MWindowCommand cmd){
        _commands.push(cmd);
    }

    // only for mainthread use 
    void process(){
        processMWindow(_commands);
    }

private:
    std::queue<MWindowCommand> _commands;
};

#endif // !_MAIN_WINDOW_HANDLER_H_