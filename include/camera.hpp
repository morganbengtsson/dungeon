#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <mos/render/camera.hpp>

class Camera {
public:
  Camera(const glm::uvec2 &resolution);
  mos::Camera camera() const;
  void update(const float dt);
  bool rotate_left;
  bool rotate_right;
  bool zoom_in;
  bool zoom_out;
private:
  glm::vec3 velocity_;
  glm::vec3 offset_;
  float angular_velocity_;
  mos::Camera camera_;
};

#endif // CAMERA_HPP
