#include <s1e/ecs/component.h>

bool ecs::operator==(const ComponentInfo& a, const ComponentInfo& b) {
  return a.type_hash == b.type_hash;
}