#include <array>
#include <corridor.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/rotate_vector.hpp>

Corridor::Corridor(const glm::mat4 &transform, const mos::Model &floor)
    : floor_(floor) {

  model_.transform = transform;

  length_ = uint((glm::abs(glm::simplex(model_.position()))) * 10.0f + 1.0f);
  auto m = floor;

  for (float i = 0; i < length_; i++) {
    m.position(glm::vec3(i, 0.0f, 0.0f));
    model_.models.push_back(m);
  }
  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(length_, 0.0f, 0.0f))));

  uint right = uint((glm::abs(glm::simplex(model_.position())) * length_));
  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(0.5f + right, -0.5f, 0.0f)) *
           glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));


  uint left = uint((glm::abs(glm::simplex(model_.position())) * length_));
  exits.push_back(
      Door(transform *
           glm::translate(glm::mat4(1.0f), glm::vec3(0.5f + left, 0.5f, 0.0f)) *
           glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

  model_.overlay(glm::linearRand(glm::vec4(0.0f), glm::vec4(1.0f)));

  std::vector<mos::Vertex> all_vertices;

  //TODO: Generalize
  for (auto & m : model_.models) {
    for (auto &v0 : m.mesh->vertices()) {
      auto vt0 = v0;
      vt0.position = glm::vec3(transform * m.transform * glm::vec4(v0.position, 1.0f));
      all_vertices.push_back(vt0);
    }
  }
  box_ = mos::Box(all_vertices.begin(), all_vertices.end(), glm::mat4(1.0f));
  box_.extent -= 0.001;
}

mos::Model Corridor::model() { return model_; }
