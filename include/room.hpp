#ifndef ROOM_HPP
#define ROOM_HPP

#include <entity.hpp>
#include <ostream>

class Room : public Entity {
public:
  Room(const glm::mat4 &transform, const mos::Model &model);
  mos::Model model();
  friend std::ostream &operator<<(std::ostream &os, const Room &room);
private:
  glm::ivec2 size_;
  mos::Model model_;
};


#endif // ROOM_HPP
