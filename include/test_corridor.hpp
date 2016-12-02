#ifndef TEST_CORRIDOR_HPP
#define TEST_CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entity.hpp>

class TestCorridor : public Entity {
public:  
  TestCorridor(const glm::mat4 &transform,
           const mos::Model &floor);
  mos::Model model();
private:
  int length_;
  mos::Model floor_;
  mos::Model model_;
};

#endif // TEST_CORRIDOR_HPP
