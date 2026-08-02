#ifndef _MAIN_CAMERA_COMMAND_H_
#define _MAIN_CAMERA_COMMAND_H_

#include <raylib.h>
#include <variant>

namespace MCExecutor{
    struct SetTarget{
        const float x;
        const float y;
    };

    struct AddTarget{
        const float x;
        const float y;
    };

    struct SetOffset{
        const float x;
        const float y;
    };

    struct AddOffset{
        const float x;
        const float y;
    };

    struct SetRotation{
        const float rotation;
    };

    struct AddRotation{
        const float rotation;
    };
    
    struct SetZoom{
        const float zoom;
    };

    struct ZoomAt{
        const float zoom;
        const Vector2 anchor;
    };

    struct AddZoom{
        const float dzoom;
    }; 

    struct RelativeZoom{
        const float dzoom;
    };

    struct RelativeZoomAt{
        const float dzoom;
        const Vector2 anchor;
    };

    struct CenterCameraOffset{};
};

using MCameraCommand = std::variant<
    MCExecutor::SetTarget,
    MCExecutor::AddTarget,
    MCExecutor::SetOffset,
    MCExecutor::AddOffset,
    MCExecutor::SetRotation,
    MCExecutor::AddRotation,
    MCExecutor::SetZoom,
    MCExecutor::AddZoom,
    MCExecutor::ZoomAt,
    MCExecutor::RelativeZoom,
    MCExecutor::RelativeZoomAt,
    MCExecutor::CenterCameraOffset
>;

#endif // !_MAIN_CAMERA_COMMAND_H_