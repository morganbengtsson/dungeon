#ifndef TEST_CORRIDOR_HPP
#define TEST_CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entities/entity.hpp>

class TestCorridor : public Entity {
public:  
  TestCorridor(mos::Assets &assets, const glm::mat4 &transform);
  mos::Model model();
private:
  int length_;
  mos::Model floor_;
  mos::Model model_;
};

#endif // TEST_CORRIDOR_HPP
