#include <right_turn.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/io.hpp>

RightTurn::RightTurn(const glm::vec3 &position, const glm::vec2 &previous_direction,
                   const mos::Model &model) : model_(model), previous_direction_(previous_direction) {


  model_.position(position);
  direction_ = glm::rotate(previous_direction, -glm::half_pi<float>());

  if (previous_direction.x == 1.0f) {
  }
  else if (previous_direction.x == -1.0f) {
    model_.transform *= glm::rotate(glm::mat4(1.0f), glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));
  }
  else if (previous_direction.y == 1.0f) {
    model_.transform *= glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));
  }
  else {
    model_.transform *= glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f));
  }
}

mos::Model RightTurn::model() {
    return model_;
}

glm::vec3 RightTurn::end() {
  auto out = model_.position() + glm::vec3(direction_ * 2.0f, 0.0f) + glm::vec3(previous_direction_, 0.0f);
  return out;
}

glm::vec2 RightTurn::direction() const {
    return direction_;
}
