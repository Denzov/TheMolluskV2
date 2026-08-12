#include "MCamera2DHandler.h"

#include "MCameraExecutor.h"

void MCamera2DHandler::init(){
    _camera.offset = {GetRenderWidth() / 2.f, GetRenderHeight() / 2.f};
}

void MCamera2DHandler::addCommand(MCameraCommand cmd){
    _commands.push(cmd);
}

void MCamera2DHandler::process(){
    processCamera(_camera, _commands);
}

Camera2D MCamera2DHandler::getData() const {
    return _camera;
}