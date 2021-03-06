#include <array>
#include <entities/corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <algorithm.hpp>

Corridor::Corridor(mos::Assets &assets, const glm::mat4 &transform, const int min_length, const int max_length)
    : floor_(assets.model("corridor.model")) {
  model_.transform = transform;

  length_ = simplex_range(model_.position(), min_length, max_length);
  auto m = floor_;

  for (float i = 0; i < length_; i++) {
    m.position(glm::vec3(i + 0.5f, 0.0f, 0.0f));
    model_.models.push_back(m);
  }
  exits.push_back(
      Door(assets, transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, 0.0f))));

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.001;
}

mos::Model Corridor::model() { return model_; }

void Corridor::print(std::ostream &os) {
  os << "Corridor";
}
void Corridor::update(const float dt) {

}
