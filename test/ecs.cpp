#include <s1e/s1mpleEngine.h>
#include <gtest/gtest.h>

struct Transform
{
    int x;
    int y;
    int z;
};

struct Rigidbody
{
    int vel;
};

void basicSystem(ecs::Query<Transform, Rigidbody> query) { query.iter(); }

TEST(EngineTest, ECS) {
    ecs::World world;
    world.spawn()->insert(Transform{1,2,3})->insert(Rigidbody{1})->build();
    createQuery(basicSystem);
}
