#ifndef THEMOLLUSK_COMMO_H
#define THEMOLLUSK_COMMO_H

#include <vector>
#include <memory>

template<typename T, typename... Args>
inline std::vector<std::unique_ptr<T>> make_unique_vector(Args&&... args) {
    std::vector<std::unique_ptr<T>> vec;
    vec.reserve(sizeof...(Args));
    (vec.push_back(std::move(args)), ...);
    return vec;
}

template<typename T, typename... Args>
std::vector<T> make_vector(Args&&... args)
{
    std::vector<T> vec;
    vec.reserve(sizeof...(Args));
    (vec.emplace_back(std::forward<Args>(args)), ...);
    return vec;
}

#endif // !THEMOLLUSK_COMMO_H