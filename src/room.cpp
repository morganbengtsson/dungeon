#include <room.hpp>
#include <glm/gtc/noise.hpp>

mos::Assets Room::assets_;

Room::Room(const glm::mat4 &transform){
  room_.transform = transform;
  size_.x = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 2.0f;
  size_.y = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 2.0f;

  size_ = {3,3};

  auto m = assets_.model("room_floor.model");
  auto e = assets_.model("room_edge.model");

  for (float x = 0; x < size_.x; x++) {
    e.transform =  glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, .0f, .0f}), glm::half_pi<float>(), {.0f, .0f, 1.f});
    room_.models.push_back(e);

    e.transform =  glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, size_.y - 1.0f, .0f}), -glm::half_pi<float>(), {.0f, .0f, 1.f});
    room_.models.push_back(e);

    for(float y = 1; y  < (size_.y - 1.f); y++) {
      m.position(glm::vec3(x + 0.5f, y, 0.0f));
      room_.models.push_back(m);
    }
  }

  //model_.transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size_.x, size_.y, 1.0f));

  box_ = mos::Box::create_from_model(room_);
  std::cout << box_.extent << std::endl;
  box_.extent -= 0.01;

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(size_.x, 0.0f, 0.0f))));

  //uint right = uint((glm::abs(glm::simplex(model_.position())) * length_));

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((size_.x / 2) + 0.5f, -0.5f, 0.0f))
          * glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

  //uint left = uint((glm::abs(glm::simplex(model_.position())) * length_));

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((size_.x / 2) + 0.5f, float(size_.y) - 0.5f, 0.0f)) *
          glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

}

mos::Model Room::model() {
  return room_;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
  os << " size: " << room.size_;
  return os;
}

