#include <level.hpp>
#include <mos/util.hpp>

Level::Level(mos::Assets &assets) {
  auto m = assets.model("floor.model");
  for (int i = 0 ; i < 500; i += 10){
  rooms_.push_back(Room(glm::vec3(i, 0.0f, 0.0f), m, m, m));
  }
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
  for (auto & r : rooms_){
    out_models_.push_back(r.model());
  }
  return out_models_;
}

