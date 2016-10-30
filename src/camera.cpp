#include <camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <glm/gtx/io.hpp>

Camera::Camera(const glm::uvec2 &resolution)
    : left(false), right(false), forward(false), backward(false),
      zoom_in(false), zoom_out(false), velocity_(0.0f),
      camera_(glm::vec3(0.0f, -1.0f, 50.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 200.0f)) {}

mos::Camera Camera::camera() const { return camera_; }

void Camera::update(const float dt) {

  const float acceleration = 10.0f;
  if (forward) {
    velocity_.y += dt * acceleration;
  }
  if (backward) {
    velocity_.y -= dt * acceleration;
  }
  if (left) {
    velocity_.x += dt * acceleration;
  }
  if (right) {
    velocity_.x -= dt * acceleration;
  }

  if (zoom_in) {
    velocity_ += camera_.direction() * dt * acceleration;
  }
  if (zoom_out) {
    velocity_ -= camera_.direction() * dt * acceleration;
  }

  velocity_ *= 0.99f;

  auto p = camera_.position();
  auto c = camera_.center();
  camera_.position(p + velocity_ * dt);
  camera_.center(c + velocity_ * dt);
}
