#include <s1mpleEngine.h>
#include <gtest/gtest.h>

TEST(helloEngineTest, BasicAssertions) {
    EXPECT_STREQ(s1mpleEngine::VERSION, "0.0.1");
}