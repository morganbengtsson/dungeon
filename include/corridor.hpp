#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

#include <mos/render/model.hpp>

class Corridor {
public:
  Corridor(const unsigned int length,
           const mos::Model &floor,
           const mos::Model &wall);
private:
  mos::Model floor_;
  mos::Model wall_;
};

#endif // CORRIDOR_HPP
