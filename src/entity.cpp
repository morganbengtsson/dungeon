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
