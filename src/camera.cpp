#include <camera.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::uvec2 &resolution)
    : camera_(glm::vec3(0.0f, -50.0f, 50.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 200.0f))
{}

mos::Camera Camera::camera() const {
  return camera_;
}

void Camera::update(const float dt) {
  auto p = camera_.position();
  auto c = camera_.center();
  const float speed = 10.0f;
  if (forward) {
    p.y += dt * speed;
    c.y += dt * speed;
  }
  if (backward) {
    p.y -= dt * speed;
    c.y -= dt * speed;
  }
  if (left) {
    p.x += dt * speed;
    c.x += dt * speed;
  }
  if (right) {
    p.x -= dt * speed;
    c.x -= dt * speed;
  }
  camera_.position(p);
  camera_.center(c);
}
