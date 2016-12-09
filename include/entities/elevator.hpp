#ifndef DUNGEON_ELEVATOR_HPP
#define DUNGEON_ELEVATOR_HPP

#include <entities/entity.hpp>
#include <mos/render/model.hpp>
#include <mos/assets.hpp>

class Elevator : public Entity {
public:
  Elevator(mos::Assets & assets, const glm::mat4 &transform, const int max_height = 10);
  mos::Model model();
  void update(const float dt) override;
protected:
  void print(std::ostream &os) override;
private:
  float time_;
  int height_;
  mos::Model model_;
  mos::Model elevator_;
  mos::Model elevator_cart_;
};

#endif //DUNGEON_ELEVATOR_HPP
