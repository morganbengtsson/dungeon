#ifndef DUNGEON_ALGORITHM_HPP
#define DUNGEON_ALGORITHM_HPP

#include <glm/gtc/noise.hpp>
#include <mos/util.hpp>

template<class T>
int simplex_index(const T &seed, const int size) {
  return int(glm::abs(glm::simplex(seed) * size));
}

#endif //DUNGEON_ALGORITHM_HPP
