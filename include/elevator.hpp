#ifndef DUNGEON_ELEVATOR_HPP
#define DUNGEON_ELEVATOR_HPP

#include <entity.hpp>
#include <mos/render/model.hpp>
#include <mos/assets.hpp>

class Elevator : public Entity {
  Elevator(mos::Assets & assets, const glm::mat4 &transform, const int max_length = 5);
  mos::Model model();
protected:
  void print(std::ostream &os) override;
private:
  int height_;
  mos::Model model_;
};

#endif //DUNGEON_ELEVATOR_HPP
