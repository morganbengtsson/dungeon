#ifndef DUNGEON_ALGORITHM_HPP
#define DUNGEON_ALGORITHM_HPP

#include <glm/gtc/noise.hpp>
#include <mos/util.hpp>

template<class T>
int simplex_index(const T &seed, const int size) {
  return int(glm::abs(glm::simplex(seed) * size));
}

template<class T>
bool simplex_bool(const T &seed){
  return glm::simplex(seed) > 0.0f ? true : false;
}

#endif //DUNGEON_ALGORITHM_HPP
