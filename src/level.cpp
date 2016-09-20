#include <level.hpp>
#include <mos/util.hpp>

Level::Level(mos::Assets &assets) {
  auto m = assets.model("floor.model");
  rooms_.push_back(Room(glm::uvec2(4, 4), m, m, m));
}

Level::~Level() {
}

void Level::update(const float dt) {
}

Level::Models Level::models(){
  out_models_.clear();
  out_models_.push_back(rooms_[0].model());
  return out_models_;
}

