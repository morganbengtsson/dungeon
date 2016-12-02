#include <array>
#include <test_corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/rotate_vector.hpp>

TestCorridor::TestCorridor(const glm::mat4 &transform, const mos::Model &floor)
    : floor_(floor) {
  model_.transform = transform;

  length_ = uint((glm::abs(glm::simplex(model_.position()))) * 10.0f + 1.0f);
  auto m = floor;

  auto t = glm::mat4(1.0f);

  for (float i = 0; i < length_; i++) {
    m.transform = t;
    model_.models.push_back(m);
    t *= glm::translate(glm::vec3(1.0f, 0.0f, 0.0f));
  }
  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, 0.0f))));

  model_.overlay(glm::linearRand(glm::vec4(0.0f), glm::vec4(1.0f)));

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.001;
}

mos::Model TestCorridor::model() { return model_; }
