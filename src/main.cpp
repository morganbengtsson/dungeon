#include <chrono>
#include <fstream>
#include <glm/gtx/io.hpp>
#include <iostream>
#include <memory>

#include <dungeon.hpp>
#include <mos/experimental/window.hpp>

static glm::uvec2 resolution(1980 / 2, 1080 / 2);

mos::Window window("Dungeons", resolution);
Dungeon dungeon(resolution);
glm::bvec4 camera_movement(false);

int main(int argc, char **argv) {

  window.key_func = [&](int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
      window.close(true);
    }

    if (key == GLFW_KEY_F3 && action == GLFW_PRESS) {
    }

    if (key == GLFW_KEY_W) {
      if (action == GLFW_PRESS) {
        camera_movement[0] = true;
      } else if (action == GLFW_RELEASE) {
        camera_movement[0] = false;
      }
    }
    if (key == GLFW_KEY_S) {
      if (action == GLFW_PRESS) {
        camera_movement[1] = true;
      } else if (action == GLFW_RELEASE) {
        camera_movement[1] = false;
      }
    }
    if (key == GLFW_KEY_A) {
      if (action == GLFW_PRESS) {
        camera_movement[2] = true;
      } else if (action == GLFW_RELEASE) {
        camera_movement[2] = false;
      }
    }
    if (key == GLFW_KEY_D) {
      if (action == GLFW_PRESS) {
        camera_movement[3] = true;
      } else if (action == GLFW_RELEASE) {
        camera_movement[3] = false;
      }
    }

  };

  window.mouse_func = [&](const glm::dvec2 &position) {};

  window.click_func = [&](int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {
    }
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE) {
    }
  };

  std::chrono::duration<float> frame_time =
      std::chrono::duration_cast<std::chrono::seconds>(std::chrono::seconds(0));

  while (!window.close()) {
    auto old_time = std::chrono::high_resolution_clock::now();

    dungeon.update(frame_time.count(), window.framebuffer_size(), camera_movement);
    window.poll_events();
    window.swap_buffers();

    frame_time = std::chrono::high_resolution_clock::now() - old_time;
  }

  return 0;
}
