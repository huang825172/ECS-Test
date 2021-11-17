#include <s1e/ecs/misc.h>

void ecs::ComponentMap::tryAdd(size_t type_hash) {
  if (storage.find(type_hash) == storage.end()) {
    storage.insert(std::pair{type_hash, storage.size()});
  }
}

size_t ecs::ComponentMap::operator[](size_t index) {
  if (storage.count(index) == 1) return storage[index];
  return -1;
}