#include <dungeon.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <mos/render/camera.hpp>
#include <mos/render/models_batch.hpp>

Dungeon::Dungeon(const glm::uvec2 &resolution)
    : renderer_(), assets_(), resolution_(resolution), level_(assets_),
      camera_(glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(0.0f),
              glm::perspective(45.0f,
                               ((float)resolution_.x / (float)resolution_.y),
                               0.1f, 100.0f)) {
  std::cout << "Dungeons started." << std::endl;
}

Dungeon::~Dungeon() {}

void Dungeon::update(const float dt, const glm::uvec2 &resolution,
                     const glm::bvec4 &camera_movement) {
  level_.update(dt);

  const auto light =
      mos::Light(glm::vec3(0.0f, 100.0f, 100.0f), glm::vec3(2000.0f),
                 glm::vec3(0.0f), glm::vec3(0.3f));


  auto p = camera_.position();
  auto c = camera_.center();
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
  camera_.position(p);
  camera_.center(c);



  const auto models = level_.models();

  const mos::ModelsBatch main(models.begin(), models.end(), camera_.view,
                        camera_.projection, resolution_, light);

  renderer_.batches({main}, {}, {}, glm::vec4(0.0f));
}
