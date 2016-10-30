#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entity.hpp>

class Corridor : public Entity {
public:  
  Corridor(const glm::mat4 &transform,
           const mos::Model &floor);
  mos::Model model();
private:
  unsigned int length_;
  mos::Model floor_;
  mos::Model model_;
};

#endif // CORRIDOR_HPP
