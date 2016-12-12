#ifndef DUNGEON_ALGORITHM_HPP
#define DUNGEON_ALGORITHM_HPP

#include <glm/gtc/noise.hpp>
#include <mos/util.hpp>

template<class T>
int simplex_range(const T &seed, const int min, const int max) {
  // Noise value in range -1.0f, 1.0f.
  auto s = glm::simplex(seed);

  // Scale it to the min , max range.
  auto n = (((s + 1.0f) * (max - min)) / 2.0f) + min;
  return int(n);
}

template<class T>
float simplex_range(const T &seed, const float min, const float max){
  // Noise value in range -1.0f, 1.0f.
  auto s = glm::simplex(seed);

  // Scale it to the min , max range.
  auto n = (((s + 1.0f) * (max - min)) / 2.0f) + min;
  return n;
}

template<class T>
bool simplex_bool(const T &seed){
  return glm::simplex(seed) > 0.0f ? true : false;
}

#endif //DUNGEON_ALGORITHM_HPP
