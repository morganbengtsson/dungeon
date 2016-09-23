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
  for (int i = 0; i < 500; i += 10) {
    rooms_.push_back(Room(glm::vec3(i, 0.0f, 0.0f), m_, m_, m_));
  }
}

Level::~Level() {}

void Level::update(const float dt, const glm::bvec4 &camera_movement) {

  std::cout << glm::round(camera.center() / 10.0f) * 10.0f << std::endl;
  rooms_.clear();
  for (int x = -50; x < 50; x += 10){
    for (int y = -50; y < 50; y += 10){
      rooms_.push_back(Room(glm::vec3(x, y, 0.0f) + glm::round(camera.center() / 10.0f) * 10.0f, m_, m_, m_));
    }
  }

  for (auto &room : rooms_) {
    room.update(dt);
  }

  auto p = camera.position();
  auto c = camera.center();
  const float speed = 10.0f;
  if (camera_movement[0]){
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
  for (auto &r : rooms_) {
    out_models_.push_back(r.model());
  }
  return out_models_;
}
