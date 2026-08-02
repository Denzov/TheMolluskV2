#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

class TickSystem
{
public:
    constexpr float getTickPeriod() const { return TICK_PERIOD; }
    bool consumeTick();
    void process();
private:
    static constexpr float TICK_PERIOD = 0.01; // period in s
    static constexpr float MAX_ACCUMULATED_TICK = 25;

    float _accumulator = 0;
};

#endif // !_TIME_SYSTEM_H_