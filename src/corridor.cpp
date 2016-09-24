#include <array>
#include <corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/random.hpp>

Corridor::Corridor(const glm::vec3 &position,
                   const glm::vec2 &previous_direction,
                   const mos::Model &floor)
    : floor_(floor) {
  model_.position(position);
  auto noise = glm::simplex(position * 1000000.0f);
  auto n = int(glm::roundEven(noise));
  direction_ = glm::rotate(previous_direction, n * glm::half_pi<float>());
  length_ = 3;
  auto m = floor;

  for (float i = 0; i < length_; i++) {
    m.position(glm::vec3(direction_, 0.0f) * i);
    model_.models.push_back(m);
  }
}

mos::Model Corridor::model() { return model_; }

glm::vec3 Corridor::end() {
  return model_.position() + glm::vec3(direction_, 0.0f) * length_;
}

glm::vec2 Corridor::direction() const {
  return direction_;
}
