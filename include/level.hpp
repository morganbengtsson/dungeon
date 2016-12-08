#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <mos/assets.hpp>
#include <mos/render/camera.hpp>
#include <mos/render/model.hpp>
#include <mos/render/render_box.hpp>
#include <entities/corridor.hpp>
#include <entities/door.hpp>
#include <camera.hpp>
#include <entities/stairs.hpp>
#include <entities/stairs_down.hpp>
#include <entities/test_corridor.hpp>
#include <entities/room.hpp>
#include <entities/elevator.hpp>
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
  Entity::SharedEntity create_entity(mos::Assets &assets, const glm::mat4 &transform);
  Camera camera_;
  float time_;
  mos::Model floor_;
  mos::Model stairs_;
  mos::Model stairs_down_;
  Entities entities_;
  Models out_models_;
  std::future<void> load_;
};

#endif // LEVEL_HPP
