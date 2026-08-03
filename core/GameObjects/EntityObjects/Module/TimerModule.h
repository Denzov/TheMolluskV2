#ifndef THEMOLLUSK_TIMER_MODULE_H
#define THEMOLLUSK_TIMER_MODULE_H

namespace EntityModule {
    struct Timer {
        float elapsed = 0;
        float duration;
    };

    class ITemporary { 
    public:
        virtual ~ITemporary() = default;

        virtual float getElapsed() const = 0;
        virtual float getDuration() const = 0;
        
        virtual void elapse(const float time) = 0;

        virtual void setDuration(const float time) = 0;
        virtual void addDuration(const float time) = 0;
    };
}
#endif // !THEMOLLUSK_TIMER_MODULE_H