#include <room.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/io.hpp>
#include <iostream>

Room::Room(const glm::vec3 &position,
           const mos::Model &floor,
           const mos::Model &wall,
           const mos::Model &corner)
    : position_(position), floor_(floor), wall_(wall), corner_(corner),
      size_(10, 10){
  size_ = glm::uvec2(int(glm::abs(glm::simplex(position_)) * 10));

  out_model_.models.clear();

  for (int x = 0; x < 10; x++) {
    auto m = floor_;
    m.position(glm::vec3(x, 5.0f, 0.0f));
    out_model_.models.push_back(m);
  }
  for (int y = 0; y < 10; y++){
    auto m = floor_;
    m.position(glm::vec3(5.0f, y, 0.0f));
    out_model_.models.push_back(m);
  }
  for (int x = (10 - size_.x) / 2; x < (10 + size_.x)/2; x++) {
    for (int y = (10 - size_.y) / 2; y < (10 + size_.y)/2; y++) {
      auto m = floor_;
      auto x0 = x;
      auto y0 = y;
      m.position(glm::vec3(x0, y0, 0.0f));
      out_model_.models.push_back(m);
    }
  }
  out_model_.transform = glm::translate(glm::mat4(1.0f), position_);
}

void Room::update(const float dt) {
  time_ += dt;
}

mos::Model Room::model() {

  return out_model_;
}
