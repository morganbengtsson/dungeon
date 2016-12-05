#include <room.hpp>
#include <glm/gtc/noise.hpp>
#include <mos/util.hpp>

mos::Assets Room::assets_;

Room::Room(const glm::mat4 &transform) {
  room_.transform = transform;
  size_.x = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 2.0f;
  size_.y = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 2.0f;

  //size_ = {3, 3};

  const auto entry_pos = mos::position(transform);

  auto floor_model = assets_.model("room_floor.model");
  auto edge_model = assets_.model("room_edge.model");
  auto edge_model1 = assets_.model("room_edge1.model");
  edge_model = edge_model1;
  auto corner_model = assets_.model("room_corner.model");
  auto entry_model = assets_.model("room_entry.model");

  //Entry door
  entry_model.transform = glm::rotate(glm::translate(glm::mat4(1.0f), {.5f, .0f, .0f}), 0.0f, {.0f, .0f, 1.f});
  room_.models.push_back(entry_model);

  //Exit door
  entry_model.transform =
      glm::rotate(glm::translate(glm::mat4(1.0f), {size_.x - .5f, .0f, .0f}), 0.0f, {.0f, .0f, 1.f});
  room_.models.push_back(entry_model);

  corner_model.transform =
      glm::rotate(glm::translate(glm::mat4(1.0f), {0.5f, size_.y - 1.0f, .0f}), 0.0f, {.0f, .0f, 1.f});
  room_.models.push_back(corner_model);

  corner_model.transform = glm::rotate(glm::translate(glm::mat4(1.0f), {size_.x - 0.5f, size_.y - 1.0f, .0f}),
                                       -glm::half_pi<float>(),
                                       {.0f, .0f, 1.f});
  room_.models.push_back(corner_model);

  for (float x = 1.0f; x < (size_.x - 1.0f); x++) {
    const auto t0 = glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, .0f, .0f}),
                                glm::half_pi<float>(),
                                {.0f, .0f, 1.f});
    const auto t1 = glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, size_.y - 1.0f, .0f}),
                                -glm::half_pi<float>(),
                                {.0f, .0f, 1.f});

    if (x != float(size_.x / 2)) {
      edge_model.transform = t0;
      room_.models.push_back(edge_model);

      edge_model.transform = t1;
      room_.models.push_back(edge_model);
    } else {
      floor_model.transform = t0;
      room_.models.push_back(floor_model);

      floor_model.transform = t1;
      room_.models.push_back(floor_model);
    }

    for (float y = 1; y < (size_.y - 1.f); y++) {

      floor_model.position(glm::vec3(x + 0.5f, y, 0.0f));
      room_.models.push_back(floor_model);

      edge_model.transform = glm::rotate(glm::translate(glm::mat4(1.0f), {0.5f, y, .0f}), 0.0f, {.0f, .0f, 1.f});
      room_.models.push_back(edge_model);

      edge_model.transform =
          glm::rotate(glm::translate(glm::mat4(1.0f), {size_.x - 0.5f, y, .0f}), glm::pi<float>(), {.0f, .0f, 1.f});
      room_.models.push_back(edge_model);
    }
  }

  box_ = mos::Box::create_from_model(room_);
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

