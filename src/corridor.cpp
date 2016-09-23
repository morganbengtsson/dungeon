#include <corridor.hpp>

Corridor::Corridor(const glm::vec3 &position, const mos::Model &floor) {
  model_.position(position);

  auto m = floor;
  m.position(glm::vec3(0.0f));
  model_.models.push_back(m);
  m.position(glm::vec3(1.0f, 0.0f, 0.0f));
  model_.models.push_back(m);
  m.position(glm::vec3(2.0f, 0.0f, 0.0f));
  model_.models.push_back(m);
}

mos::Model Corridor::model() { return model_; }
