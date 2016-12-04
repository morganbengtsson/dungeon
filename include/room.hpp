#ifndef ROOM_HPP
#define ROOM_HPP

#include <entity.hpp>
#include <ostream>
#include <string>
#include <mos/assets.hpp>

class Room : public Entity {
public:
  Room(const glm::mat4 &transform);
  mos::Model model();
  friend std::ostream &operator<<(std::ostream &os, const Room &room);
private:
  glm::ivec2 size_;
  mos::Model room_;
  static mos::Assets assets_;
};


#endif // ROOM_HPP
