#include <door.hpp>
#include <algorithm.hpp>
#include <mos/util.hpp>

Door::Door(mos::Assets &assets, const glm::mat4 &transform)
    : transform(transform), door_closed_(assets.model("door_closed.model")),
      door_open_(assets.model("door_open.model")) {
  door_closed_.transform = transform;
  door_open_.transform = transform;
  open = bool(simplex_range(mos::position(transform), 0, 2));
}

mos::Model Door::model() const {
  return open ? door_open_ : door_closed_;
}
