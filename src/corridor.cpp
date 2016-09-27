#include <array>
#include <corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/rotate_vector.hpp>

Corridor::Corridor(const glm::mat4 &transform, const mos::Model &floor)
    : floor_(floor) {
  model_.transform = transform;

  length_ = glm::linearRand(1, 5);
  auto m = floor;

  for (float i = 0; i < length_; i++) {
    m.position(glm::vec3(i, 0.0f, 0.0f));
    model_.models.push_back(m);
  }
  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, 0.0f))));

  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, -0.5f, 0.0f))*
           glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

  model_.overlay(glm::linearRand(glm::vec4(0.0f), glm::vec4(1.0f)));
}

mos::Model Corridor::model() { return model_; }
