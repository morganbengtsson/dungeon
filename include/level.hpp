#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <mos/assets.hpp>
#include <mos/render/camera.hpp>
#include <mos/render/model.hpp>
#include <mos/render/render_box.hpp>
#include <corridor.hpp>
#include <door.hpp>
#include <camera.hpp>

class Level {
public:
  using Boxes = std::vector<mos::RenderBox>;
  using Models = std::vector<mos::Model>;
  using Entities = std::vector<std::shared_ptr<Entity>>;
  using Doors = std::vector<Door>;
  Level(mos::Assets &assets, const glm::vec2 &resolution);
  ~Level();
  void update(const float dt);
  void camera_left(const bool left);
  void camera_right(const bool right);
  void camera_forward(const bool forward);
  void camera_backward(const bool backward);
  Models models();
  Boxes boxes();
  mos::Camera camera() const;
private:
  Camera camera_;
  float time_;
  Entities entities_;
  mos::Model corridor_;
  mos::Model stairs_;
  mos::Model left_turn_;
  mos::Model right_turn_;
  Models out_models_;
};

#endif // LEVEL_HPP
