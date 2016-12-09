#include <entities/elevator.hpp>
#include <glm/gtc/noise.hpp>
#include <algorithm.hpp>

Elevator::Elevator(mos::Assets &assets,
                   const glm::mat4 &transform, const int max_length) : time_(.0f), elevator_cart_(assets.model("elevator_cart.model")) {
model_.transform = transform;
elevator_cart_.position(glm::vec3(0.0f));

height_ = simplex_int(model_.position(), 1, max_length);

auto elevator = assets.model("elevator.model");

exits.push_back(
    Door(assets, transform *
        glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, height_))*
        glm::rotate(glm::mat4(1.0f), glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

for (int i = 0; i <= height_; i++) {
  auto m = elevator;
  m.transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, i));
  m.mesh.reset();
  model_.models.push_back(m);
}

box_ = mos::Box::create_from_model(model_);
box_.extent -= 0.001;

}
mos::Model Elevator::model() {
  auto m = model_;
  m.models.push_back(elevator_cart_);
  return m;
}
void Elevator::print(std::ostream &os) {
  os << "Elevator";
}
void Elevator::update(const float dt) {
  time_ += dt;
  auto p = elevator_cart_.position();
  p.z = (glm::sin(time_  * 3.0f / height_) + 1.0f) / 2.0f * height_;
  elevator_cart_.position(p);
}
