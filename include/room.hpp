#ifndef ROOM_HPP
#define ROOM_HPP

#include <entity.hpp>
#include <ostream>

class Room : public Entity {
public:
  Room(const glm::mat4 &transform,
       const mos::Model &floor,
       const mos::Model &floor_edge);
  mos::Model model();
  friend std::ostream &operator<<(std::ostream &os, const Room &room);
private:
  glm::ivec2 size_;
  mos::Model room_;
};


#endif // ROOM_HPP
