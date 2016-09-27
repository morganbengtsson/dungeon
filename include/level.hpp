#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <mos/assets.hpp>
#include <mos/render/camera.hpp>
#include <mos/render/model.hpp>
#include <room.hpp>
#include <corridor.hpp>
#include <stairs.hpp>
#include <door.hpp>
#include <left_turn.hpp>
#include <right_turn.hpp>

class Level {
public:
  using Models = std::vector<mos::Model>;
  using Rooms = std::vector<Room>;
  using Entities = std::vector<std::shared_ptr<Entity>>;
  using Doors = std::vector<Door>;
  Level(mos::Assets &assets, const glm::vec2 &resolution);
  ~Level();
  void update(const float dt, const glm::bvec4 &camera_movement);
  Models models();
  mos::Camera camera;
private:
  float time_;
  Entities entities_;
  mos::Model corridor_;
  mos::Model stairs_;
  mos::Model left_turn_;
  mos::Model right_turn_;
  Models out_models_;
};

#endif // LEVEL_HPP
