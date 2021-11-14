#include <gtest/gtest.h>
#include <uv.h>

int uv() {
  uv_loop_t *loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
  uv_loop_init(loop);
  uv_run(loop, UV_RUN_DEFAULT);
  uv_loop_close(loop);
  free(loop);
  return 0;
}

TEST(UVTest, BasicAssertions) { ASSERT_EQ(uv(), 0); }