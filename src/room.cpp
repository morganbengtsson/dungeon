#include <room.hpp>
#include <glm/gtc/noise.hpp>

Room::Room(const glm::mat4 &transform, const mos::Model &model) : model_(model) {
    model_.transform = transform;
    //size_.x = uint(glm::abs(glm::simplex(model_.position()) * 10.0f + 5.0f)) + 1.0f;
    //size_.y = uint(glm::abs(glm::simplex(model_.position()) * 10.0f + 5.0f)) + 1.0f;
    //model_.transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size_.x, size_.y, 1.0f));
    std::cout << *this << std::endl;
    //box_.extent = glm::vec3(size_.x / 2.0f, size_.y / 2.0f, 1.0f);
    box_.extent = glm::vec3(0.5f, 0.5, 0.1f);
    box_.position = model_.position() + glm::vec3(0.5f, 0.0f, 0.0f);
    box_.extent -= 0.01f;
}

mos::Model Room::model() {
    return model_;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
  os  << " size: " << room.size_;
  return os;
}