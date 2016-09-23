#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <mos/assets.hpp>
#include <mos/render/camera.hpp>
#include <mos/render/model.hpp>
#include <room.hpp>
#include <corridor.hpp>
#include <door.hpp>

class Level {
public:
  using Models = std::vector<mos::Model>;
  using Rooms = std::vector<Room>;
  using Corridors = std::vector<Corridor>;
  Level(mos::Assets &assets, const glm::vec2 &resolution);
  ~Level();
  void update(const float dt, const glm::bvec4 &camera_movement);
  Models models();
  mos::Camera camera;
private:
  Corridors corridors_;
  mos::Model m_;
  Models out_models_;
};

#endif // LEVEL_HPP
