#include "TemporaryEntity.h"

float TemporaryEntity::getElapsed() const {
    return _timer.elapsed;
}

float TemporaryEntity::getDuration() const {
    return _timer.duration;
}

void TemporaryEntity::elapse(const float time) {
    _timer.elapsed += time;
}

void TemporaryEntity::setDuration(const float time) {
    _timer.duration = time;
}

void TemporaryEntity::addDuration(const float time) {
    _timer.duration += time;
}

bool TemporaryEntity::isAlive() const{
    return _timer.elapsed <= _timer.duration;
}