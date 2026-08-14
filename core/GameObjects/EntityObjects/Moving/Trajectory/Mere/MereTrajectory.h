#ifndef THEMOLLUSK_MERE_TRAJECTORY_H
#define THEMOLLUSK_MERE_TRAJECTORY_H

#include "../ITrajectory.h"

#include <memory>

class IVec2Source;

struct MereTrajectoryProperty{
    const float reach_radius;
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<IVec2Source> target;
};

class MereTrajectory:
    public ITrajectory
{
public:
    MereTrajectory(
        MereTrajectoryProperty property);

    void consume() override;
    float getDirectionAngle() const override;
    bool isEnd() const override;    

private:
    MereTrajectoryProperty _property;

};

#endif // !THEMOLLUSK_MERE_TRAJECTORY_H