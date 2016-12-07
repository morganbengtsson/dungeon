#include <room.hpp>
#include <glm/gtc/noise.hpp>
#include <mos/util.hpp>
#include <algorithm.hpp>

Room::Room(mos::Assets &assets, const glm::mat4 &transform) {
  room_.transform = transform;
  size_.x = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 3.0f;
  size_.y = int(glm::abs(glm::simplex(room_.position()) * 5.0f)) + 3.0f;

  //size_ = {3, 3};

  const auto entry_pos = mos::position(transform);

  room_type = simplex_index(entry_pos, 4);

  //TODO: Move to own class.
  std::vector<mos::Model> floor_models;
  std::vector<mos::Model> edge_models;
  mos::Model corner_model;
  mos::Model entry_model;

  if ((room_type == 1) || (room_type == 0)) {
    corner_model = assets.model("room_corner.model");
    entry_model = assets.model("room_entry.model");
    floor_models = {assets.model("room_floor.model")};
    edge_models = {assets.model("room_edge1.model"),
                   assets.model("room_edge1.model"),
                   assets.model("room_edge2.model"),
                   assets.model("room_edge3.model"),
                   assets.model("room_edge4.model")};
  }
  else if (room_type == 2) {
    corner_model = assets.model("room_corner_metal.model");
    entry_model = assets.model("room_entry_metal.model");
    floor_models = {assets.model("room_floor_metal.model")};
    edge_models = {assets.model("room_edge_metal0.model")};
  }
  else if (room_type == 3) {
    corner_model = assets.model("room_corner_wood.model");
    entry_model = assets.model("room_entry_wood.model");
    floor_models = {assets.model("room_floor_wood.model")};
    edge_models = {assets.model("room_edge_wood0.model")};
  }
  else {
    corner_model = assets.model("room_corner.model");
    entry_model = assets.model("room_entry.model");
    floor_models = {assets.model("room_floor.model")};
    edge_models = {assets.model("room_edge1.model")};
  }

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

    auto & edge_model = edge_models[simplex_index(mos::position(t1),edge_models.size())];
    auto & floor_model = floor_models[0];
    if (x != float(size_.x / 2)) {
      edge_model.transform = t0;
      room_.models.push_back(edge_model);

      edge_model = edge_models[simplex_index(mos::position(t1),edge_models.size())];
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

      const auto t0 = glm::rotate(glm::translate(glm::mat4(1.0f), {0.5f, y, .0f}), 0.0f, {.0f, .0f, 1.f});
      edge_model = edge_models[simplex_index(mos::position(t1),edge_models.size())];
      edge_model.transform = t0;
      room_.models.push_back(edge_model);

      const auto t1 = glm::rotate(glm::translate(glm::mat4(1.0f), {size_.x - 0.5f, y, .0f}), glm::pi<float>(), {.0f, .0f, 1.f});
      edge_model = edge_models[simplex_index(mos::position(t1),edge_models.size())];
      edge_model.transform = t1;
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

void Room::print(std::ostream &os) {
  os << "Room, " << "type: " << room_type;
}

