#include <algorithm>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/io.hpp>
#include <level.hpp>
#include <mos/util.hpp>
#include <queue>
#include <algorithm.hpp>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), camera_(resolution),
      floor_(assets.model("corridor.model")),
      stairs_(assets.model("stairs.model")),
      stairs_down_(assets.model("stairs_down.model")),
      entities_{std::make_shared<Room>(assets, glm::mat4(1.0f))},
      load_(std::async(std::launch::async, [&] {
        Entities new_entities;
        for (int i = 0; i < 10; i++) {
          for (auto &entity : entities_) {
            for (auto &door : entity->exits) {
              if (!door.next) {
                auto next = create_entity(assets, door.transform);

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
                } else {
                  door.open = false;
                }
              }
            }
          }
          load_mutex_.lock();
          entities_.insert(entities_.end(), new_entities.begin(), new_entities.end());
          load_mutex_.unlock();
          time_ = 0.0f;
        }
        std::cout << "Level generating done." << std::endl;
      })){

}

Level::~Level() {}

void Level::camera_zoom_in(const bool zoom_in) { camera_.zoom_in = zoom_in; }

void Level::camera_zoom_out(const bool zoom_out) {
  camera_.zoom_out = zoom_out;
}

void Level::update(const float dt) {
  time_ += dt;
  camera_.update(dt);
  for (auto & entity : entities_){
    entity->update(dt);
  }
}

Level::Models Level::models() {
  out_models_.clear();
  for (auto &c : entities_) {
    load_mutex_.lock();
    out_models_.push_back(c->model());
    for (auto &door : c->exits){
      out_models_.push_back(door.model());
    }
    load_mutex_.unlock();
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

Entity::SharedEntity Level::create_entity(mos::Assets &assets, const glm::mat4 &transform) {

  int min = 5;
  int max = 10;
  glm::uvec2 min_size(3,3);
  glm::uvec2 max_size(6,6);

  std::vector<std::shared_ptr<Entity>> entities;
  auto corridor = std::make_shared<Corridor>(assets, transform, min, max);
  auto stairs = std::make_shared<Stairs>(assets, transform, min, max);
  auto stairs_down = std::make_shared<StairsDown>(assets, transform, min, max);
  auto room = std::make_shared<Room>(assets, transform, min_size, max_size);
  auto elevator = std::make_shared<Elevator>(assets, transform, min, max);

  entities.push_back(corridor);
  entities.push_back(corridor);
  entities.push_back(stairs);
  entities.push_back(stairs_down);
  entities.push_back(elevator);
  entities.push_back(room);
  entities.push_back(room);
  entities.push_back(room);
  entities.push_back(room);

  auto seed = glm::vec3(transform[3][0], transform[3][1], transform[3][2]);

  auto value = simplex_range(seed, 0, entities.size());
  return entities[value];
}

void Level::camera_rotate_right(const bool rotate_right) {
  camera_.rotate_right = rotate_right;
}

void Level::camera_rotate_left(const bool rotate_left) {
  camera_.rotate_left = rotate_left;
}
