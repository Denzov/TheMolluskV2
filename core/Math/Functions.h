#ifndef THE_MOLLUSK_FUNCTIONS_H
#define THE_MOLLUSK_FUNCTIONS_H

namespace Math{
    inline constexpr float normalize(float value, float start, float end){
        float result = (value - start)/(end - start);
        return result;
    }
}

#endif // !THE_MOLLUSK_FUNCTIONS_H