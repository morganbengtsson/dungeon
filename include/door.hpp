#ifndef DOOR_HPP
#define DOOR_HPP

#include <memory>
#include <corridor.hpp>

class Door {
public:
  using SharedEntity = std::shared_ptr<Corridor>;
  Door(const glm::vec3& position);
  SharedEntity previous;
  SharedEntity next;
  const glm::vec3 position;
};

#endif // DOOR_HPP
