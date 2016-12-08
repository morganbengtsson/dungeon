#ifndef STAIRSDOWN_HPP
#define STAIRSDOWN_HPP

#include <entities/entity.hpp>
#include <mos/render/model.hpp>

class StairsDown : public Entity {
public:
  StairsDown(const glm::mat4 &transform,
         const mos::Model model,
         const unsigned int max_length = 5);
  mos::Model model();
  void update(const float dt) override;
protected:
  void print(std::ostream &os) override;
private:
  int length_;
  mos::Model model_;
};
#endif //STAIRSDOWN_HPP
