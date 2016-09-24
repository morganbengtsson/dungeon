#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>
#include <memory>
#include <mos/render/model.hpp>

class Entity {
public:
  using SharedEntity = std::shared_ptr<Entity>;
  virtual ~Entity(){}
  virtual mos::Model model() = 0;
  virtual glm::vec3 end() = 0;
  virtual glm::vec2 direction() const = 0;
  SharedEntity next;
};

#endif // ENTITY_HPP
