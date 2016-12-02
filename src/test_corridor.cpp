#include <array>
#include <test_corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <mos/util.hpp>

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
    t *= glm::rotate(glm::mat4(1.0f), glm::linearRand(-0.2f, 0.2f), glm::vec3(0.0f, 0.0f, 1.0f));
    t *= glm::rotate(glm::mat4(1.0f), glm::linearRand(-0.2f, 0.2f), glm::vec3(0.0f, 1.0f, 0.0f));

    if (glm::simplex(m.position()) > 0.0f) {
      auto p = mos::position(t);
      exits.push_back(
          Door(transform *
              glm::translate(glm::mat4(1.0f), p) *
              glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.5f, 0.0f)) *
              glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    }
    if (glm::simplex(m.position()) > 0.0f) {
      auto p = mos::position(t);
      exits.push_back(
          Door(transform *
              glm::translate(glm::mat4(1.0f), p) *
              glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.5f, 0.0f)) *
              glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    }

  }
  //t *= glm::translate(glm::mat4(1.0f), glm::vec3(1.0, 0.0f, 0.0f));
  //t *= glm::rotate(glm::mat4(1.0f), 0.2f, glm::vec3(0.0f, 0.0f, 1.0f));
  auto p = mos::position(t);
  exits.push_back(Door(transform * glm::translate(glm::mat4(1.0f), p)));

  //model_.overlay(glm::linearRand(glm::vec4(0.0f), glm::vec4(1.0f)));

  //auto shadow = (model_.position().z + 6.0f) / 12.0f;

  //model_.overlay(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f - shadow));

  box_ = mos::Box::create_from_model(model_);
  box_.extent.x *= 0.7;
  box_.extent.y *= 0.7;
}

mos::Model TestCorridor::model() { return model_; }
