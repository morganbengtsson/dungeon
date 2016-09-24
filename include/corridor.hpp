#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entity.hpp>

class Corridor : public Entity {
public:  
  Corridor(const glm::vec3 &position,
           const glm::vec2 &previous_direction,
           const mos::Model &floor);
  mos::Model model();
  glm::vec3 end();
  glm::vec2 direction() const;
private:
  float length_;
  glm::vec2 direction_;
  mos::Model floor_;
  mos::Model model_;
};

#endif // CORRIDOR_HPP
