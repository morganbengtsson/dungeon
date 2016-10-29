#include <chrono>
#include <fstream>
#include <glm/gtx/io.hpp>
#include <iostream>
#include <memory>

#include <dungeon.hpp>
#include <mos/experimental/window.hpp>

static glm::uvec2 resolution(1980 / 1, 1080 / 1);

mos::Window window("Dungeons", resolution);
Dungeon dungeon(resolution);
bool zoom_in = false;
bool zoom_out = false;
float zoom_time = 0.0f;

int main(int argc, char **argv) {

  window.key_func = [&](int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
      window.close(true);
    }

    if (key == GLFW_KEY_F3 && action == GLFW_PRESS) {
    }

    if (key == GLFW_KEY_W) {
      if (action == GLFW_PRESS) {
        dungeon.camera_forward(true);
      } else if (action == GLFW_RELEASE) {
        dungeon.camera_forward(false);
      }
    }
    if (key == GLFW_KEY_S) {
      if (action == GLFW_PRESS) {
        dungeon.camera_backward(true);
      } else if (action == GLFW_RELEASE) {
        dungeon.camera_backward(false);
      }
    }
    if (key == GLFW_KEY_A) {
      if (action == GLFW_PRESS) {
        dungeon.camera_right(true);
      } else if (action == GLFW_RELEASE) {
        dungeon.camera_right(false);
      }
    }
    if (key == GLFW_KEY_D) {
      if (action == GLFW_PRESS) {
        dungeon.camera_left(true);
      } else if (action == GLFW_RELEASE) {
        dungeon.camera_left(false);
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

  window.scroll_func = [&](const glm::dvec2 offset) {
    if (offset.y > 0.0) {
      zoom_in = true;
    }
    if (offset.y < 0.0) {
      zoom_out = true;
    }
  };

  std::chrono::duration<float> frame_time =
      std::chrono::duration_cast<std::chrono::seconds>(std::chrono::seconds(0));

  while (!window.close()) {
    auto old_time = std::chrono::high_resolution_clock::now();

    if (zoom_in || zoom_out) {
      zoom_time += frame_time.count();
      if (zoom_time > 1.0f) {
        zoom_time = 0.0f;
        zoom_in = false;
        zoom_out = false;
      }
    }
    dungeon.camera_zoom_in(zoom_in);
    dungeon.camera_zoom_out(zoom_out);

    dungeon.update(frame_time.count(), window.framebuffer_size());
    window.poll_events();
    window.swap_buffers();

    frame_time = std::chrono::high_resolution_clock::now() - old_time;



  }

  return 0;
}
