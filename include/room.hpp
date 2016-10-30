#ifndef ROOM_HPP
#define ROOM_HPP

#include <entity.hpp>

class Room : public Entity {
public:
  Room(const glm::mat4 &transform, const mos::Model &model);
  mos::Model model();
private:
  glm::uvec2 size_;
  mos::Model model_;
};

#endif // ROOM_HPP
