#ifndef STAIRS_HPP
#define STAIRS_HPP

#include <entity.hpp>
#include <mos/render/model.hpp>

class Stairs : public Entity {
public:
  Stairs(const glm::mat4 &transform,
         const mos::Model model,
         const unsigned int max_length = 10);
  mos::Model model();
private:
  unsigned int length_;
  mos::Model model_;
};

#endif // STAIRS_HPP
