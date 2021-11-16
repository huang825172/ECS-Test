#include <gtest/gtest.h>

TEST(HelloTest, basicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}