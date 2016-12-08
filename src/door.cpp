#include <door.hpp>

Door::Door(mos::Assets &assets, const glm::mat4 &transform) : transform(transform), model_(assets.model("door.model")) {
}

mos::Model Door::model() const {
  return model_;
}
