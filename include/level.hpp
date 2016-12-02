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
#include <stairs.hpp>
#include <stairs_down.hpp>
#include <room.hpp>
#include <future>

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
  void camera_zoom_in(const bool zoom_in);
  void camera_zoom_out(const bool zoom_out);
  Models models();
  Boxes boxes();
  mos::Camera camera() const;
private:
  Entity::SharedEntity create_entity(const glm::mat4 & transform);
  Camera camera_;
  float time_;
  int times_;
  Entities entities_;
  mos::Model corridor_;
  mos::Model stairs_;
  mos::Model stairs_down_;
  Models out_models_;
  std::future<void> load_;
};

#endif // LEVEL_HPP
