#include <algorithm>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/io.hpp>
#include <level.hpp>
#include <mos/util.hpp>
#include <queue>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), camera_(resolution),
      floor_(assets.model("room_floor.model")),
      stairs_(assets.model("stairs.model")),
      stairs_down_(assets.model("stairs_down.model")),
      entities_{std::make_shared<Corridor>(glm::mat4(1.0f), floor_)},
      load_(std::async(std::launch::async, [&] {
        Entities new_entities;
        for (int i = 0; i < 4; i++) {
          for (auto &entity : entities_) {
            for (auto &door : entity->exits) {
              if (!door.next) {
                auto next = create_entity(door.transform);

                if (std::none_of(entities_.begin(), entities_.end(),
                                 [&](const Entity::SharedEntity &e0) {
                                   return e0->intersects(*next);
                                 }) &&
                    std::none_of(new_entities.begin(), new_entities.end(),
                                 [&](const Entity::SharedEntity &e0) {
                                   return e0->intersects(*next);
                                 })) {
                  door.next = next;
                  new_entities.push_back(door.next);
                }
              }
            }
          }
          entities_.insert(entities_.end(), new_entities.begin(), new_entities.end());
          time_ = 0.0f;
          std::cout << "Level generating done." << std::endl;
        }
      })) {}

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
  entities.push_back(std::make_shared<Corridor>(transform, floor_));
  entities.push_back(std::make_shared<Stairs>(transform, stairs_));
  entities.push_back(std::make_shared<StairsDown>(transform, stairs_down_));
  entities.push_back(std::make_shared<Room>(transform));
  entities.push_back(std::make_shared<TestCorridor>(transform, floor_));

  auto seed = glm::vec3(transform[3][0], transform[3][1], transform[3][2]);

  auto value = int(glm::abs(glm::simplex(seed)) * entities.size());
  return entities[3];
}
