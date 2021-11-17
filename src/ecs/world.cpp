#include <s1e/ecs/world.h>

#include <iostream>

std::unique_ptr<ecs::EntityBuilder> ecs::World::spawn() {
  auto entityBuilder = std::make_unique<ecs::EntityBuilder>(compMap, archList);
  return entityBuilder;
}