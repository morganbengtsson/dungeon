#include <left_turn.hpp>
#include <glm/gtx/rotate_vector.hpp>

LeftTurn::LeftTurn(const glm::vec3 &position, const glm::vec2 &previous_direction,
                   const mos::Model &model) : model_(model) {
  model_.position(position);
  direction_ = previous_direction;
}

mos::Model LeftTurn::model() {
    return model_;
}

glm::vec3 LeftTurn::end() {
  auto left = glm::rotate(direction_, -glm::half_pi<float>());
  return model_.position() + glm::vec3(direction_, 0.0f) + glm::vec3(left, 0.0f);
}

glm::vec2 LeftTurn::direction() {
    return direction_;
}
