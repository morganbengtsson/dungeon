#include <algorithm>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/io.hpp>
#include <level.hpp>
#include <mos/util.hpp>
#include <queue>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), times_(0), camera_(resolution) {
  stairs_ = assets.model("stairs.model");
  corridor_ = assets.model("corridor.model");
  stairs_ = assets.model("stairs.model");
  stairs_down_ = assets.model("stairs_down.model");
  entities_.push_back(std::make_shared<Corridor>(glm::mat4(1.0f), corridor_));
}

Level::~Level() {}

void Level::camera_left(const bool left) { camera_.left = left; }

void Level::camera_right(const bool right) { camera_.right = right; }

void Level::camera_forward(const bool forward) { camera_.forward = forward; }

void Level::camera_backward(const bool backward) {
  camera_.backward = backward;
}

void Level::camera_zoom_in(const bool zoom_in) { camera_.zoom_in = zoom_in; }

void Level::camera_zoom_out(const bool zoom_out) {
  camera_.zoom_out = zoom_out;
}

void Level::update(const float dt) {
  time_ += dt;

  //TODO Move to own thread
  Entities new_entities;
  if (times_ < 6) {
    times_++;
    for (auto &e : entities_) {
      for (auto &d : e->exits) {
        if (!d.next) {
          auto next = create_entity(d.transform);

          if (std::none_of(entities_.begin(), entities_.end(),
                           [&](const Entity::SharedEntity &e0) {
                             return e0->intersects(*next);
                           }) &&
              std::none_of(new_entities.begin(), new_entities.end(),
                           [&](const Entity::SharedEntity &e0) {
                             return e0->intersects(*next);
                           })) {
            d.next = next;
            new_entities.push_back(d.next);

          }
        }
      }
    }
    entities_.insert(entities_.end(), new_entities.begin(), new_entities.end());
    time_ = 0.0f;
  }
  camera_.update(dt);
}

Level::Models Level::models() {
  out_models_.clear();
  for (auto &c : entities_) {
    out_models_.push_back(c->model());
  }
  return out_models_;
}

Level::Boxes Level::boxes() {
  Boxes boxes;
  for (auto &e : entities_) {
    auto b = e->box();
    boxes.push_back(mos::RenderBox(b.position, b.extent));
  }
  return boxes;
}

mos::Camera Level::camera() const { return camera_.camera(); }

Entity::SharedEntity Level::create_entity(const glm::mat4 &transform) {
  std::vector<std::shared_ptr<Entity>> entities;
  entities.push_back(std::make_shared<Corridor>(transform, corridor_));
  entities.push_back(std::make_shared<Stairs>(transform, stairs_));
  entities.push_back(std::make_shared<StairsDown>(transform, stairs_down_));
  entities.push_back(std::make_shared<Room>(transform, corridor_));

  auto s = glm::vec3(transform[3][0], transform[3][1], transform[3][2]);

  auto value = int(glm::abs(glm::simplex(s)) * entities.size());
  return entities[value];
}
