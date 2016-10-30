#include <stairs.hpp>
#include <glm/gtc/noise.hpp>

Stairs::Stairs(const glm::mat4 &transform, const mos::Model model)
    : model_(model) {
  model_.transform = transform;
  length_ = uint((glm::abs(glm::simplex(model_.position()))) * 10.0f + 1.0f);

  model_.transform *= glm::scale(glm::mat4(1.0f), glm::vec3(length_, 1.0f, length_));

  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, length_))));

}

mos::Model Stairs::model() { return model_; }
