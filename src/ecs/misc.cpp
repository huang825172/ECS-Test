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

size_t ecs::ArchetypeList::tryAdd(ecs::Archetype arch) {
  for (auto i = storage.begin(); i != storage.end(); i++) {
    if (std::equal(i->begin(), i->end(), arch.begin())) {
      return i - storage.begin();
    }
  }
  storage.push_back(arch);
  return storage.size() - 1;
}