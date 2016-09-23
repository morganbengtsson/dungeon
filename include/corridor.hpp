#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <mos/render/model.hpp>

class Corridor {
public:
  Corridor(const glm::vec3 &position,
           const mos::Model &floor);
  mos::Model model();

private:
  mos::Model model_;
};

#endif // CORRIDOR_HPP
