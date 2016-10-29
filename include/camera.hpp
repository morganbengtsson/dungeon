#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <mos/render/camera.hpp>

class Camera {
public:
  Camera(const glm::uvec2 &resolution);
  mos::Camera camera() const;
  void update(const float dt);
  bool left;
  bool right;
  bool forward;
  bool backward;
  bool zoom_in;
  bool zoom_out;
private:
  glm::vec3 velocity_;
  mos::Camera camera_;
};

#endif // CAMERA_HPP
