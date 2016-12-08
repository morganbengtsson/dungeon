#ifndef DOOR_HPP
#define DOOR_HPP

#include <memory>
#include <entities/entity.hpp>
#include <mos/assets.hpp>
class Entity;

class Door {
public:
  Door(const glm::mat4 &transform):transform(transform){};
  Door(mos::Assets &assets, const glm::mat4 &transform);
  std::shared_ptr<Entity> next;
  const glm::mat4 transform;
  mos::Model model() const;
private:
  mos::Model model_;
};

#endif // DOOR_HPP
