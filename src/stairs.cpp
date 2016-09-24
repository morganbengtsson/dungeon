#include <stairs.hpp>

Stairs::Stairs(const glm::vec3 &position,
               const glm::vec2 &previous_position,
               const mos::Model &model) :
  model_(model), direction_(-1.0f, 0.0f){
    model_.position(position);
}

mos::Model Stairs::model() { return model_; }

glm::vec3 Stairs::end() {
  return model_.position() + glm::vec3(direction_ * 3.0f, 1.0f);
}

glm::vec2 Stairs::direction() const { return direction_; }
