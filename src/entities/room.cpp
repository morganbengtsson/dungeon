#include <entities/room.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <mos/util.hpp>
#include <algorithm.hpp>

Room::Room(mos::Assets &assets, const glm::mat4 &transform) {
  room_.transform = transform;
  size_.x = simplex_int(room_.position(), 3, 6);
  size_.y = simplex_int(room_.position() * .5f, 3, 6);

  const auto entry_pos = mos::position(transform);

  room_type = simplex_int(entry_pos, 0, 3);

  //TODO: Move to own class.
  std::vector<mos::Model> floor_models;
  std::vector<mos::Model> edge_models;
  mos::Model corner_model;
  mos::Model entry_model;

  if (room_type == 2) {
    corner_model = assets.model("room_corner.model");
    entry_model = assets.model("room_entry.model");
    floor_models = {assets.model("room_floor.model")};
    edge_models = {assets.model("room_edge0.model"),
                   assets.model("room_edge1.model"),
                   assets.model("room_edge2.model"),
                   assets.model("room_edge3.model"),
                   assets.model("room_edge4.model")};
  } else if (room_type == 1) {
    corner_model = assets.model("room_corner_metal.model");
    entry_model = assets.model("room_entry_metal.model");
    floor_models = {assets.model("room_floor_metal.model")};
    edge_models = {assets.model("room_edge_metal0.model"),
                   assets.model("room_edge_metal1.model")};
  } else if (room_type == 0) {
    corner_model = assets.model("room_corner_wood.model");
    entry_model = assets.model("room_entry_wood.model");
    floor_models = {assets.model("room_floor_wood.model")};
    edge_models = {assets.model("room_edge_wood0.model"),
                   assets.model("room_edge_wood1.model")};
  }

  // Items
  const std::vector<mos::Model> items{assets.model("plant.model"),
                                      assets.model("table.model"),
                                      assets.model("package.model")};

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

  int left = simplex_int(room_.position() * 0.5f, 1, size_.x - 1);
  int right = simplex_int(room_.position(), 1, size_.x - 1);

  for (float x = 1.0f; x < (size_.x - 1.0f); x++) {
    const auto t0 = glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, .0f, .0f}),
                                glm::half_pi<float>(),
                                {.0f, .0f, 1.f});
    const auto t1 = glm::rotate(glm::translate(glm::mat4(1.0f), {x + .5f, size_.y - 1.0f, .0f}),
                                -glm::half_pi<float>(),
                                {.0f, .0f, 1.f});

    auto edge_model = edge_models[simplex_int(mos::position(t0), 0, edge_models.size())];
    auto floor_model = floor_models[0];
    if (x != float(left)) {
      edge_model.transform = t0;
      room_.models.push_back(edge_model);
    } else {
      floor_model.transform = t0;
      room_.models.push_back(floor_model);
    }
    if (x != float(right)) {
      edge_model = edge_models[simplex_int(mos::position(t1), 0, edge_models.size())];
      edge_model.transform = t1;
      room_.models.push_back(edge_model);
    } else {
      floor_model.transform = t1;
      room_.models.push_back(floor_model);
    }
    /*


    */


    for (float y = 1; y < (size_.y - 1.f); y++) {

      auto floor_pos = glm::vec3(x + 0.5f, y, 0.0f);
      floor_model.position(floor_pos);
      room_.models.push_back(floor_model);

      if (simplex_bool(entry_pos + floor_pos)) {
        auto item = items[simplex_int(entry_pos + floor_pos, 0, items.size())];
        item.position(floor_pos);
        items_.push_back(item);
      }

      const auto t0 = glm::rotate(glm::translate(glm::mat4(1.0f), {0.5f, y, .0f}), 0.0f, {.0f, .0f, 1.f});
      edge_model = edge_models[simplex_int(mos::position(t0), 0, edge_models.size())];
      edge_model.transform = t0;
      room_.models.push_back(edge_model);

      const auto t1 =
          glm::rotate(glm::translate(glm::mat4(1.0f), {size_.x - 0.5f, y, .0f}), glm::pi<float>(), {.0f, .0f, 1.f});
      edge_model = edge_models[simplex_int(mos::position(t1), 0, edge_models.size())];
      edge_model.transform = t1;
      room_.models.push_back(edge_model);
    }
  }

  box_ = mos::Box::create_from_model(room_);
  box_.extent -= 0.01;

  exits.push_back(
      Door(assets, transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(size_.x, 0.0f, 0.0f))));

  exits.push_back(
      Door(assets, transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((left) + 0.5f, -0.5f, 0.0f))
          * glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

  exits.push_back(
      Door(assets, transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((right) + 0.5f, float(size_.y) - 0.5f, 0.0f)) *
          glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

}

mos::Model Room::model() {
  auto r = room_;
  r.models.insert(r.end(), items_.begin(), items_.end());
  return r;
}

void Room::print(std::ostream &os) {
  os << "Room, " << "type: " << room_type;
}
void Room::update(const float dt) {

}

