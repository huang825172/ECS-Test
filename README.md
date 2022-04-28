# ECS-Test

Try to implement simple ECS concepts.

```cpp
// Example:

#include <gtest/gtest.h>
#include <s1e/s1mpleEngine.h>

struct Transform {
  int x;
  int y;
  int z;
};

struct Rigidbody {
  int vel;
};

void basicSystem(ecs::Query<Transform, Rigidbody> query) { query.iter(); }

TEST(EngineTest, ECS) {
  ecs::World world;
  auto e = world.spawn();
  e->insert(Transform{1, 2, 3});
  e->insert(Rigidbody{1});
  e->build();
  world.spawn()->insert(Transform{1, 2, 3})->build();
  createQuery(basicSystem);
}
```

Dependencies added:
+ glfw
+ glad
+ libuv
+ openal-soft
+ freealut
+ google test
+ vulkan-sdk
