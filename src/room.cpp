#include <room.hpp>
#include <glm/gtc/noise.hpp>

Room::Room(const glm::mat4 &transform, const mos::Model &model) : model_(model){
    model_.transform = transform;
    size_.x = uint(glm::abs(glm::simplex(model_.position()) * 10.0f + 5.0f));
    size_.y = uint(glm::abs(glm::simplex(model_.position()) * 10.0f + 5.0f));
    model_.transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size_.x, size_.y, 1.0f));
}

mos::Model Room::model() {
    return model_;
}
