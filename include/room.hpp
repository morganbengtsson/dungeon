#ifndef ROOM_HPP
#define ROOM_HPP

#include <mos/render/model.hpp>
#include <optional.hpp>
#include <memory>

class Room {
public:
  using SharedRoom = std::shared_ptr<Room>;
  Room(const glm::vec3 &position,
       const glm::uvec2 &size,
       const mos::Model &floor,
       const mos::Model &wall,
       const mos::Model &corner);

  void update(const float dt);
  mos::Model model();
  SharedRoom next;
private:
  glm::vec3 position_;
  float time_;
  glm::uvec2 size_;
  mos::Model out_model_;
  mos::Model floor_;
  mos::Model wall_;
  mos::Model corner_;
};

#endif // ROOM_HPP
