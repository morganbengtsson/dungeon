#include <dungeon.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <mos/render/models_batch.hpp>

Dungeon::Dungeon(const glm::uvec2 &resolution)
    : renderer_(), assets_(), resolution_(resolution), level_(assets_, resolution)
       {
  std::cout << "Dungeons started." << std::endl;
}

Dungeon::~Dungeon() {}

void Dungeon::update(const float dt, const glm::uvec2 &resolution,
                     const glm::bvec4 &camera_movement) {
  level_.update(dt, camera_movement);

  const auto light =
      mos::Light(glm::vec3(0.0f, 100.0f, 100.0f), glm::vec3(0.0f),
                 glm::vec3(0.0f), glm::vec3(1.0f));

  const auto models = level_.models();

  const mos::ModelsBatch main(models.begin(), models.end(), level_.camera.view,
                        level_.camera.projection, resolution_, light);

  renderer_.batches({main}, {}, {}, glm::vec4(0.0f));
}
