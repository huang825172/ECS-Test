# ***************** #
# Test dependencies #
# ***************** #

# Test googletest
add_executable(test_deps_gtest gtest.cpp)
target_link_libraries(test_deps_gtest gtest_main)
gtest_discover_tests(test_deps_gtest)

# Test OpenGL
add_executable(test_deps_gl gl/gl.cpp)
target_link_libraries(test_deps_gl gtest_main glfw glad)
gtest_discover_tests(test_deps_gl)

# Test libuv
add_executable(test_deps_uv uv.cpp)
target_link_libraries(test_deps_uv gtest_main uv)
gtest_discover_tests(test_deps_uv)

# Test OpenAL
add_executable(test_deps_al al.cpp)
# target_link_libraries(test_al gtest_main alut)
# gtest_discover_tests(test_al)
target_link_libraries(test_deps_al alut)

# Test SPIR-V
add_custom_command(
        OUTPUT sv.spv
        COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/spirv/spirv.vert
                                 -o sv.spv
                                 --auto-map-locations
)
add_custom_command(
        OUTPUT sf.spv
        COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/spirv/spirv.frag
                                 -o sf.spv
                                 --auto-map-locations
)
add_custom_target(test_deps_spirv ALL DEPENDS sv.spv sf.spv)