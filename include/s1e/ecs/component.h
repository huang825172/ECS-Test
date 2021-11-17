#pragma once

#include <stddef.h>

namespace ecs {

struct ComponentInfo {
  size_t type_hash;
  void* compRef;
};
bool operator==(const ComponentInfo& a, const ComponentInfo& b);

}  // namespace ecs