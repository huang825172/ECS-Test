#pragma once

#include <map>
#include <vector>

namespace ecs {

struct Component {
  size_t type_hash;
};

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

 public:
  size_t tryAdd(Archetype arch);
  size_t identify(Archetype arch);
};

}  // namespace ecs