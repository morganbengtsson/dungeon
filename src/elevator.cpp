#include <elevator.hpp>
#include <glm/gtc/noise.hpp>
Elevator::Elevator(mos::Assets &assets,
                   const glm::mat4 &transform, const int max_length) {
model_.transform = transform;
height_ = uint((glm::abs(glm::simplex(model_.position()))) * max_length + 1.0f);

auto elevator = assets.model("elevator.model");
auto elevator_car = assets.model("elevator_car.model");

exits.push_back(
    Door(transform *
        glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, height_))));

for (int i = 0; i < height_; i++) {
  elevator.transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, i));
  model_.models.push_back(elevator);
}

box_ = mos::Box::create_from_model(model_);
box_.extent -= 0.001;

}
mos::Model Elevator::model() {
  return mos::Model();
}
void Elevator::print(std::ostream &os) {
  os << "Elevator";
}
