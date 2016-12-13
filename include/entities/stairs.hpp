#ifndef STAIRS_HPP
#define STAIRS_HPP

#include <entities/entity.hpp>
#include <mos/render/model.hpp>

class Stairs : public Entity {
public:
  Stairs(mos::Assets &assets,
         const glm::mat4 &transform,
         const int min_length = 5,
         const int max_length = 10);
  mos::Model model();
  void update(const float dt) override;
protected:
  void print(std::ostream &os) override;
private:
  int length_;
  mos::Model model_;
};

#endif // STAIRS_HPP
