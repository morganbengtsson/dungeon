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
protected:
  void print(std::ostream &os) override;
public:
  int room_type;
private:
  glm::ivec2 size_;
  mos::Model room_;
};


#endif // ROOM_HPP
