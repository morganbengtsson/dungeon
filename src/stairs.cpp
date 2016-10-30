#include <stairs.hpp>
#include <glm/gtc/noise.hpp>

Stairs::Stairs(const glm::mat4 &transform, const mos::Model model)
    : model_(model) {
  model_.transform = transform;
  //length_ = uint((glm::abs(glm::simplex(model_.position()))) * 10.0f + 1.0f);
  length_ = 1;

  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, length_))));

  auto vertices = model_.mesh->vertices();
  for (auto &v : vertices) {
    v.position = glm::vec3(transform * glm::vec4(v.position, 1.0f));
  }

  box_ = mos::Box(vertices.begin(), vertices.end(), glm::mat4(1.0f));
  box_.extent -= 0.01f;
}

mos::Model Stairs::model() { return model_; }
