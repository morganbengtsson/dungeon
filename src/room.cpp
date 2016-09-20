#include <room.hpp>

Room::Room(const glm::uvec2 &size, const mos::Model &floor,
           const mos::Model &wall, const mos::Model &corner)
    : floor_(floor), wall_(wall), corner_(corner), size_(size) {}

mos::Model Room::model() {
  out_model_.models.clear();
  for (float x = 0; x < size_.x; x++) {
    for (float y = 0; y < size_.y; y++) {
      auto m = floor_;
      m.position(glm::vec3(x, y, 0.0f));
      out_model_.models.push_back(m);
    }
  }
  return out_model_;
}
