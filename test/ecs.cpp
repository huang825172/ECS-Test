#include <ecs/system.h>
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

class Animator{
    int id;
};


void basicSystem(Query<Transform, Rigidbody, Animator> query) { query.iter(); }

TEST(EngineTest, ECS) {
    createQuery(basicSystem);
}