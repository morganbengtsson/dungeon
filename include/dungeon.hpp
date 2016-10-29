#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <glm/glm.hpp>
#include <mos/render/render_system.hpp>
#include <mos/render/text.hpp>
#include <mos/assets.hpp>
#include <level.hpp>

class Dungeon {
public:
  Dungeon(const glm::uvec2 & resolution);
  ~Dungeon();
  void update(const float dt,
              const glm::uvec2 &resolution);
  void camera_left(const bool left);
  void camera_right(const bool right);
  void camera_backward(const bool backward);
  void camera_forward(const bool forward);
private:
  mos::RenderSystem renderer_;
  mos::Assets assets_;
  glm::uvec2 resolution_;
  Level level_;
};

#endif // DUNGEON_HPP
