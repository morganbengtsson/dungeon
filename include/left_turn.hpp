#ifndef LEFTTURN_HPP
#define LEFTTURN_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entity.hpp>

class LeftTurn : public Entity {
public:
  LeftTurn(const glm::vec3 &position,
           const glm::vec2 &previous_direction,
           const mos::Model &model);
  mos::Model model();
  glm::vec3 end();
  glm::vec2 direction() const;
private:
  glm::vec2 direction_;
  glm::vec2 previous_direction_;
  mos::Model model_;
};

#endif // LEFTTURN_HPP
