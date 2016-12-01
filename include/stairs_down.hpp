#ifndef STAIRSDOWN_HPP
#define STAIRSDOWN_HPP

#include <entity.hpp>
#include <mos/render/model.hpp>

class StairsDown : public Entity {
public:
  StairsDown(const glm::mat4 &transform,
         const mos::Model model,
         const unsigned int max_length = 10);
  mos::Model model();
private:
  unsigned int length_;
  mos::Model model_;
};
#endif //STAIRSDOWN_HPP
