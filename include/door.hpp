#ifndef DOOR_HPP
#define DOOR_HPP

#include <memory>
#include <entity.hpp>

class Door {
public:
  Door(const glm::vec3 &position, const glm::vec2 &direction);
  using SharedEntity = std::shared_ptr<Entity>;
  SharedEntity next;
  const glm::vec3 position;
  const glm::vec2 direction;
};

#endif // DOOR_HPP
