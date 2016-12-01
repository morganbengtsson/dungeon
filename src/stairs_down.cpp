#include <stairs_down.hpp>
#include <glm/gtc/noise.hpp>

StairsDown::StairsDown(const glm::mat4 &transform,
               const mos::Model model,
const unsigned int max_length)
    : model_(model) {
  model_.transform = transform;
  length_ = uint((glm::abs(glm::simplex(model_.position()))) * max_length + 1.0f);

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, -length_))));

  auto vertices = model_.mesh->vertices();
  for (auto &v : vertices) {
    v.position = glm::vec3(transform * glm::vec4(v.position, 1.0f));
  }

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.01f;
}

mos::Model StairsDown::model() { return model_; }
