#include <level.hpp>
#include <mos/util.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/noise.hpp>
#include <queue>
#include <algorithm>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), camera_(resolution) {
  corridor_ = assets.model("corridor.model");
  stairs_ = assets.model("stairs.model");
  left_turn_ = assets.model("left_turn.model");
  right_turn_ = assets.model("right_turn.model");
  entities_.push_back(std::make_shared<Corridor>(glm::mat4(1.0f), corridor_));
}

Level::~Level() {}

void Level::camera_left(const bool left) {
  camera_.left = left;
}

void Level::camera_right(const bool right) {
  camera_.right = right;
}

void Level::camera_forward(const bool forward) {
  camera_.forward = forward;
}

void Level::camera_backward(const bool backward) {
  camera_.backward = backward;
}

void Level::update(const float dt) {
  time_ += dt;
  Entities new_entities;

  if (time_ > 3.0f) {
    for (auto & e : entities_) {
      for (auto &d : e->exits){
        if (!d.next) {
          auto next = std::make_shared<Corridor>(d.transform, corridor_);

          if (std::none_of(entities_.begin(), entities_.end(), [&](const Entity::SharedEntity& e0){
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

mos::Camera Level::camera() const {
   return camera_.camera();
}
