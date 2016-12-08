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
  virtual void update(const float dt) = 0;
  std::vector<Door> exits;
  bool intersects(const Entity &entity) const;
  mos::Box box() const;
  friend std::ostream& operator<<(std::ostream& ofs, Entity& e);
protected:
  virtual void print(std::ostream &os) = 0;
  mos::Box box_;
};

#endif // ENTITY_HPP
