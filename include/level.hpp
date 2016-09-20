#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <mos/assets.hpp>
#include <mos/render/model.hpp>
#include <room.hpp>

class Level {
public:
  using Models = std::vector<mos::Model>;
  using Rooms = std::vector<Room>;
  Level(mos::Assets &assets);
  ~Level();
  void update(const float dt);
  Models models();
private:
  Rooms rooms_;
  Models out_models_;
};

#endif // LEVEL_HPP
