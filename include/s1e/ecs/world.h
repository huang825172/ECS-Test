#pragma once

#include "entity.h"
#include "misc.h"

#include <memory>
#include <map>

namespace ecs {

class World {
 public:
  std::unique_ptr<EntityBuilder> spawn();

 private:
  ComponentMap compMap;
  ArchetypeList archList;
};

}  // namespace ecs