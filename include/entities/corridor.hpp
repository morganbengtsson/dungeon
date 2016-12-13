#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <memory>
#include <mos/render/model.hpp>
#include <entities/entity.hpp>

class Corridor : public Entity {
public:
  Corridor(mos::Assets &assets,
           const glm::mat4 &transform,
           const int min_length = 5,
           const int max_length = 10);
  mos::Model model();
  void update(const float dt) override;
protected:
  void print(std::ostream &os) override;
private:
  int length_;
  mos::Model floor_;
  mos::Model model_;
};

#endif // CORRIDOR_HPP
