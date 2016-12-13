#ifndef ROOM_HPP
#define ROOM_HPP

#include <entities/entity.hpp>
#include <ostream>
#include <string>
#include <mos/assets.hpp>

class Room : public Entity {
public:
  Room(mos::Assets &assets,
       const glm::mat4 &transform,
       const glm::ivec2 min_size = glm::ivec2(3,3),
       const glm::ivec2 max_size = glm::ivec2(6,6));
  void update(const float dt) override;
  mos::Model model();
protected:
  void print(std::ostream &os) override;
public:
  int room_type;
private:
  glm::ivec2 size_;
  mos::Model room_;
  std::vector<mos::Model> items_;
};


#endif // ROOM_HPP
