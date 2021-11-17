#pragma once

#include <map>
#include <vector>

namespace ecs {

class ComponentMap {
 private:
  std::map<size_t, size_t> storage;

 public:
  void tryAdd(size_t type_hash);

  size_t operator[](size_t index);
};

typedef std::vector<size_t> Archetype;

class ArchetypeList {
 private:
  std::vector<Archetype> storage;
};

}  // namespace ecs