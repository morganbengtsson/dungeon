#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>

class Corridor {
public:
  using SharedCorridor = std::shared_ptr<Corridor>;
  Corridor(const glm::vec3 &position,
           const mos::Model &floor);
  mos::Model model();
  glm::vec3 end();
  SharedCorridor next;
private:
  mos::Model floor_;
  mos::Model model_;
};

#endif // CORRIDOR_HPP
