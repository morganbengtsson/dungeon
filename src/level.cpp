#include <level.hpp>
#include <mos/util.hpp>

Level::Level(mos::Assets &assets) {
  auto m = assets.model("floor.model");
  rooms_.push_back(Room(glm::vec3(0.0f), glm::uvec2(4, 4), m, m, m));
}

Level::~Level() {
}

void Level::update(const float dt) {
  for (auto &room : rooms_){
    room.update(dt);
  }
}

Level::Models Level::models(){
  out_models_.clear();
  out_models_.push_back(rooms_[0].model());
  return out_models_;
}

