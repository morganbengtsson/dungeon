#include <entities/stairs.hpp>
#include <glm/gtc/noise.hpp>
#include <algorithm.hpp>

Stairs::Stairs(mos::Assets &assets, const glm::mat4 &transform, const int min_length, const int max_length) {
  model_.transform = transform;
  length_ = simplex_range(model_.position(), min_length, max_length);

  exits.push_back(
      Door(assets, transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, length_))));

  for (int i = 0; i < length_; i++) {
    auto m = assets.model("stairs.model");
    m.transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, i));
    model_.models.push_back(m);
  }

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.001;
}

mos::Model Stairs::model() { return model_; }

void Stairs::print(std::ostream &os) {
  os << "Stairs";
}
void Stairs::update(const float dt) {

}
