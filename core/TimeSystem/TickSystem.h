#ifndef THEMOLLUSK_TIME_SYSTEM_H
#define THEMOLLUSK_TIME_SYSTEM_H

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

#endif // !THEMOLLUSK_TIME_SYSTEM_H