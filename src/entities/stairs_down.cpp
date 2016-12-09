#include <entities/stairs_down.hpp>
#include <glm/gtc/noise.hpp>
#include <algorithm.hpp>

StairsDown::StairsDown(mos::Assets &assets, const glm::mat4 &transform, const unsigned int max_length) : length_(0) {
  model_.transform = transform;
  length_ = simplex_int(model_.position(), 1, max_length);

  exits.push_back(
      Door(assets, transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, -length_))));

  for (int i = 0; i < length_; i++) {
    auto m = assets.model("stairs_down.model");
    m.transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, -i));
    model_.models.push_back(m);
  }
  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.001;
}

mos::Model StairsDown::model() { return model_; }

void StairsDown::print(std::ostream &os) {
  os << "Stairs down.";
}
void StairsDown::update(const float dt) {

}
