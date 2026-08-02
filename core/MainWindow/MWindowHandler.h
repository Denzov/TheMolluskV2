#ifndef _MAIN_WINDOW_HANDLER_H_
#define _MAIN_WINDOW_HANDLER_H_

#include <queue>
#include "MWindowCommand.h"

class MWindowHandler{
public:
    struct Default {
        static constexpr const char* title = "TheMollusk";
        static constexpr int width = 1000;
        static constexpr int height = 1000;
        static constexpr int fps = 60;
    };

    void init();
    void addCommand(MWindowCommand cmd);

    // only for mainthread use 
    void process();

private:
    std::queue<MWindowCommand> _commands;
};

#endif // !_MAIN_WINDOW_HANDLER_H_