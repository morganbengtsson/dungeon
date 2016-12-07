#include <entity.hpp>

bool Entity::intersects(const Entity &entity) const {
  if (box_.intersects(entity.box_)) {
    return true;
  }
  return false;
}

mos::Box Entity::box() const {
  return box_;
}

std::ostream &operator<<(std::ostream &os, Entity &e) {
  e.print(os);
  return os;
}
