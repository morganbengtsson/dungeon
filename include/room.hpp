#ifndef ROOM_HPP
#define ROOM_HPP

#include <mos/render/model.hpp>

class Room {
public:
  Room(const glm::uvec2 &size,
       const mos::Model &floor,
       const mos::Model &wall,
       const mos::Model &corner);
  mos::Model model();
private:
  glm::uvec2 size_;
  mos::Model out_model_;
  mos::Model floor_;
  mos::Model wall_;
  mos::Model corner_;
};

#endif // ROOM_HPP
