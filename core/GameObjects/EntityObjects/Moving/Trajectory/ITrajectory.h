#ifndef THEMOLLUSK_I_TRAJECTORY_H
#define THEMOLLUSK_I_TRAJECTORY_H

class ITrajectory {
public:
    virtual ~ITrajectory() = default;

    virtual void consume() = 0;
    virtual float getDirectionAngle() const = 0;
    virtual bool isEnd() const = 0;
};

#endif // !THEMOLLUSK_I_TRAJECTORY_H