#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>
#include <memory>
#include <mos/render/model.hpp>
#include <vector>
#include <door.hpp>

class Door;

class Entity {
public:
  using SharedEntity = std::shared_ptr<Entity>;
  virtual ~Entity(){}
  virtual mos::Model model() = 0;
  std::vector<Door> exits;
};

#endif // ENTITY_HPP
