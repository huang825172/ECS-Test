#include <s1e/ecs/entity.h>

#include <iostream>

void ecs::EntityBuilder::build() {
  // Sort component types to align with archetypes
  std::sort(compList.begin(), compList.end(),
            [this](ComponentInfo a, ComponentInfo b) {
              return compMap[a.type_hash] < compMap[b.type_hash];
            });

  // Register and get an ID of the archetype
  Archetype arch;
  for (auto i = compList.begin(); i != compList.end(); i++)
    arch.push_back(i->type_hash);
  auto archID = archList.identify(arch);
  std::cout << archID << std::endl;
}