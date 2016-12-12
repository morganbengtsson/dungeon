#include <camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <glm/gtx/io.hpp>
#include <glm/gtx/rotate_vector.hpp>

Camera::Camera(const glm::uvec2 &resolution)
    : rotate_left(false), rotate_right(false),
      zoom_in(false), zoom_out(false), velocity_(0.0f), angular_velocity_(0.2f),
      offset_(-20.0f, -20.0f, 50.0f),
      camera_(offset_, glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 200.0f)) {}

mos::Camera Camera::camera() const { return camera_; }

void Camera::update(const float dt) {
  if (zoom_in) {
    offset_ += camera_.direction() * dt * 10.0f;
  }
  if (zoom_out) {
    offset_ -= camera_.direction() * dt * 10.0f;
  }

  offset_ = glm::rotateZ(offset_, angular_velocity_ * dt);
  camera_.position(offset_ + camera_.center());
}
