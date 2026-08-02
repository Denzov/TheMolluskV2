#include "MWindowHandler.h"

#include "MWindowExecutor.h"

void MWindowHandler::init() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(Default::width, Default::height, Default::title);
    SetTargetFPS(Default::fps);
}

void MWindowHandler::addCommand(MWindowCommand cmd){
    _commands.push(cmd);
}

void MWindowHandler::process(){
    processMWindow(_commands);
}