#ifndef DOOR_HPP
#define DOOR_HPP

#include <memory>
#include <entity.hpp>

class Entity;

class Door {
public:
  Door(const glm::mat4 &transform);
  std::shared_ptr<Entity> next;
  const glm::mat4 transform;
};

#endif // DOOR_HPP
