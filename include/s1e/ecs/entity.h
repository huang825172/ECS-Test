#pragma once

#include "component.h"
#include "misc.h"

#include <algorithm>
#include <map>
#include <vector>

namespace ecs {

class EntityBuilder {
 private:
  ComponentMap& compMap;
  ArchetypeList& archMap;
  std::vector<ComponentInfo> compList;

 public:
  EntityBuilder(ComponentMap& componentMap, ArchetypeList& archetypeList)
      : compMap(componentMap), archMap(archetypeList) {}

  template <class T>
  EntityBuilder* insert(T component) {
    // Rigister component type in world
    compMap.tryAdd(typeid(T).hash_code());

    // Record components
    if (std::find(compList.begin(), compList.end(),
                  ComponentInfo{typeid(T).hash_code(), nullptr}) ==
        compList.end()) {
      compList.push_back(
          ComponentInfo{typeid(T).hash_code(), (void*)&component});
    }
    return this;
  }

  void build();
};

}  // namespace ecs