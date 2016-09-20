#include <corridor.hpp>

Corridor::Corridor(const unsigned int length, const mos::Model &floor,
                   const mos::Model &wall)
    : wall_(wall), floor_(floor) {}
