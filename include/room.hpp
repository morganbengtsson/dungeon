#ifndef ROOM_HPP
#define ROOM_HPP

#include <entity.hpp>
#include <ostream>
#include <string>
#include <mos/assets.hpp>

class Room : public Entity {
public:
  Room(mos::Assets &assets, const glm::mat4 &transform);
  mos::Model model();
  friend std::ostream &operator<<(std::ostream &os, const Room &room);
private:
  glm::ivec2 size_;
  mos::Model room_;
};


#endif // ROOM_HPP
