#include <level.hpp>
#include <mos/util.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/noise.hpp>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : time_(0.0f), camera(glm::vec3(0.0f, -10.0f, 10.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 100.0f)) {
  corridor_ = assets.model("corridor.model");
  stairs_ = assets.model("stairs.model");
  left_turn_ = assets.model("left_turn.model");
  right_turn_ = assets.model("right_turn.model");
  entities_.push_back(std::make_shared<Corridor>(glm::vec3(0.0f), glm::vec2(1.0f, 0.0f), corridor_));
}

Level::~Level() {}

void Level::update(const float dt, const glm::bvec4 &camera_movement) {
  time_ += dt;

  if (time_ > 0.5f) {
    for (auto & e : entities_) {
      if (!e->next) {
        //e->next = std::make_shared<Corridor>(e->end(), e->direction(), m_);
        //e->next = std::make_shared<Stairs>(e->end(), e->direction(), stairs_);
        auto n = glm::simplex(e->end() * 1000000.0f);
        if (n < -0.33f) {
         e->next = std::make_shared<Corridor>(e->end(), e->direction(), corridor_);
        }
        else if (n > -0.33 && n < 0.33) {
           e->next = std::make_shared<LeftTurn>(e->end(), e->direction(), left_turn_);
        }
        else {
          e->next = std::make_shared<RightTurn>(e->end(), e->direction(), right_turn_);
        }
        entities_.push_back(e->next);
      }
    }
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
