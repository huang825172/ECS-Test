#include <s1mpleEngine.h>
#include <gtest/gtest.h>

TEST(helloEngineTest, linkTest) {
    EXPECT_STREQ(s1mpleEngine::VERSION, "0.0.1");
}