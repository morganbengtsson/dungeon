#include <level.hpp>
#include <mos/util.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/noise.hpp>
#include <queue>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), camera(glm::vec3(0.0f, -10.0f, 10.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 100.0f)) {
  corridor_ = assets.model("corridor.model");
  stairs_ = assets.model("stairs.model");
  left_turn_ = assets.model("left_turn.model");
  right_turn_ = assets.model("right_turn.model");
  entities_.push_back(std::make_shared<Corridor>(glm::mat4(1.0f), corridor_));
}

Level::~Level() {}

void Level::update(const float dt, const glm::bvec4 &camera_movement) {
  time_ += dt;
  Entities new_entities;

  if (time_ > 0.5f) {
    for (auto & e : entities_) {
      for (auto &d : e->exits){
        if (!d.next) {
          d.next = std::make_shared<Corridor>(d.transform, corridor_);
          new_entities.push_back(d.next);
        }
      }
    }
    entities_.insert(entities_.end(), new_entities.begin(), new_entities.end());
    time_ = 0.0f;
  }

  auto p = camera.position();
  auto c = camera.center();
  const float speed = 10.0f;
  if (camera_movement[0]) {
    p.y += dt * speed;
    c.y += dt * speed;
  }
  if (camera_movement[1]){
    p.y -= dt * speed;
    c.y -= dt * speed;
  }
  if (camera_movement[2]){
    p.x -= dt * speed;
    c.x -= dt * speed;
  }
  if (camera_movement[3]){
    p.x += dt * speed;
    c.x += dt * speed;
  }
  camera.position(p);
  camera.center(c);
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
