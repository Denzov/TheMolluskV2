#ifndef _APP_CONTROL_H_
#define _APP_CONTROL_H_

#include <raylib.h>

#include "../MainWindow/MWindowHandler.h"
#include "../MainCamera2D/MCamera2DHandler.h"

class AppControl{
public:
    static void init(){
        MWindowHandler::getInstance()->init();
        MCamera2DHandler::getInstance()->init();
    }

    static void process(){
        MWindowHandler::getInstance()->process();
        MCamera2DHandler::getInstance()->process();
    }

private:
};

#endif // !_APP_CONTROL_H_