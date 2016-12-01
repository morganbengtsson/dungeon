#include <stairs.hpp>
#include <glm/gtc/noise.hpp>

Stairs::Stairs(const glm::mat4 &transform,
               const mos::Model model,
               const unsigned int max_length) {
  model_.transform = transform;
  length_ = uint((glm::abs(glm::simplex(model_.position()))) * max_length + 1.0f);

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, length_))));

  for (int i = 0; i < length_; i++) {
    auto m = model;
    m.transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, i));
    model_.models.push_back(m);
  }

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.001;
}

mos::Model Stairs::model() { return model_; }
