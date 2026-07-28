#ifndef _TIMER_MODULE_H_
#define _TIMER_MODULE_H_

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
    };
}
#endif // !_TIMER_MODULE_H_