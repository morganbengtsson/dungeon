#include <room.hpp>
#include <glm/gtc/noise.hpp>

Room::Room(const glm::mat4 &transform, const mos::Model &model){
  model_.transform = transform;
  size_.x = int(glm::abs(glm::simplex(model_.position()) * 5.0f)) + 2.0f;
  size_.y = int(glm::abs(glm::simplex(model_.position()) * 5.0f)) + 2.0f;


  size_ = {3,3};

  auto m = model;
  for (float x = 0; x < size_.x; x++){
    for(float y = 0; y  < size_.y; y++) {
      m.position(glm::vec3(x, y, 0.0f));
      std::cout << m.position();
      model_.models.push_back(m);
    }
  }
  //model_.transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size_.x, size_.y, 1.0f));

  box_ = mos::Box::create_from_model(model_);
  box_.extent -= 0.01;

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3(size_.x, 0.0f, 0.0f))));

  //uint right = uint((glm::abs(glm::simplex(model_.position())) * length_));



  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((size_.x / 2) + 0.5f, -0.5f, 0.0f))
          * glm::rotate(glm::mat4(1.0f), -glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));



  //uint left = uint((glm::abs(glm::simplex(model_.position())) * length_));

  exits.push_back(
      Door(transform *
          glm::translate(glm::mat4(1.0f), glm::vec3((size_.x / 2) + 0.5f, float(size_.y) - 0.5f, 0.0f)) *
          glm::rotate(glm::mat4(1.0f), glm::half_pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));

}

mos::Model Room::model() {
  return model_;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
  os << " size: " << room.size_;
  return os;
}