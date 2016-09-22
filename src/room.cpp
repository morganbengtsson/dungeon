#include <room.hpp>
#include <glm/gtc/noise.hpp>
#include <iostream>

Room::Room(const glm::vec3 &position, const glm::uvec2 &size,
           const mos::Model &floor, const mos::Model &wall,
           const mos::Model &corner)
    : position_(position), floor_(floor), wall_(wall), corner_(corner),
      size_(size), time_(0.0f) {}

void Room::update(const float dt) {
  time_ += dt;
  if (time_ > 3.0f && !next) {
    auto p = position_ + glm::vec3(3.0f, 0.0f, 0.0f);
    int n = int(glm::clamp(glm::abs(glm::perlin(p * 1.45f) * 10.0f), 1.0f, 10.0f));
    next = std::make_shared<Room>(p, glm::uvec2(n), floor_, floor_, floor_);
  }
  if (next){
    next->update(dt);
  }
}

mos::Model Room::model() {
  out_model_.models.clear();
  for (float x = 0; x < size_.x; x++) {
    for (float y = 0; y < size_.y; y++) {
      auto m = floor_;
      m.position(glm::vec3(x, y, 0.0f) + position_);
      out_model_.models.push_back(m);
    }
  }
  if (next) {
    out_model_.models.push_back(next->model());
  }
  return out_model_;
}
