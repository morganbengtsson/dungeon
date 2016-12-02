#ifndef ROUND_ROOM_HPP
#define ROUND_ROOMRoom_HPP

#include <entity.hpp>
#include <ostream>

class RoundRoom : public Entity {
public:
  RoundRoom(const glm::mat4 &transform, const mos::Model &model);
  mos::Model model();
  friend std::ostream &operator<<(std::ostream &os, const RoundRoom &RoundRoom);
private:
  int diameter_;
  mos::Model model_;
};

#endif // ROUND_ROOM_HPP
