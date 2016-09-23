#include <level.hpp>
#include <mos/util.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/io.hpp>

Level::Level(mos::Assets &assets, const glm::vec2 &resolution)
    : camera(glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution.x / (float)resolution.y),
                               0.1f, 100.0f)) {
  m_ = assets.model("floor.model");
  corridors_.push_back(Corridor(glm::vec3(0.0f), m_));
}

Level::~Level() {}

void Level::update(const float dt, const glm::bvec4 &camera_movement) {

  auto p = camera.position();
  auto c = camera.center();
  const float speed = 10.0f;
  if (camera_movement[0]) {
    p.y -= dt * speed;
    c.y -= dt * speed;
  }
  if (camera_movement[1]){
    p.y += dt * speed;
    c.y += dt * speed;
  }
  if (camera_movement[2]){
    p.x += dt * speed;
    c.x += dt * speed;
  }
  if (camera_movement[3]){
    p.x -= dt * speed;
    c.x -= dt * speed;
  }
  camera.position(p);
  camera.center(c);
}

Level::Models Level::models() {
  out_models_.clear();
  for (auto &c : corridors_) {
    out_models_.push_back(c.model());
  }
  return out_models_;
}
