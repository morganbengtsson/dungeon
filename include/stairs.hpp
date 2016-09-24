#ifndef STAIRS_HPP
#define STAIRS_HPP

#include <entity.hpp>

class Stairs : public Entity{
public:
  Stairs(const glm::vec3 &position,
         const glm::vec2 &previous_position,
         const mos::Model &model);
  mos::Model model();
  glm::vec3 end();
  glm::vec2 direction() const;
private:
  glm::vec2 direction_;
  mos::Model model_;
};

#endif // STAIRS_HPP
