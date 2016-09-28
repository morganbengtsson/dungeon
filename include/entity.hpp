#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include <mos/render/model.hpp>
#include <mos/simulate/box.hpp>
#include <door.hpp>

class Door;

class Entity {
public:
  using SharedEntity = std::shared_ptr<Entity>;
  virtual ~Entity(){}
  virtual mos::Model model() = 0;
  std::vector<Door> exits;
  bool intersects(const Entity &entity) const;
  mos::Box box() const;
protected:
  mos::Box box_;
};

#endif // ENTITY_HPP
