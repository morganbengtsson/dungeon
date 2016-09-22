#include <glm/gtx/io.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <mos/render/camera.hpp>
#include <mos/render/models_batch.hpp>
#include <dungeon.hpp>

Dungeon::Dungeon(const glm::uvec2 &resolution)
    : renderer_(), assets_(), resolution_(resolution),
      level_(assets_) {
  std::cout << "Dungeons started." << std::endl;
}

Dungeon::~Dungeon() {}

void Dungeon::update(const float dt, const glm::uvec2 &resolution) {
  level_.update(dt);

  const auto light = mos::Light(glm::vec3(0.0f, 10.0f, 10.0f),
                                glm::vec3(200.0f), glm::vec3(0.0f), glm::vec3(0.3f));
  const auto camera = mos::Camera(
      glm::vec3(40.0f), glm::vec3(0.0f),
      glm::perspective(45.0f, ((float)resolution_.x / (float)resolution_.y),
                       0.1f, 100.0f));

  const auto models = level_.models();

  mos::ModelsBatch main(models.begin(), models.end(), camera.view,
                        camera.projection, resolution_, light);


  renderer_.batches({main}, {}, {}, glm::vec4(0.0f));

}
