#include <room.hpp>
#include <glm/gtc/noise.hpp>
#include <iostream>

Room::Room(const glm::vec3 &position,
           const mos::Model &floor,
           const mos::Model &wall,
           const mos::Model &corner)
    : position_(position), floor_(floor), wall_(wall), corner_(corner),
      size_(10, 10){
  size_ = glm::uvec2(int(glm::abs(glm::simplex(position_)) * 10));
}

void Room::update(const float dt) {
  time_ += dt;
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
  return out_model_;
}
