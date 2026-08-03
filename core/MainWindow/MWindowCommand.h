#ifndef THEMOLLUSK_MAIN_WINDOW_COMMAND_H
#define THEMOLLUSK_MAIN_WINDOW_COMMAND_H

#include <variant>

namespace MWExecutor {
    struct SetWidth { int width; };
    struct SetHeight { int height; };
    struct SetFps { int fps; };
    struct SetFullscreen { bool fullscreen; };
    struct ToggleFullscreen {};
}

using MWindowCommand = std::variant<
    MWExecutor::SetWidth,
    MWExecutor::SetHeight,
    MWExecutor::SetFps,
    MWExecutor::SetFullscreen,
    MWExecutor::ToggleFullscreen
>;

#endif // !THEMOLLUSK_MAIN_WINDOW_COMMAND_H