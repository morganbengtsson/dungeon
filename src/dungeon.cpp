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

void Dungeon::update(const float dt, const glm::uvec2 &resolution) {
  level_.update(dt);

  const auto light =
      mos::Light(glm::vec3(0.0f, 100.0f, 100.0f), glm::vec3(10000.0f),
                 glm::vec3(0.0f), glm::vec3(1.0f));

  const auto models = level_.models();
  const auto fog = mos::FogLinear(glm::vec3(0.0f), 50.0f, 80.0f);
  const mos::ModelsBatch main(models.begin(), models.end(), level_.camera().view,
                        level_.camera().projection, resolution_, light, mos::FogExp(), fog);


  const auto boxes = level_.boxes();
  const mos::BoxesBatch boxes_batch(boxes.begin(), boxes.end(), level_.camera().view,
                        level_.camera().projection);
  renderer_.batches({main}, {}, {}, glm::vec4(0.0f));
}

void Dungeon::camera_left(const bool left) {
  level_.camera_left(left);
}

void Dungeon::camera_right(const bool right) {
  level_.camera_right(right);
}

void Dungeon::camera_backward(const bool backward) {
  level_.camera_backward(backward);
}

void Dungeon::camera_forward(const bool forward) {
  level_.camera_forward(forward);
}

void Dungeon::camera_zoom_in(const bool zoom_in) {
  level_.camera_zoom_in(zoom_in);
}

void Dungeon::camera_zoom_out(const bool zoom_out) {
  level_.camera_zoom_out(zoom_out);
}
