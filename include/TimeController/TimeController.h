#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <raylib.h>


#include <raylib.h>

#include "../Util/lerp.h"

class RealTimeHandler{
public:
    static RealTimeHandler* getInstance() {
        static RealTimeHandler instance;
        return &instance;
    }

    float getTime() const { return GetTime(); }

    float getDeltaTime() const { return GetFrameTime(); }

    float getScaledDeltaTime() const { 
        const float dt = GetFrameTime();
        return _time_scale * dt; 
    }
    float getTimeScale() const { return _time_scale; }
    
    void setTimeScaleByLerp(float target, float lerp_t) {
        _time_scale = umath::lerp(_time_scale, target, lerp_t); 
    }

    void setTimeScale(float scale) { _time_scale = scale; }
    void resetTimeScale() { _time_scale = 1.0f; }
    void addTimeScale(float scale) { _time_scale += scale; }
    void mulTimeScale(float scale) { _time_scale *= scale; }

private:
    RealTimeHandler() = default;
    ~RealTimeHandler() = default;

    RealTimeHandler(const RealTimeHandler&) = delete;
    RealTimeHandler& operator=(const RealTimeHandler&) = delete;
    
private:
    float _time_scale = 1.f;
};

class PhysTimeHandler{
public:
    static PhysTimeHandler* getInstance() {
        static PhysTimeHandler instance;
        return &instance;
    }

    float getTimeStep() const { return TIME_STEP; }

    void timeStep(){
        _time += TIME_STEP;
    }

    double getTime() const { return _time; }

    PhysTimeHandler(const PhysTimeHandler&) = delete;
    PhysTimeHandler& operator=(const PhysTimeHandler&) = delete;

private:
    PhysTimeHandler() = default;
    ~PhysTimeHandler() = default;

private:
    static constexpr double TIME_STEP = 0.001;
    double _time = 0.f;

};

#endif // !_TIME_MANAGER_H_