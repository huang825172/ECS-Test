#include <s1e/ecs/entity.h>

#include <iostream>

void ecs::EntityBuilder::build() {
  // Sort component types to align with archetypes
  std::sort(compList.begin(), compList.end(),
            [this](ComponentInfo a, ComponentInfo b) {
              return compMap[a.type_hash] < compMap[b.type_hash];
            });
}