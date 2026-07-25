#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <raylib.h>

class RealTimeHandler{
public:
    static RealTimeHandler* getInstance() {
        static RealTimeHandler instance;
        return &instance;
    }

    float getTime() const { return GetTime(); }
    float getFrameTime() const { return GetFrameTime(); }

private:
    RealTimeHandler() = default;
    ~RealTimeHandler() = default;

    RealTimeHandler(const RealTimeHandler&) = delete;
    RealTimeHandler& operator=(const RealTimeHandler&) = delete;
};


#endif // !_TIME_MANAGER_H_